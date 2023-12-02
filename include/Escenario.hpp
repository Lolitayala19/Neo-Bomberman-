#ifndef __ESCENARIO_H__
#define __ESCENARIO_H__
#include <ctime>
#include <stdlib.h>
#define filas 15
#define columnas 17

using namespace System::Drawing

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

    void DibujarMatriz(Graphics^g, Bitmap^bmpSolido, Bitmap^bmpDestruible)
    {
    int X=0,Y=0;

    for(int i=0; i<filas; i++)
    {
        for(int j=0; j<columnas; j++)
        {
            if(matriz[i][j]==0 || matriz[i][j]==2)
            {
            g->DrawImage(bmpSolido,X,Y,50,50);
            }
            else
            {
            if(matriz[i][j]==3 || matriz[i][j]==2)
            g->DrawImage(bmpDestruible,X,Y,50,50);
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
#endif
