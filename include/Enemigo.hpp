#pragma once

#include<Dibujo.hpp>

class Enemigo : public Dibujo
{
private:
int x;
public:
    Enemigo() : Dibujo("Enemigo") 
    {

    }
    ~Enemigo() 
    {

    }
};