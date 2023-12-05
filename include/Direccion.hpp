#pragma once

#include<Personajearriba.hpp>
#include<Personajeabajo.hpp>
#include<Personajederecha.hpp>
#include<Personajeizquierda.hpp>
#include<Vector.hpp>
#include <SFML/Graphics.hpp>

class Direccion
{
private:

public:
    Direccion(/* args */) 
    {

    }
    Vector V;
    Personajearriba *Pa = New Personajearriba;
    Personajeabajo *Pab = New Personajeabajo;
    Personajeizquierda *Pi = New Personajeizquierda;
    Personajederecha *Pd = New Personajederecha;
    void Sentido()
    {
    int key = getch();
        if (key == 'a' || key == KEY_LEFT)
        {
        *Pa->
        }
        if (key == 'd' || key == KEY_RIGHT)
        {
            NB->CambiarDireccion();
        }
        if (key == 'w' || key == KEY_UP)
        {
            NB->AvanzarY();
        }
        if (key == 's' || key == KEY_DOWN)
        {
          NB->CambiarDireccionY();  
        }    
    }
    ~Direccion() 
    {

    }
};