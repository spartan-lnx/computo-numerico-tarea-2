#include "../include/biseccion.h"
#include "../include/funciones.h"
#include <stdio.h>

int metodobiseccion(double a,double b,double objetivo,int funcion, double calculos [][4],int maxit)
{
    double c,fc;
    int i = 0;

    switch(funcion)
    {
        case FUNCIONFACIL:
        {
            if(cosx_minus_x(a)*cosx_minus_x(b) > 0)
            {
                printf("Error: No hay un cambio de signo entre f(a) y f(b)\n");
                return -1;
            }
            
            do{
                c = (a+b)/2;
                fc = (cosx_minus_x(c));
                actualizartablabiseccion(calculos, i++, a, b, c, fc);
                if(fabs(fc) < objetivo || i > maxit)
                {
                    break;
                }
                else
                {
                    if(fc*cosx_minus_x(a) <= 0)
                    {
                        b = c;
                    }
                    else
                    {
                        a = c;
                    } 
                }
            }while(fabs(fc) > objetivo || i < maxit);
         
            break;   
        }
        case FUNCIONDIFICIL:
        {
            if(funcion_dificil(a)*funcion_dificil(b) > 0)
            {
                printf("Error: No hay un cambio de signo entre f(a) y f(b)\n");
                return -1;
            }

            do{
                c = (a+b)/2;
                fc = (funcion_dificil(c));
                actualizartablabiseccion(calculos, i++, a, b, c, fc);
                if(fabs(fc) < objetivo || i > maxit)
                {
                    break;
                }
                else
                {
                    if(fc*funcion_dificil(a) <= 0)
                    {
                        b = c;
                    }
                    else
                    {
                        a = c;
                    } 
                }
            }while(fabs(fc) > objetivo || i < maxit);
            break;   
        }

        default:
        {
            printf("Error: Funcion Invalida. Funciones validas:\nFUNCIONFACIL\nFUNCIONDIFICIL\n");
            return -1;
        }
    }

    return i;
}

void actualizartablabiseccion(double calculos[][4],int i,double a,double b, double c, double fc)
{
    calculos[i][0] = a;
    calculos[i][1] = b;
    calculos[i][2] = c;
    calculos[i][3] = fc;
}

void mostrartablabiseccion(double calculos[][4],int n,int cifras_significativas)
{
    int i;

    switch (cifras_significativas) 
    {
        case 11:
        {
            printf("it\ta\t\tb\t\tc\t\tf(c)\n");
            for(i=0;i < n; i++)
            {
                printf("%d\t%-8.11g\t%-8.11g\t%-8.11g\t%-8.11g\n",i,calculos[i][0],calculos[i][1],calculos[i][2],
                    calculos[i][3]);
            }
            break;
        }
        case 5:
        {
            printf("it\ta\t\tb\t\tc\t\tf(c)\n");
            for(i=0;i < n; i++)
            {
                printf("%d\t%-8.5g\t%-8.5g\t%-8.5g\t%-8.5g\n",i,calculos[i][0],calculos[i][1],calculos[i][2],
                    calculos[i][3]);
            }
            break;
        }
        default:
        {
            printf("it\ta\t\tb\t\tc\t\tf(c)\n");
            for(i=0;i < n; i++)
            {
                printf("%d\t%-8.10g\t%-8.10g\t%-8.10g\t%-8.10g\n",i,calculos[i][0],calculos[i][1],calculos[i][2],
                    calculos[i][3]);
            }
            break;
        }
    }
}

void guardartablabiseccionlatex(double calculos[][4],int n,int cifras_significativas, char nombre[])
{
    int i;
    FILE* archivo = fopen(nombre, "w+");

    fprintf(archivo, "\\begin{center}\n");
    fprintf(archivo, "\\begin{tabular}{c c c c c}\n");
    fprintf(archivo, "it & $a$ & $b$ & $c$ & $f(c)$\\\\\n");

    for (i=0; i < n; i++) 
    {
        switch (cifras_significativas) 
        {
            case 11:
            {
                fprintf(archivo,"%d & %.11g & %.11g & %.11g & %.11g\\\\\n",i,calculos[i][0],calculos[i][1],calculos[i][2],
                calculos[i][3]);
                break;
            }
            case 5:
            {
                fprintf(archivo,"%d & %.5g & %.5g & %.5g & %.5g\\\\\n",i,calculos[i][0],calculos[i][1],calculos[i][2],
                calculos[i][3]);
                break;
            }
            default:
            {
                fprintf(archivo,"%d & %.10g & %.10g & %.10g & %.10g\\\\\n",i,calculos[i][0],calculos[i][1],calculos[i][2],
                calculos[i][3]);
                break;
            }
        }
    }

    fprintf(archivo, "\\end{tabular}\n");
    fprintf(archivo, "\\end{center}\n");
    fclose(archivo);
}