#include "test/GPTest.h"
#include <assert.h>
#include <fstream>
#include <iostream>
#include <string>
#include <fstream>
#include <iostream>
#include "core/GPFunctionDataBase.h"
#include "core/GPFactory.h"
#include "core/GPStreamFactory.h"
#include "core/GPProducer.h"
#include "core/GPStreamFactory.h"
using namespace std;
class GPStreamADFTest:public GPTest
{
    public:
        virtual void run();
        GPStreamADFTest(){}
        virtual ~GPStreamADFTest(){}
};
void GPStreamADFTest::run()
{
    GPPtr<GPFunctionDataBase> base = GPFactory::createDataBase("func.xml", NULL);
    {
        GPPtr<GPProducer> gen = GPFactory::createProducer(base.get(), GPFactory::STREAM);
        xmlReader r;
        auto n = r.loadFile("stream_test.xml");
        GPPtr<IGPAutoDefFunction> gp = gen->createFunction(n);
        GPPtr<GPTreeNode> node = gp->vSave();
        GPPtr<GPWStream> outp = GPStreamFactory::NewWStream("output/GPStreamTest.xml");
        xmlReader::dumpNodes(node.get(), outp.get());
        auto bmptype = base->vQueryType("TrBmp");
        outp->vFlush();
        {
            GPContents contents;
            GPPtr<GPStream> inputjpeg = GPStreamFactory::NewStream("input.jpg", GPStreamFactory::FILE);
            auto pic = bmptype->vLoad(inputjpeg.get());
            contents.push(pic, bmptype);
            inputjpeg = GPStreamFactory::NewStream("output.jpg", GPStreamFactory::FILE);
            pic = bmptype->vLoad(inputjpeg.get());
            contents.push(pic, bmptype);
            inputjpeg = GPStreamFactory::NewStream("input_sharp.jpg", GPStreamFactory::FILE);
            pic = bmptype->vLoad(inputjpeg.get());
            contents.push(pic, bmptype);
            inputjpeg = GPStreamFactory::NewStream("output.jpg", GPStreamFactory::FILE);
            pic = bmptype->vLoad(inputjpeg.get());
            contents.push(pic, bmptype);
            
            GPContents* out = gp->vRun(&contents);
            GPASSERT(NULL!=out);
            GPASSERT(out->size() == 1);
            GPPtr<GPWStream> outputjpeg = GPStreamFactory::NewWStream("output/GPStreamTest.jpg", GPStreamFactory::FILE);
            out->getType(0)->vSave(out->get(0), outputjpeg.get());
            delete out;
        }
        std::vector<const IStatusType*> types;
        gp = gen->createFunction("S(TFR(C(x0,x1), FR(x2, x3)))", types);
        {
            GPContents contents;
            GPPtr<GPStream> inputjpeg = GPStreamFactory::NewStream("input.jpg", GPStreamFactory::FILE);
            auto pic = bmptype->vLoad(inputjpeg.get());
            contents.push(pic, bmptype);
            inputjpeg = GPStreamFactory::NewStream("output.jpg", GPStreamFactory::FILE);
            pic = bmptype->vLoad(inputjpeg.get());
            contents.push(pic, bmptype);
            inputjpeg = GPStreamFactory::NewStream("input_sharp.jpg", GPStreamFactory::FILE);
            pic = bmptype->vLoad(inputjpeg.get());
            contents.push(pic, bmptype);
            inputjpeg = GPStreamFactory::NewStream("output.jpg", GPStreamFactory::FILE);
            pic = bmptype->vLoad(inputjpeg.get());
            contents.push(pic, bmptype);
            
            GPContents* out = gp->vRun(&contents);
            GPASSERT(NULL!=out);
            GPASSERT(out->size() == 1);
            GPPtr<GPWStream> outputjpeg = GPStreamFactory::NewWStream("output/GPStreamTest2.jpg", GPStreamFactory::FILE);
            out->getType(0)->vSave(out->get(0), outputjpeg.get());
            delete out;
        }
    }
}

static GPTestRegister<GPStreamADFTest> a("GPStreamADFTest");
