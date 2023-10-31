#pragma once

#include <Vector.hpp>
#include <Dibujo.hpp>
#include <Actualizable.hpp>
#include <list>

class NeoBomberman : public Dibujo, public Actualizable
{
private:
    int x, y;
public:
    NeoBomberman(/* args */) : Dibujo("Bomberman")
    {

    }
    NeoBomberman(int x, int y) : Dibujo("Bomberman")
    {
        this->posicion.DesplazarX(x);
        this->posicion.DesplazarY(y);
    }
    void Actualizar()
    {
        this->x = this->posicion.LeerX();
        this->y = this->posicion.LeerY();
       // this->posicion.CambiarDireccionX();
    }
    void Avanzar()
    {
        this->posicion.DesplazarX(1);
    }
    void AvanzarY()
    {
        this->posicion.DesplazarY(1);
    }
    void CambiarDireccionY()
    {
        this->posicion.CambiarDireccionY();
    }
    void CambiarDireccion()
    {
        this->posicion.CambiarDireccionX();
    }
    Vector LeerPosicion()
    {
        return this->posicion;
    }
    ~NeoBomberman() 
    {

    }
};