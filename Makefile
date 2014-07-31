all:libGP.so test.out gpsuit.out 

ALL_INCLUESlibGP.so= include/core/status.h include/core/AbstractGP.h include/core/GPProducerFactory.h include/core/funcStatusType.h include/core/genetic_operator.h include/core/GP_XmlString.h include/core/IDataBase.h include/core/BasicComposeFunction.h include/core/function.h include/core/GPData.h include/core/IGPAutoDefFunction.h include/core/group.h include/core/GPProducer.h include/core/computeTree.h include/system/xmlDataBase.h include/system/GenerateSystem.h include/system/mutateTree.h include/system/recurse_tree.h include/system/computeSystem.h include/system/system_lib.h include/system/xmlGenerateSystem.h include/evolution/GPEvolutionGroup.h include/evolution/AbstractEvolutionGroup.h include/math/AbstractPoint.h include/math/carryTree.h include/math/carryArray.h include/math/carryPoint.h include/math/GPSingleTree.h include/utils/statusMachine.h include/utils/RefCount.h include/utils/AutoClean.h include/utils/BasicTree.h include/utils/debug.h include/utils/GP_Clock.h include/xml/xmlGPDataLoader.h include/xml/xmlFunctionLoader.h include/xml/xmlGPLoader.h include/xml/xmlReader.h include/xml/xmlTree.h

libGP.so:  build/core_BasicComposeFunction.o build/core_GPData.o build/core_GPProducerFactory.o build/core_GP_XmlString.o build/core_status.o build/core_AbstractGP.o build/core_function.o build/core_funcStatusType.o build/system_GenerateSystem.o build/system_recurse_tree.o build/system_computeSystem.o build/system_system_lib.o build/system_mutateTree.o build/system_xmlDataBase.o build/system_xmlGenerateSystem.o build/platform_system_lib.o build/evolution_GPEvolutionGroup.o build/math_GPSingleTree.o build/math_AbstractPoint.o build/math_carryPoint.o build/math_carryArray.o build/utils_GP_Clock.o build/utils_statusMachine.o build/xml_xmlFunctionLoader.o build/xml_xmlReader.o build/xml_xmlGPDataLoader.o build/xml_xmlGPLoader.o build/xml_xmlTree.o build/utils_debug.o 
	g++  -O3 --share  -o libGP.so  build/core_BasicComposeFunction.o build/core_GPData.o build/core_GPProducerFactory.o build/core_GP_XmlString.o build/core_status.o build/core_AbstractGP.o build/core_function.o build/core_funcStatusType.o build/system_GenerateSystem.o build/system_recurse_tree.o build/system_computeSystem.o build/system_system_lib.o build/system_mutateTree.o build/system_xmlDataBase.o build/system_xmlGenerateSystem.o build/platform_system_lib.o build/evolution_GPEvolutionGroup.o build/math_GPSingleTree.o build/math_AbstractPoint.o build/math_carryPoint.o build/math_carryArray.o build/utils_GP_Clock.o build/utils_statusMachine.o build/xml_xmlFunctionLoader.o build/xml_xmlReader.o build/xml_xmlGPDataLoader.o build/xml_xmlGPLoader.o build/xml_xmlTree.o build/utils_debug.o  -lpthread -ldl ${SELF_VARIABLES}
build/core_BasicComposeFunction.o : src/core/BasicComposeFunction.cpp ${ALL_INCLUESlibGP.so}
	g++ -O3 -o build/core_BasicComposeFunction.o -c src/core/BasicComposeFunction.cpp -Iinclude 
build/core_GPData.o : src/core/GPData.cpp ${ALL_INCLUESlibGP.so}
	g++ -O3 -o build/core_GPData.o -c src/core/GPData.cpp -Iinclude 
build/core_GPProducerFactory.o : src/core/GPProducerFactory.cpp ${ALL_INCLUESlibGP.so}
	g++ -O3 -o build/core_GPProducerFactory.o -c src/core/GPProducerFactory.cpp -Iinclude 
build/core_GP_XmlString.o : src/core/GP_XmlString.cpp ${ALL_INCLUESlibGP.so}
	g++ -O3 -o build/core_GP_XmlString.o -c src/core/GP_XmlString.cpp -Iinclude 
build/core_status.o : src/core/status.cpp ${ALL_INCLUESlibGP.so}
	g++ -O3 -o build/core_status.o -c src/core/status.cpp -Iinclude 
build/core_AbstractGP.o : src/core/AbstractGP.cpp ${ALL_INCLUESlibGP.so}
	g++ -O3 -o build/core_AbstractGP.o -c src/core/AbstractGP.cpp -Iinclude 
build/core_function.o : src/core/function.cpp ${ALL_INCLUESlibGP.so}
	g++ -O3 -o build/core_function.o -c src/core/function.cpp -Iinclude 
build/core_funcStatusType.o : src/core/funcStatusType.cpp ${ALL_INCLUESlibGP.so}
	g++ -O3 -o build/core_funcStatusType.o -c src/core/funcStatusType.cpp -Iinclude 
build/system_GenerateSystem.o : src/system/GenerateSystem.cpp ${ALL_INCLUESlibGP.so}
	g++ -O3 -o build/system_GenerateSystem.o -c src/system/GenerateSystem.cpp -Iinclude 
build/system_recurse_tree.o : src/system/recurse_tree.cpp ${ALL_INCLUESlibGP.so}
	g++ -O3 -o build/system_recurse_tree.o -c src/system/recurse_tree.cpp -Iinclude 
build/system_computeSystem.o : src/system/computeSystem.cpp ${ALL_INCLUESlibGP.so}
	g++ -O3 -o build/system_computeSystem.o -c src/system/computeSystem.cpp -Iinclude 
build/system_system_lib.o : src/system/system_lib.cpp ${ALL_INCLUESlibGP.so}
	g++ -O3 -o build/system_system_lib.o -c src/system/system_lib.cpp -Iinclude 
build/system_mutateTree.o : src/system/mutateTree.cpp ${ALL_INCLUESlibGP.so}
	g++ -O3 -o build/system_mutateTree.o -c src/system/mutateTree.cpp -Iinclude 
build/system_xmlDataBase.o : src/system/xmlDataBase.cpp ${ALL_INCLUESlibGP.so}
	g++ -O3 -o build/system_xmlDataBase.o -c src/system/xmlDataBase.cpp -Iinclude 
build/system_xmlGenerateSystem.o : src/system/xmlGenerateSystem.cpp ${ALL_INCLUESlibGP.so}
	g++ -O3 -o build/system_xmlGenerateSystem.o -c src/system/xmlGenerateSystem.cpp -Iinclude 
build/platform_system_lib.o : src/platform/system_lib.cpp ${ALL_INCLUESlibGP.so}
	g++ -O3 -o build/platform_system_lib.o -c src/platform/system_lib.cpp -Iinclude 
build/evolution_GPEvolutionGroup.o : src/evolution/GPEvolutionGroup.cpp ${ALL_INCLUESlibGP.so}
	g++ -O3 -o build/evolution_GPEvolutionGroup.o -c src/evolution/GPEvolutionGroup.cpp -Iinclude 
build/math_GPSingleTree.o : src/math/GPSingleTree.cpp ${ALL_INCLUESlibGP.so}
	g++ -O3 -o build/math_GPSingleTree.o -c src/math/GPSingleTree.cpp -Iinclude 
build/math_AbstractPoint.o : src/math/AbstractPoint.cpp ${ALL_INCLUESlibGP.so}
	g++ -O3 -o build/math_AbstractPoint.o -c src/math/AbstractPoint.cpp -Iinclude 
build/math_carryPoint.o : src/math/carryPoint.cpp ${ALL_INCLUESlibGP.so}
	g++ -O3 -o build/math_carryPoint.o -c src/math/carryPoint.cpp -Iinclude 
build/math_carryArray.o : src/math/carryArray.cpp ${ALL_INCLUESlibGP.so}
	g++ -O3 -o build/math_carryArray.o -c src/math/carryArray.cpp -Iinclude 
build/utils_GP_Clock.o : src/utils/GP_Clock.cpp ${ALL_INCLUESlibGP.so}
	g++ -O3 -o build/utils_GP_Clock.o -c src/utils/GP_Clock.cpp -Iinclude 
build/utils_statusMachine.o : src/utils/statusMachine.cpp ${ALL_INCLUESlibGP.so}
	g++ -O3 -o build/utils_statusMachine.o -c src/utils/statusMachine.cpp -Iinclude 
build/xml_xmlFunctionLoader.o : src/xml/xmlFunctionLoader.cpp ${ALL_INCLUESlibGP.so}
	g++ -O3 -o build/xml_xmlFunctionLoader.o -c src/xml/xmlFunctionLoader.cpp -Iinclude 
build/xml_xmlReader.o : src/xml/xmlReader.cpp ${ALL_INCLUESlibGP.so}
	g++ -O3 -o build/xml_xmlReader.o -c src/xml/xmlReader.cpp -Iinclude 
build/xml_xmlGPDataLoader.o : src/xml/xmlGPDataLoader.cpp ${ALL_INCLUESlibGP.so}
	g++ -O3 -o build/xml_xmlGPDataLoader.o -c src/xml/xmlGPDataLoader.cpp -Iinclude 
build/xml_xmlGPLoader.o : src/xml/xmlGPLoader.cpp ${ALL_INCLUESlibGP.so}
	g++ -O3 -o build/xml_xmlGPLoader.o -c src/xml/xmlGPLoader.cpp -Iinclude 
build/xml_xmlTree.o : src/xml/xmlTree.cpp ${ALL_INCLUESlibGP.so}
	g++ -O3 -o build/xml_xmlTree.o -c src/xml/xmlTree.cpp -Iinclude 
build/utils_debug.o : src/utils/debug.c ${ALL_INCLUESlibGP.so}
	gcc -O3 -o build/utils_debug.o -c src/utils/debug.c -Iinclude 

ALL_INCLUEStest.out= include/test/GPTest.h

test.out:  build/test_main.o build/test_GPcombineTest.o build/test_AbstractPointTest.o build/test_GPXmlEvolutionTest.o build/test_GPSingleTreeTest.o build/test_GPloadXmlTreeTest.o build/test_GPGPDataTest.o build/test_GPTest.o build/test_GPxmlTreeTest.o build/test_GPSearchIOTest.o libGP.so
	g++  -O3 -o test.out  build/test_main.o build/test_GPcombineTest.o build/test_AbstractPointTest.o build/test_GPXmlEvolutionTest.o build/test_GPSingleTreeTest.o build/test_GPloadXmlTreeTest.o build/test_GPGPDataTest.o build/test_GPTest.o build/test_GPxmlTreeTest.o build/test_GPSearchIOTest.o  ./libGP.so -ldl -lpthread  ${SELF_VARIABLES}
build/test_main.o : src/test/main.cpp ${ALL_INCLUEStest.out}
	g++ -O3 -o build/test_main.o -c src/test/main.cpp -Iinclude 
build/test_GPcombineTest.o : src/test/GPcombineTest.cpp ${ALL_INCLUEStest.out}
	g++ -O3 -o build/test_GPcombineTest.o -c src/test/GPcombineTest.cpp -Iinclude 
build/test_AbstractPointTest.o : src/test/AbstractPointTest.cpp ${ALL_INCLUEStest.out}
	g++ -O3 -o build/test_AbstractPointTest.o -c src/test/AbstractPointTest.cpp -Iinclude 
build/test_GPXmlEvolutionTest.o : src/test/GPXmlEvolutionTest.cpp ${ALL_INCLUEStest.out}
	g++ -O3 -o build/test_GPXmlEvolutionTest.o -c src/test/GPXmlEvolutionTest.cpp -Iinclude 
build/test_GPSingleTreeTest.o : src/test/GPSingleTreeTest.cpp ${ALL_INCLUEStest.out}
	g++ -O3 -o build/test_GPSingleTreeTest.o -c src/test/GPSingleTreeTest.cpp -Iinclude 
build/test_GPloadXmlTreeTest.o : src/test/GPloadXmlTreeTest.cpp ${ALL_INCLUEStest.out}
	g++ -O3 -o build/test_GPloadXmlTreeTest.o -c src/test/GPloadXmlTreeTest.cpp -Iinclude 
build/test_GPGPDataTest.o : src/test/GPGPDataTest.cpp ${ALL_INCLUEStest.out}
	g++ -O3 -o build/test_GPGPDataTest.o -c src/test/GPGPDataTest.cpp -Iinclude 
build/test_GPTest.o : src/test/GPTest.cpp ${ALL_INCLUEStest.out}
	g++ -O3 -o build/test_GPTest.o -c src/test/GPTest.cpp -Iinclude 
build/test_GPxmlTreeTest.o : src/test/GPxmlTreeTest.cpp ${ALL_INCLUEStest.out}
	g++ -O3 -o build/test_GPxmlTreeTest.o -c src/test/GPxmlTreeTest.cpp -Iinclude 
build/test_GPSearchIOTest.o : src/test/GPSearchIOTest.cpp ${ALL_INCLUEStest.out}
	g++ -O3 -o build/test_GPSearchIOTest.o -c src/test/GPSearchIOTest.cpp -Iinclude 

ALL_INCLUESgpsuit.out=

gpsuit.out:  build/GPSuit_main.o build/GPSuit_FilePath.o libGP.so
	g++  -O3 -o gpsuit.out  build/GPSuit_main.o build/GPSuit_FilePath.o  ./libGP.so ${SELF_VARIABLES}
build/GPSuit_main.o : src/GPSuit/main.cpp ${ALL_INCLUESgpsuit.out}
	g++ -O3 -o build/GPSuit_main.o -c src/GPSuit/main.cpp -Iinclude 
build/GPSuit_FilePath.o : src/GPSuit/FilePath.cpp ${ALL_INCLUESgpsuit.out}
	g++ -O3 -o build/GPSuit_FilePath.o -c src/GPSuit/FilePath.cpp -Iinclude 

clean:
	rm build/*.o
	rm libGP.so
	rm test.out
	rm gpsuit.out