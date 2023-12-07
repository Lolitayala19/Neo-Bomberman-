CXX = x86_64-w64-mingw32-g++
SDL_INCLUDE = -IC:\msys64\mingw64\include\SDL2 -LC:\msys64\mingw64\lib
CXXFLAGS = $(SDL_INCLUDE) -w Wl,-subsystem,windows -lmingw32 -lSDL2main -lSDL2

runneobomberman: src/RunNeoBomberman.cpp
	g++ src/NeoBomberman.cpp -o src/NeoBomberman -I include $(CXXFLAGS)

bin/bomberman: src/bomberman.cpp include/*
	g++ src/bomberman.cpp -o bin/bomberman -I include -lncurses

runbomberman : bin/bomberman
	./bin/bomberman

bin/personaje: src/personaje.cpp include/*
	g++ $< -o $@ -I include -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

runpersonaje: bin/personaje
	./$<
	
clean: bin/personaje
	rm bin/personaje
