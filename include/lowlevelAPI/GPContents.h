/******************************************************************
   Copyright 2013, Jiang Xiao-tang

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
#ifndef USER_PACKAGE_H
#define USER_PACKAGE_H
#include <vector>
#include "IStatusType.h"
#include "GPRefCount.h"

class GPContents : public GPRefCount
{
public:
    class GP_Unit :public GPRefCount
    {
    public:
        GP_Unit(void* content, const IStatusType* type, bool own=true)
        {
            mContent = content;
            mType = type;
            mOwn = own;
        }
        ~GP_Unit()
        {
            if (mOwn)
            {
                mType->vFree(mContent);
            }
        }
        
        void* content() const {return mContent;}
        const IStatusType* type() const {return mType;}
    private:
        void* mContent;
        const IStatusType* mType;
        bool mOwn;
    };

    GPContents()
    {
    }
    ~GPContents()
    {
    }
    void push(void* content, const IStatusType* type, bool own=true)
    {
        mContents.push_back(new GP_Unit(content, type, own));
    }
    inline void* get(size_t i) const
    {
        return mContents[i]->content();
    }
    inline const IStatusType* getType(size_t i) const
    {
        return mContents[i]->type();
    }
    inline size_t size() const
    {
        return mContents.size();
    }
    inline GPPtr<GP_Unit> getContent(size_t i) const
    {
        return mContents[i];
    }
    void pushContent(GPPtr<GP_Unit> unit)
    {
        mContents.push_back(unit);
    }
    
    void merge(const GPContents& other)
    {
        for (auto c : other.mContents)
        {
            mContents.push_back(c);
        }
    }

private:
    std::vector<GPPtr<GP_Unit>> mContents;
};

typedef GPContents*(*computeFunction)(GPContents* inputs);



#endif