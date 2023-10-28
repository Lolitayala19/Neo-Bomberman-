#include <iostream>
#include <NeoBomberman.hpp>
#include <unistd.h>
#include <Ventana.hpp>
#include <Dibujo.hpp>
#include <Actualizable.hpp>
#include <list>
#include <fstream>
#include <curses.h>
#include <Enemigo.hpp>
#include <Bomba.hpp>
#include <BombaExplotada.hpp>

using namespace std;

int main(int argc, char const *argv[])
{
    NeoBomberman *NB = new NeoBomberman(5, 5);
    Ventana *V = new Ventana();
    Enemigo *E = new Enemigo(100,2);
   

    list<Dibujo *> dibujos;

    dibujos.push_back(NB);
    dibujos.push_back(E);

    list<Actualizable *> actualizables;
    while(true)
    {
        int key = getch();
        if (key == 'a' || key == KEY_LEFT)
        {
            NB->Avanzar();
        }
        if (key == 'd' || key == KEY_RIGHT)
        {
            NB->CambiarDireccion();
        }
        if (key == ' ')
        {
            Bomba *B = new Bomba(NB->LeerPosicion());
            BombaExplotada *BE = new BombaExplotada();
            dibujos.push_back(B);
            if(key == 'M')
            {
             
            }
    
        }
        V->Dibujar(dibujos);
        V->Actualizar(actualizables);
    }

    return 0;
}
