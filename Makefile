SandBoxDebug: CEngineDebug SandBox/src/*
	echo "Building SandBox"
	g++ -L bin/debug/CEngine/ -lCEngine -I CEngine/src/ -I CEngine/vendor/plog/include/ SandBox/src/main.cpp -o bin/debug/SandBox/main
	cp bin/debug/CEngine/libCEngine.so bin/debug/SandBox/libCEngine.so

CEngineDebug: CEngine/src/*
	echo "Building CEngine"
	g++ -fPIC -c CEngine/src/application.cpp -c CEngine/src/log.cpp -I CEngine/vendor/plog/include/
	ld -relocatable application.o log.o -o CEngineT.o
	g++ -shared -Wl,-soname,libCEngine.so -o bin/debug/CEngine/libCEngine.so application.o log.o

clean:
	rm -rf bin/debug/CEngine/libCEngine.so
	rm -rf bin/release/CEngine/libCEngine.so
