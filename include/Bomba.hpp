#pragma once 

#include<Dibujo.hpp>
#include<Actualizable.hpp>
#include<Vector.hpp>

class Bomba : public Dibujo, public Actualizable
{
private:
int tiempovida;
public:
    Bomba(Vector posicion) : Dibujo(posicion.LeerX(),posicion.LeerY(), "Bomba")
    {
        this->tiempovida=5;
    }

    void Actualizar()
    {
    int key = getch();
       if(key == 'M')
       {
        Dibujo(this->posicion.LeerX(),this->posicion.LeerY(), "BombaExplotada");
       }
    }

    ~Bomba() 
    {

    }
};