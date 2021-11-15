#include "../include/biseccion.h"

void metodobiseccion(char nombre[],double a,double b,double objetivo,int funcion)
{
    double c,fc;
    FILE* archivo = fopen(nombre,"w+");
    int i = 0,max_it=50;
    
    fprintf(archivo,"\\begin{center}\n");
    fprintf(archivo,"\\begin{tabular}{c c c c c}\n");
    fprintf(archivo,"it & $a$ & $b$ & $c$ & $f(c)$ \\\\ \n");
    printf("it\ta\t\tb\t\tc\t\tfc\n");

    switch(funcion)
    {
        case FUNCIONFACIL:
        {
            do{
                c = (a+b)/2;
                fc = (cosx_minus_x(c));
                mostrartablabiseccion(i++,a,b,c,fc,11);
                guardartablabiseccionlatex(archivo,i++,a,b,c,fc,11);
                if(fabs(fc) < objetivo || i > max_it)
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
            }while(fabs(fc) > objetivo || i < max_it);
         
            break;   
        }
        case FUNCIONDIFICIL:
        {
            do{
                c = (a+b)/2;
                fc = (funcion_dificil(c));
                mostrartablabiseccion(i++,a,b,c,fc,5);
                guardartablabiseccionlatex(archivo,i++,a,b,c,fc,5);
                if(fabs(fc) < objetivo || i > max_it)
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
            }while(fabs(fc) > objetivo || i < max_it);
            break;   
        }
    }
    
    fprintf(archivo,"\\end{tabular}\n");
    fprintf(archivo,"\\end{center}\n");
    fclose(archivo);
}

void mostrartablabiseccion(int i, double a, double b, double c, double fc,int cifras_significativas)
{
    if(cifras_significativas == 11)
        printf("%d\t%.11g\t%.11g\t%.11g\t%.11g\n",i,a,b,c,fc);
    else
        printf("%d\t%.5g\t%.5g\t%.5g\t%.5g\n",i,a,b,c,fc);
}

void guardartablabiseccionlatex(FILE* archivo, int i, double a, double b, double c, double fc,int cifras_significativas)
{
    if(cifras_significativas == 11)
        fprintf(archivo,"%d & %.11g & %.11g & %.11g & %.11g \\\\\n",i,a,b,c,fc);
    else
        fprintf(archivo,"%d & %.5g & %.5g & %.5g & %.5g \\\\\n",i,a,b,c,fc);
}