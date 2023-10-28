#pragma once 

#include<Dibujo.hpp>
#include<Actualizable.hpp>
#include<Vector.hpp>

class Bomba : public Dibujo, public Actualizable
{
private:

public:
    Bomba(Vector posicion) : Dibujo(posicion.LeerX(),posicion.LeerY(), "Bomba")
    {

    }

    void Actualizar()
    {
    
    }

    ~Bomba() 
    {

    }
};