# pragma once

#include<SFML/Graphics.hpp>
#include <ctime>
#include <stdlib.h>
#define filas 15
#define columnas 17
#include "iostream"
#include "string"

using namespace std;

class Escenario
{
private:
    int **matriz;
public:
    Escenario() {
        matriz = new int*[filas];
    }
    ~Escenario() {}
    void Generarmatriz() 
    {
        srand(time(NULL));
        for (int i=0; i<filas; i++)
        {
            matriz[i] = new int[columnas];
        for (int j=0; j<filas; j++)
        {
          if(i==0 || j==0 ||i==filas -1 || j==columnas -1) 
          {
          matriz[i][j];
          }
          else
          {
            if(i % 2 == 0 && j % 2 == 0)
            {
            matriz[i][j]=1;    
            }
            else
            {
            if((i== 1 && (j==1 || j==2)) || (j==1 && i==2) 
            || (i==filas-2 && j== columnas-3 || j==columnas-2) || (i==filas-3 && j==columnas-2))
            {
            matriz[i][j]=0;
            }
            else
            {
            matriz[i][j] == rand()%2+2;
            }
            }
          }
        }
        }
    }

    void DibujarMatriz()
    {
    int X=0,Y=0;

    for(int i=0; i<filas; i++)
    {
        for(int j=0; j<columnas; j++)
        {
            if(matriz[i][j]==0 || matriz[i][j]==2)
            {
            cout<<"P"<<endl;
            }
            else
            {
            if(matriz[i][j]==3 || matriz[i][j]==2)
            cout<<"O"<<endl;
            }
            X+=50;
        }
        Y+=50;
    }
    int **getmatriz()
    {
        return matriz;
    }
    }
};

