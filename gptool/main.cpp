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
#include "user/GPAPI.h"
#include <assert.h>
#include <string.h>
#include <fstream>
#include <sstream>
#define INFO(...)#__VA_ARGS__
void dump_usage()
{
    printf("Usage:\n");
    printf(INFO(
                gptool.out create func.xml input=<TrBmp>, output=<TrBmp> fit=<NULL> outputfunc=<outf.xml>
                gptool.out create func.xml model=<model.xml>, fit=<fitf.xml> outputfunc=<outf.xml>

                gptool.out query func.xml outputfunc.xml
                gptool.out run outputfunc.xml input=<1.txt,2.jpg> output=<3.jpg>));
}
void gp_run(int argc, char** argv)
{
    printf("In %s, %d\n", __func__, __LINE__);
    assert(argc>=4);
    std::ifstream metadata(argv[2]);
    assert(!metadata.fail());
    std::ifstream funcfile(argv[3]);
    assert(!funcfile.fail());
    auto base = GP_Producer_Create(metadata, NULL, 0);
    assert(NULL!=base);
    auto adf = GP_Function_Create_ByStream(base, funcfile);
    assert(NULL!=adf);
    GPTYPES outputtype;
    GPTYPES inputtype;
    GP_Function_Get_Inputs(adf, &inputtype);
    GP_Function_Get_Outputs(adf, &outputtype);
    printf("Outputs:\n");
    int cur = 4;
    auto outputcur = 4;
    for (auto t:outputtype)
    {
        assert(cur <= argc);
        printf("%s: %s\n", t->name().c_str(), argv[cur++]);
    }
    printf("Inputs:\n");
    auto inputcur = cur;
    for (auto t:inputtype)
    {
        assert(cur < argc);
        printf("%s: %s\n", t->name().c_str(), argv[cur++]);
    }
    GPContents inputcontents;
    for (int i=0; i<inputtype.size(); i++)
    {
        std::ifstream inputs(argv[inputcur+i]);
        assert(!inputs.fail());
        auto t = inputtype[i];
        inputcontents.push(t->vLoad(inputs), t);
    }
    GPContents* outputcontents = GP_Function_Run(adf, &inputcontents);
    inputcontents.clear();
    assert(outputcontents->size() == outputtype.size());
    for (int i=0; i<outputtype.size(); ++i)
    {
        assert(outputcur < argc);
        std::ofstream outputs(argv[outputcur+i]);
        assert(!outputs.fail());
        auto t = outputtype[i];
        t->vSave(outputcontents->get(i), outputs);
    }
    outputcontents->clear();
    delete outputcontents;
    GP_Function_Destroy(adf);
    GP_Producer_Destroy(base);
}
void gp_create(int argc, char** argv)
{
    printf("In %s, %d\n", __func__, __LINE__);
}
void gp_opt(int argc, char** argv)
{
    printf("In %s, %d\n", __func__, __LINE__);
    assert(argc>=6);
    std::ifstream metadata(argv[2]);
    assert(!metadata.fail());
    auto base = GP_Producer_Create(metadata, NULL, 0);
    std::ifstream model_(argv[3]);
    assert(!model_.fail());
    auto model = GP_Function_Create_ByStream(base, model_);
    std::ifstream fitf_(argv[4]);
    assert(!fitf_.fail());
    auto fitf = GP_Function_Create_ByStream(base, fitf_);
    /*TODO Add input*/
    GPContents inputs;

    auto fitfunction = [&](IGPAutoDefFunction* target) {
        auto output = GP_Function_Run(target, &inputs);
        auto fit = GP_Function_Run(fitf, output);
        assert(1 == fit->size());
        double fitness;
        auto c = fit->contents[0];
        std::ostringstream foutput_;
        (c.type)->vSave(c.content, foutput_);
        std::istringstream input_(foutput_.str());
        input_ >> fitness;
        GPContents::destroy(output);
        GPContents::destroy(fit);
        return fitness;
    };
    GP_Function_Optimize(model, fitfunction, 1, NULL);
    std::ostringstream outputfuncfile(argv[5]);
    GP_Function_Save(model, outputfuncfile);
    inputs.clear();
    GP_Function_Destroy(model);
    GP_Function_Destroy(fitf);
    GP_Producer_Destroy(base);
}
int main(int argc, char** argv)
{
    //dump_usage();
    printf("argc = %d\n", argc);
    for (int i=0; i<argc; ++i)
    {
        printf("argc_%d: %s\n", i,argv[i]);
    }
    assert(argc>=2);
    if (strcmp(argv[1],"run") == 0)
    {
        gp_run(argc, argv);
    }
    else if (strcmp(argv[1],"create") == 0)
    {
        gp_create(argc, argv);
    }
    return 1;
}