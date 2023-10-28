CXX = x86_64-w64-mingw32-g++

RunNeoBomberman: src/RunNeoBomberman.cpp
	g++ src/NeoBomberman.cpp -o src/NeoBomberman -I include $(CXXFLAGS)

bin/bomberman: src/bomberman.cpp include/*
	c++ src/bomberman.cpp -o bin/bomberman -I include -l curses

runbomberman : bin/bomberman
	./bin/bomberman

clean: bin/bomberman
	rm bin/bomberman


