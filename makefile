CXX = x86_64-w64-mingw32-g++

RunNeoBomberman: src/RunNeoBomberman.cpp
	g++ src/NeoBomberman.cpp -o src/NeoBomberman -I include $(CXXFLAGS)

<<<<<<< HEAD
bin/NeoBomberman : src/NeoBomberman.cpp
	g++ src/NeoBomberman.cpp -o bin/NeoBomberman -I include

runMascota : bin/runMascota
	./bin/mascota
=======
bin/bomberman: src/bomberman.cpp include/*
	c++ src/bomberman.cpp -o bin/bomberman -I include -l curses
>>>>>>> 3d413e5 (Proyecto 85% terminado)

runbomberman : bin/bomberman
	./bin/bomberman

