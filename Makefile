SandBoxDebug: CEngineDebug SandBox/src/*
	echo "Building SandBox"
	g++ -L bin/debug/CEngine/ -lCEngine -I CEngine/src/ -I CEngine/vendor/plog/include/ SandBox/src/main.cpp -o bin/debug/SandBox/main
	cp bin/debug/CEngine/libCEngine.so bin/debug/SandBox/libCEngine.so

CEngineDebug: CEngine/src/* GLFW
	echo "Building CEngine"
	g++ -fPIC -c CEngine/src/window.cpp -c CEngine/src/application.cpp -c CEngine/src/log.cpp -I CEngine/vendor/plog/include/ -LCEngine/vendor/GLFW/build/src -lGL -lglfw3 -ICEngine/vendor/GLFW/include/ -ICEngine/src/
	ld -relocatable application.o log.o -o CEngineT.o
	g++ -shared -Wl,-soname,libCEngine.so -o bin/debug/CEngine/libCEngine.so application.o log.o window.o -lGL -LCEngine/vendor/GLFW/build/src/ -lglfw3

GLFW: CEngine/vendor/GLFW/**/*
	cmake -S CEngine/vendor/GLFW/ -B CEngine/vendor/GLFW/build
	make -C CEngine/vendor/GLFW/build

clean:
	rm -rf bin/debug/CEngine/libCEngine.so
	rm -rf bin/release/CEngine/libCEngine.so
