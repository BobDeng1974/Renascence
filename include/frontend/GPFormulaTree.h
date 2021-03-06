/******************************************************************
 Copyright 2014, Jiang Xiao-tang
 
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
#ifndef MATH_GPFORMULATREE_H
#define MATH_GPFORMULATREE_H
#include "lowlevelAPI/GPRefCount.h"
#include "math/GPAbstractPoint.h"
#include <string>
#include <ostream>
#include <map>
class GPFormulaTreePoint:public GPAbstractPoint
{
public:
    typedef enum
    {
        NUM,
        OPERATOR,
        ADF,
        PARALLEL,
        OUTPUT
    }TYPE;
    GPFormulaTreePoint(TYPE t, const std::string& name, GPFormulaTreePoint* father = NULL);
    virtual ~GPFormulaTreePoint();
    friend class GPFormulaTree;
    inline const std::string& name() const {return mName;}
    inline TYPE type() const {return mT;}
    TYPE getChildType(size_t i) const;
    void render(std::ostream& output) const;
    void renderAsFormula(std::ostream& output) const;
    const GPFormulaTreePoint* father() const {return mFather;}
    void valid() const;
    static GPFormulaTreePoint* create(const std::vector<std::string>& words);
    
    void replaceName(const std::string& newName);
    void replaceNameAll(const std::string& oldName, const std::string& newName);
    void replaceNameAll(const std::map<std::string, std::string>& replaceMap);
    
    GPFormulaTreePoint* deepCopy() const;
    
    void replaceNameByPoint(const std::string& name, GPFormulaTreePoint* point);
    
private:
    GPFormulaTreePoint* _deepCopy(GPFormulaTreePoint* father) const;
    
    GPFormulaTreePoint* _ParallelExpand(const std::vector<std::string>& words, int sta, int fin);
    void _createSubPoints(const std::vector<std::string>& words, int sta, int fin);

    void _createSubPoint(const std::vector<std::string>& words, int sta, int fin);
    void _expand();
    static GPFormulaTreePoint* _create(const std::vector<std::string>& words, int sta, int fin, GPFormulaTreePoint* father);
    TYPE mT;
    std::string mName;

    GPFormulaTreePoint* mFather;
};
class GPFormulaTree:public GPRefCount
{
public:
    GPFormulaTree();
    virtual ~GPFormulaTree();
    void setFormula(const std::string& formula);
    inline GPFormulaTreePoint* root() {return mRoot;}
    std::string dump() const;
private:
    GPFormulaTreePoint* mRoot;
};
#endif
