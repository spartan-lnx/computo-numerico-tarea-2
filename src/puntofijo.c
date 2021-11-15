#include "../include/puntofijo.h"

void metodopuntofijo(char nombre[],double x,double objetivo)
{
    int i=0;
    double fx;
    FILE* archivo = fopen(nombre,"w+");

    fprintf(archivo,"\\begin{center}]n");
    fprintf(archivo,"\\begin{tabular}{c c c}\n");
    fprintf(archivo,"it & x_i & f(x_i)\\\\ \n");
    printf("it\txi\t\tfxi\n");

    do{
        fx = cosx_minus_x(x);
        mostrartablapuntofijo(i,x,fx);
        guardartablapuntofijolatex(archivo,i,x,fx);
        x = fx + x;
        i++;
    }while(fabs(fx) > objetivo);

    fprintf(archivo,"\\end{tabular}\n");
    fprintf(archivo,"\\end{center}\n");
    fclose(archivo);
}

void mostrartablapuntofijo(int i,double x, double fx)
{
    printf("%d\t%.11g\t%.11g\n",i,x,fx);
}

void guardartablapuntofijolatex(FILE* archivo,int i, double x, double fx)
{
    fprintf(archivo,"%d & %.11g & %.11g \\\\\n",i,x,fx);
}