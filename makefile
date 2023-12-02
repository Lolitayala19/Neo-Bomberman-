CXX = x86_64-w64-mingw32-g++

runneobomberman: src/RunNeoBomberman.cpp
	g++ src/NeoBomberman.cpp -o src/NeoBomberman -I include $(CXXFLAGS)

bin/bomberman: src/bomberman.cpp include/*
	c++ src/bomberman.cpp -o bin/bomberman -I include -l curses

runbomberman : bin/bomberman
	./bin/bomberman

bin/personaje: src/personaje.cpp include/*
	c++ src/personaje.cpp -o bin/personaje -I include -lsfml-graphics -lsfml.window -lsfml-system -lsfml-audio

runpersonaje: bin/personaje
	./bin/personaje
	
clean: bin/bomberman
	rm bin/bomberman
