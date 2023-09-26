CXX = x86_64-w64-mingw32-g++

RunNeoBomberman: src/RunNeoBomberman.cpp
	g++ src/NeoBomberman.cpp -o src/NeoBomberman -I include $(CXXFLAGS)

bin/NeoBomberman : src/NeoBomberman.cpp
	g++ src/NeoBomberman.cpp -o bin/NeoBomberman -I include

runMascota : bin/runMascota
	./bin/mascota

bin/mascota : src/mascota.cpp include/Mascota.hpp
	$(CXX) src/mascota.cpp -o bin/mascota -I include

cleanMascota : bin/mascota
	rm bin/mascota
