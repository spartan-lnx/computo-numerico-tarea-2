#include "../include/puntofijo.h"

int metodopuntofijo(double x,double objetivo, double calculos[][2],int maxit)
{
    int i=0;
    double fx;
    do{
        fx = cosx_minus_x(x);
        actualizartablapuntofijo(calculos,i++,x,fx);
        x = fx + x;
    }while(fabs(fx) > objetivo && i < maxit);

    return i;
}

void actualizartablapuntofijo(double calculos[][2],int i, double x, double fx)
{
    calculos[i][0] = x;
    calculos[i][1] = fx;
}

void mostrartablapuntofijo(double calculos[][2], int n, int cifras_significativas)
{
    int i;
    switch (cifras_significativas) 
    {
        case 11:
        {
            printf("it\txi\t\tfxi\n");
            for(i = 0; i < n; i++)
            {
                printf("%d\t%-8.11g\t%-8.11g\n",i,calculos[i][0],calculos[i][1]);
            }   
            break;
        }
        default:
        {
            printf("it\txi\t\tfxi\n");
            for(i = 0; i < n; i++)
            {
                printf("%d\t%-8.10g\t%-8.10g\n",i,calculos[i][0],calculos[i][1]);
            }
            break;
        }
    }
}

void guardartablapuntofijolatex(double calculos[][2], int n, int cifras_significativas, char nombre[])
{
    int i;
    FILE* archivo = fopen(nombre,"w+");

    fprintf(archivo,"\\begin{center}\n");
    fprintf(archivo,"\\begin{tabular}{c c c}\n");
    fprintf(archivo,"it & $x_i$ & $f(x_i)$\\\\\n");

    switch (cifras_significativas) 
    {
        case 11:
        {
            for(i = 0; i < n; i++)
            {
                fprintf(archivo,"%d & %.11g & %.11g\\\\\n",i,calculos[i][0],calculos[i][1]);
            }   
            break;
        }
        default:
        {
            for(i = 0; i < n; i++)
            {
                fprintf(archivo,"%d & %.10g & %.10g\\\\\n",i,calculos[i][0],calculos[i][1]);
            }
            break;
        }
    }
    fprintf(archivo,"\\end{tabular}\n");
    fprintf(archivo,"\\end{center}\n");
    fclose(archivo);
}