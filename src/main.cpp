
#include <iostream>
#include <Mascota.hpp>


int main(int argc, char const *argv[])
{

    std::cout<<"Juego de mascotas"<<std::endl;
    Mascota m1,m2,m3;  
    m1.Establecernombre("Pedro");
    m2.Establecernombre("Pablo");
    m3.Establecernombre("Leticia");

    m1.Decirnombre();
    m2.Decirnombre();
    m3.Decirnombre();
    return 0;
}
