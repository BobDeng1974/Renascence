/******************************************************************
   Copyright 2015, Jiang Xiao-tang

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
#ifndef FRONTEND_GPFRONTENDPRODUCER_H
#define FRONTEND_GPFRONTENDPRODUCER_H
#include "utils/RefCount.h"
#include "user/IStatusType.h"
#include "core/GPFunctionTree.h"
#include <vector>
class GPFrontEndProducer:public RefCount
{
public:
    virtual GPFunctionTree* vCreateOneFunction(const std::vector<const IStatusType*>& outputType, const std::vector<const IStatusType*>& inputType) const = 0;
    virtual std::vector<GPFunctionTree*> vCreateAllFunction(const std::vector<const IStatusType*>& outputType, const std::vector<const IStatusType*>& inputType) const = 0;
    virtual GPFunctionTree* vCreateFromFormula(const std::string& formula) const = 0;
    
    GPFrontEndProducer(){}
    virtual ~GPFrontEndProducer(){}
};
#endif