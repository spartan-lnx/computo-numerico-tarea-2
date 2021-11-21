#include "../include/misc.h"
#include "../include/main.h"

void rellenarcerostabla(double totalcalculos[][13],int i,int maxit,int l,int m,int n)
{
    int j;
    for(j=i;j<maxit;j++)
    {
        totalcalculos[j][0] = j;
        totalcalculos[j][l] = 0;
        totalcalculos[j][m] = 0;
        totalcalculos[j][n] = 0; //cuidado con el ultimo
    }
}

void rellenarcerostablasecante(double totalcalculos[][16],int i,int maxit,int l,int m,int n)
{
    int j;
    for(j=i;j<maxit;j++)
    {
        totalcalculos[j][0] = j;
        totalcalculos[j][l] = 0;
        totalcalculos[j][m] = 0;
        totalcalculos[j][n] = 0; //cuidado con el ultimo
    }
}