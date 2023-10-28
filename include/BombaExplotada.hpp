#pragma once

#include<Dibujo.hpp>
#include<Vector.hpp>
#include<Actualizable.hpp>

class BombaExplotada : public Dibujo, public Actualizable
{
private:
    /* data */
public:
    BombaExplotada( ) : Dibujo(posicion.LeerX(),posicion.LeerY(),"BombaExplotada")
    {
    
    }
    ~BombaExplotada() 
    {
        
    }
};