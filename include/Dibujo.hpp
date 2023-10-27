#pragma once

#include <string>
#include <fstream>
#include <curses.h>
#include <Vector.hpp>

using namespace std;

class Dibujo
{
private:
    bool is_open;
    fstream archivo;
    string directorio;

protected:
    Vector posicion;

public:
    Dibujo(int x, int y,string recurso) 
    {
        this->directorio = "./data/" + recurso + ".txt";
        this->is_open = false;
        this->archivo.open(this->directorio, ios::in);
        this->posicion = Vector (x,y);    
    }
    Dibujo(string recurso) :Dibujo(0,0,recurso)
    {
   
    }
        void Dibujar()
    {
        if (archivo.is_open())
        {

            std::string line;

            move(
                this->posicion.LeerY(), this->posicion.LeerX());

            while (std::getline(archivo, line))
            {
                int y;

                y = getcury(stdscr);

                mvaddstr(
                    y + 1,
                    this->posicion.LeerX(),
                    line.c_str());
            }

            archivo.clear();
            archivo.seekg(0);
        }
    }
    ~Dibujo() 
    {
        archivo.close();    
    }
};