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
#ifndef CORE_GPSTREAMUTILS_H
#define CORE_GPSTREAMUTILS_H
#include "user/GPStream.h"
#include "utils/GPBlock.h"
class GPStreamUtils
{
public:
    static GPPtr<GPBlock> read(GPStream* input, bool merge=false);
    static void write(GPWStream* output, GPPtr<GPBlock> content);
};
#endif
