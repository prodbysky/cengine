output_release = "bin/release/CEngine/"
output_debug = "bin/debug/CEngine/"

SandBoxDebug: CEngine SandBox/src/*
	echo "Building SandBox"
	g++ -L bin/debug/CEngine/ -lCEngine SandBox/src/main.cpp -o bin/debug/SandBox/main


# bin/debug/CEngine/libCEngine.so
CEngineDebug: CEngine/src/*
	echo "Building CEngine"
	g++ -fPIC -c -o CEngineT.o CEngine/src/test.cpp
	g++ -shared -Wl,-soname,libCEngine.so -o bin/debug/CEngine/libCEngine.so CEngineT.o

