/******************************************************************
   Copyright 2017, Jiang Xiao-tang

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
#ifndef COMPILER_GPBASICADAPTOR_H
#define COMPILER_GPBASICADAPTOR_H
#include "compiler/IGPCompilerInterface.h"
#include "compiler/GPProducerUtils.h"
#include "core/GPFunctionTree.h"


class GPBasicAdaptor : public IGPAdaptor
{
public:
    GPBasicAdaptor(const GPFunctionDataBase* database);
    virtual ~ GPBasicAdaptor();
    
    //If the origin has no ADF, Do nothing and return false
    virtual bool vExpand(GP__PointGroup* origin) const override;
    
    //Return n_paramters if the paramters is NULL
    virtual int vMapStructure(GP__PointGroup* target, const double* paramters, int n_paramters) const override;
protected:
    GP__Point* _expand(const GP__ADF* adf) const;
    GPFunctionTreePoint* _revert(const GP__Point* src) const;

    GPProducerUtils mUtils;
    const GPFunctionDataBase* mDataBase;
};

#endif
