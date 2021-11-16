#include "../include/newton.h"
#include "../include/funciones.h"
#include <stdio.h>

int metodonewton(double calculos[][2], double x, double objetivo,int variante, double epsilon,int maxit)
{
    double fx,fxprime;
    int i=0;

    switch(variante)
    {
        case EXACTA:
        {
            do{
                fx = cosx_minus_x(x);
                fxprime = minus_sinx_minus_one(x);
                actualizartablanewton(calculos, i++, x, fx);
                x = x - (fx/fxprime);
            }while(fabs(fx) > objetivo && i < maxit);
            break;
        }
        
        case ADELANTE:
        {
            do{
                fx = cosx_minus_x(x);
                fxprime = derivada_adelante(x,epsilon);
                actualizartablanewton(calculos, i++, x, fx);
                x = x - (fx/fxprime);
            }while(fabs(fx) > objetivo && i < maxit);   
            break;
        }
        
        case DETRAS:
        {
            do{
                fx = cosx_minus_x(x);
                fxprime = derivada_atras(x,epsilon);
                actualizartablanewton(calculos, i++, x, fx);
                x = x - (fx/fxprime);
            }while(fabs(fx) > objetivo && i < maxit);
            break;
        }
        
        case CENTRAL:
        {
            do{
                fx = cosx_minus_x(x);
                fxprime = derivada_central(x,epsilon);
                actualizartablanewton(calculos, i++, x, fx);
                x = x - (fx/fxprime);
            }while(fabs(fx) > objetivo && i < maxit);
            break;
        }

        case EXACTAFUNCIONDIFICIL:
        {
             do{
                fx = funcion_dificil(x);
                fxprime = derivada_funcion_dificil(x);
                actualizartablanewton(calculos, i++, x, fx);
                x = x - (fx/fxprime);
            }while(fabs(fx) > objetivo && i < maxit);
            break;
        }
        default:
        {
            printf("Error: Funcion invalida.Funciones validas:\nEXACTA\nADELANTE\nDETRAS\nCENTRAL\nEXACTAFUNCIONDIFICIL\n");
            return -1;
        }
    }
    
    return i;
}

void actualizartablanewton(double calculos[][2],int i,double x, double fx)
{
    calculos[i][0] = x;
    calculos[i][1] = fx;
}

void mostrartablanewton(double calculos[][2],int n, int cifras_significativas)
{
    int i;
    switch(cifras_significativas)
    {
        case 13:
        {
            printf("it\txi\t\t\tfxi\n");
            for(i = 0; i < n; i++)
            {
                printf("%d\t%-8.13g\t\t%-8.13g\n",i,calculos[i][0],calculos[i][1]);
            }
            break;
        }
        case 14:
        {
            for(i = 0; i < n; i++)
            {
                printf("%d\t%-8.14g\t\t%-8.14g\n",i,calculos[i][0],calculos[i][1]);
            }
            break;
        }
        default:
        {
            printf("it\txi\t\t\tfxi\n");
            for(i = 0; i < n; i++)
            {
                printf("%d\t%-8.10g\t\t%-8.10g\n",i,calculos[i][0],calculos[i][1]);
            }
            break;
        }
    }
}

void guardartablanewtonlatex(double calculos[][2],int n, int cifras_significativas, char nombre[])
{
    int i;
    FILE* archivo = fopen(nombre,"w+");
    
    fprintf(archivo, "\\begin{center}\n");
    fprintf(archivo,"\\begin{tabular}{c c c}\n");
    fprintf(archivo,"it & $x_i$ & $f(x_i)$\\\\\n");

    switch(cifras_significativas)
    {
        case 13:
        {
            for(i = 0; i < n; i++)
            {
                fprintf(archivo,"%d & %.13g & %.13g\\\\\n",i,calculos[i][0],calculos[i][1]);
            }
            break;
        }
        case 14:
        {
            for(i = 0; i < n; i++)
            {
                fprintf(archivo,"%d & %.14g & %.14g\\\\\n",i,calculos[i][0],calculos[i][1]);
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