#include "../include/horner.h"

double metodohorner(int coef[],double x,int n)
{
    int i;
    double resultado = coef[0];
    for(i=1;i<n;i++)
    {
        resultado = resultado*x + coef[i];
    }
    return resultado;
}