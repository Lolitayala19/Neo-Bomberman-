#pragma once

#include<Dibujo.hpp>

class Enemigo : public Dibujo
{
private:
int x,y;
public:
    Enemigo(int x, int y) : Dibujo("Enemigo") 
    {
    this->posicion.DesplazarX(x);
    this->posicion.DesplazarY(y);
    }
    ~Enemigo() 
    {

    }
};