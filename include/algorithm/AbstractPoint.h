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
#ifndef ALGORITHM_ABSTRACTPOINT_H
#define ALGORITHM_ABSTRACTPOINT_H

#include <vector>

class AbstractPoint
{
    public:
        /*This class will alloc a new AbstractPoint and copy the contents from src*/
        class IPointCopy
        {
            public:
                virtual AbstractPoint* copy(AbstractPoint* src) = 0;
        };
        AbstractPoint(){}
        /*Use for different types of tree to transform*/
        static AbstractPoint* deepCopy(AbstractPoint* src, IPointCopy* copy);
        virtual ~AbstractPoint();
    protected:
        void addPoint(AbstractPoint* p);
        std::vector<AbstractPoint*> mChildren;
};


#endif
