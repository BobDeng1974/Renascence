/******************************************************************
 Copyright 2016, Jiang Xiao-tang
 
 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at
 
 http://www.apache.org/licenses/LICENSE-2.0
 
 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
 ******************************************************************/
#include <string.h>
#include <vector>
#include <sstream>
#include "head.h"
#include "core/GPPieceFactory.h"
#include "core/GPStreamFactory.h"
#include "platform/GPSystem.h"

class GPPieceInMemory : public GPPieces
{
public:
    GPPieceInMemory(const std::vector<unsigned int>& keydimesions):mKeyDimesions(keydimesions)
    {
        mMaxSize = 1;
        if (keydimesions.empty())
        {
            pKeySize[0] = 1;
            nKeyNumber = 1;
        }
        else
        {
            nKeyNumber = (unsigned int)keydimesions.size();
            for (int i=0; i<keydimesions.size(); ++i)
            {
                GPASSERT(keydimesions[i]>0);
                mMaxSize *= keydimesions[i];
                pKeySize[i] = keydimesions[i];
            }
        }
        mPieces = new GPContents*[mMaxSize];
        ::memset(mPieces, 0, mMaxSize*sizeof(GPContents*));
    }
    virtual ~GPPieceInMemory()
    {
        //FUNC_PRINT_ALL(this, p);
        for (size_t i=0; i<mMaxSize; ++i)
        {
            if (NULL!=mPieces[i])
            {
                mPieces[i]->decRef();
            }
        }
        delete [] mPieces;
    }
    
    virtual GPContents* vLoad(unsigned int* pKey, unsigned int keynum)
    {
        auto sum = _computePos(pKey, keynum);
        GPContents* res = mPieces[sum];
        GPASSERT(NULL!=res);
        res->addRef();
        return res;
    }
    
    virtual void vSave(unsigned int* pKey, unsigned int keynum, GPContents* c)
    {
        auto sum = _computePos(pKey, keynum);
        c->addRef();
        if (NULL != mPieces[sum])
        {
            mPieces[sum]->decRef();
        }
        mPieces[sum] = c;
    }

private:
    size_t _computePos(unsigned int* key, int keynum)
    {
        GPASSERT(keynum <= mKeyDimesions.size() || (keynum==1 && mKeyDimesions.size()==0));
        size_t sum = 0;
        for (int i=0; i<keynum; ++i)
        {
            sum = sum*mKeyDimesions[i] + key[i];
        }
        GPASSERT(sum < mMaxSize);
        return sum;
    }
    GPContents** mPieces;
    std::vector<unsigned int> mKeyDimesions;
    size_t mMaxSize;
};

class GPLocalFilePiece : public GPPieces
{
public:
    GPLocalFilePiece(const char* path, std::vector<const IStatusType*> types)
    {
        pTypes = types;
        nKeyNumber = 0;
        mPath = path;
    }
    virtual ~GPLocalFilePiece()
    {
    }
    
    std::string generatePath(unsigned int* pKey, unsigned int keynum, const std::string& type)
    {
        return GPPieceFactory::getFilePath(pKey, keynum, type, mPath);
    }
    
    virtual GPContents* vLoad(unsigned int* pKey, unsigned int keynum)
    {
        GPASSERT(!pTypes.empty());
        GPContents* c = new GPContents;
        GPASSERT(keynum>0);
        for (int i=0; i<pTypes.size(); ++i)
        {
            std::string path = generatePath(pKey, keynum, pTypes[i]->name());
            GPPtr<GPStream> readStream = GPStreamFactory::NewStream(path.c_str());
            GPASSERT(NULL!=readStream.get());
            c->push(pTypes[i]->vLoad(readStream.get()), pTypes[i]);
        }
        return c;
    }
    
    virtual void vSave(unsigned int* pKey, unsigned int keynum, GPContents* c)
    {
        GPASSERT(NULL!=c);
        GPASSERT(keynum>0);
        for (int i=0; i<c->size(); ++i)
        {
            auto type = c->getType(i);
            std::string path = generatePath(pKey, keynum, type->name());
            GPPtr<GPWStream> writeStream = GPStreamFactory::NewWStream(path.c_str());
            type->vSave(c->get(i), writeStream.get());
        }
    }
private:
    std::string mPath;
};



static GPPieces* _createMemoryPieces(const std::vector<unsigned int>& keydimesions)
{
    GPASSERT(keydimesions.size() < 10);
    return new GPPieceInMemory(keydimesions);
}

GPPieces* GPPieceFactory::createMemoryPiece(const std::vector<unsigned int> &keydimesions)
{
    return _createMemoryPieces(keydimesions);
}

GPPieces* GPPieceFactory::createLocalFilePiece(const std::vector<const IStatusType*>& types, const char* srcPath, size_t maxMemoryCacheSize/*MB*/)
{
    return new GPLocalFilePiece(srcPath, types);
}

std::string GPPieceFactory::getFilePath(unsigned int* pKey, unsigned int keynum, const std::string& type, const std::string& basicPath)
{
    std::ostringstream output;
    output << basicPath << "/"<<type;
    for (int i=0; i<keynum; ++i)
    {
        output << "_" << pKey[i];
    }
    return output.str();
}
