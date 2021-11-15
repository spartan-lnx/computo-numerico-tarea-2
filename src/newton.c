#include "../include/newton.h"
#include "../include/funciones.h"

void metodonewton(char nombre[],double x, double objetivo,int variante, double epsilon)
{
    double fx,fxprime;
    int i=0,max_it = 50;
    FILE* archivo = fopen(nombre,"w+");
    
    fprintf(archivo, "\\begin{center}\n");
    fprintf(archivo,"\\begin{tabular}{c c c}\n");
    fprintf(archivo,"it & x_i & f(x_i)\\\\ \n");
    printf("it\txi\t\t\tfxi\n");
    switch(variante)
    {
        case EXACTA:
        {
            do{
                fx = cosx_minus_x(x);
                fxprime = minus_sinx_minus_one(x);
                printf("%d\t%.13g\t\t%.13g\n",i++,x,fx);
                guardartablanewtonlatex(archivo,i,x,fx,13);
                x = x - (fx/fxprime);
            }while(fabs(fx) > objetivo && i<max_it);
            break;
        }
        
        case ADELANTE:
        {
            do{
                fx = cosx_minus_x(x);
                fxprime = derivada_adelante(x,epsilon);
                printf("%d\t%.13g\t\t%.13g\n",i++,x,fx);
                guardartablanewtonlatex(archivo,i,x,fx,13);
                x = x - (fx/fxprime);
            }while(fabs(fx) > objetivo && i<max_it);   
            break;
        }
        
        case DETRAS:
        {
            do{
                fx = cosx_minus_x(x);
                fxprime = derivada_atras(x,epsilon);
                printf("%d\t%.13g\t\t%.13g\n",i++,x,fx);
                guardartablanewtonlatex(archivo,i,x,fx,13);
                x = x - (fx/fxprime);
            }while(fabs(fx) > objetivo && i<max_it);
            break;
        }
        
        case CENTRAL:
        {
            do{
                fx = cosx_minus_x(x);
                fxprime = derivada_central(x,epsilon);
                printf("%d\t%.13g\t\t%.13g\n",i++,x,fx);
                guardartablanewtonlatex(archivo,i,x,fx,13);
                x = x - (fx/fxprime);
            }while(fabs(fx) > objetivo && i<max_it);
            break;
        }

        case EXACTAFUNCIONDIFICIL:
        {
             do{
                fx = funcion_dificil(x);
                fxprime = derivada_funcion_dificil(x);
                printf("%d\t%.14g\t\t%.14g\n",i++,x,fx);
                guardartablanewtonlatex(archivo,i,x,fx,14);
                x = x - (fx/fxprime);
            }while(fabs(fx) > objetivo && i<90);
            break;
        }
    }
    fprintf(archivo,"\\end{tabular}\n");
    fprintf(archivo,"\\end{center}\n");
    fclose(archivo);
}

void guardartablanewtonlatex(FILE* archivo,int i, double x, double fx, int cifras_significativas)
{
    if(cifras_significativas==13)
        fprintf(archivo,"%d & %.13g & %.13g \\\\\n",i,x,fx);
    if(cifras_significativas==14)
        fprintf(archivo,"%d & %.14g & %.14g \\\\\n",i,x,fx);
}