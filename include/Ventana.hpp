#pragma once

#include <curses.h>
#include <string>
#include <unistd.h>
#include <iostream>
#include <Dibujo.hpp>
#include <Actualizable.hpp>
#include <list>
class Ventana
{
private:
    int x, y;
    bool cerrar;

public:
    Ventana(/* args */) 
    {
            //Inicializar pantalla
        initscr();

        //eliminar cursos de pantalla
        noecho();
        curs_set(FALSE);

        //no bloquear consola
        cbreak();
        timeout(10);
        keypad(stdscr,TRUE);

        //Inicializar clase
        getmaxyx(stdscr, y, x);
        cerrar = false;    
    }
    ~Ventana() 
    {
        keypad(stdscr,FALSE);
        endwin();    
    }
    void Actualizar(list<Actualizable*> listaactualizables)
    {
        for (auto &&iterador : listaactualizables)
        {
            iterador->Actualizar();
        }

        usleep(41000);
    }

    void Dibujar(list<Dibujo*> listaDibujos)
    {
        clear();
        box(stdscr, 'l', '*');
        for (auto &&dibujo : listaDibujos)
        {
            dibujo->Dibujar();
        }

        refresh();
    }

    bool DeboCerrar()
    {
        return this->cerrar;
    }

    void Cerrar()
    {
        this->cerrar = true;
    }
};