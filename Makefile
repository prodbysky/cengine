output_release = "bin/release/CEngine/"
output_debug = "bin/debug/CEngine/"

SandBoxDebug: CEngineDebug SandBox/src/*
	echo "Building SandBox"
	g++ -L bin/debug/CEngine/ -lCEngine -I CEngine/src/ SandBox/src/main.cpp -o bin/debug/SandBox/main
	cp bin/debug/CEngine/libCEngine.so bin/debug/SandBox/libCEngine.so

CEngineDebug: CEngine/src/*
	echo "Building CEngine"
	g++ -fPIC -c -o CEngineT.o CEngine/src/application.cpp
	g++ -shared -Wl,-soname,libCEngine.so -o bin/debug/CEngine/libCEngine.so CEngineT.o
	rm CEngineT.o

clean:
	rm -rf bin/debug/CEngine/libCEngine.so
	rm -rf bin/release/CEngine/libCEngine.so
