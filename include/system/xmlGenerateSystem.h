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
#ifndef XML_GENERATE_SYSTEM_H
#define XML_GENERATE_SYSTEM_H

#include "system/GenerateSystem.h"
#include "system/xmlDataBase.h"

class xmlGenerateSystem:public GenerateSystem
{
    public:
        xmlGenerateSystem(const char* xmlFile, bool print= false);
        virtual ~xmlGenerateSystem();
        std::string xmlPrint(GeneticProgram* gp);
        GeneticProgram* xmlLoad(const char* xmlFile);
    private:
        xmlDataBase mData;
        std::vector<void*> mHandle;
};



#endif