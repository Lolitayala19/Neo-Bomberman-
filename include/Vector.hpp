#pragma once

class Vector
{
private:
    int x, y;
    int direccion_x;
    int direccion_y;

public:
    Vector(/* args */) 
    {
        this->x = 0;
        this->y = 0;
        direccion_x = 1;
        direccion_y = 1;
    }
    Vector(int x, int y)
    {
        this->x = x;
        this->y = y;
        this->direccion_x = 1;
        this->direccion_y = 1;
    }
    void CambiarDireccionX()
    {
        this->x -= x *this->direccion_x;
    }

    void CambiarDireccionY()
    {
        this->y -= y *this->direccion_y;
    }

    void DesplazarX(unsigned int x)
    {
        this->x += x * this->direccion_x;
    }
    void DesplazarY(unsigned int y)
    {
        this->y += y * this->direccion_y;
    }
    int LeerX()
    {
        return this->x;
    }
    int LeerY()
    {
        return this->y;
    }
    ~Vector() 
    {

    }
};