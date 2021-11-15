#include "../include/secante.h"
#include "../include/funciones.h"

void metodosecante(char nombre[],double x0,double x1, double objetivo)
{
    double fx0, fx1,x2;
    int i = 0,max_it=50;
    FILE* archivo = fopen(nombre,"w+");
    
    fprintf(archivo,"\\begin{center}\n");
    fprintf(archivo,"\\begin{tabular}{c c c c}\n");
    fprintf(archivo,"it & $x_i$ & $x_{i-1}$ & $f(x_i)$\\\\\n");
    printf("it\tx_i\t\t\tx_{i-1}\t\t\tf(x_i)\n");
    
    do{
        fx0 = cosx_minus_x(x0);
        fx1 = cosx_minus_x(x1);
        printf("%d\t%.13g\t\t%.13g\t\t%.13g\n",i++,x1,x0,fx1);
        guardartablasecantelatex(archivo,i,x1,x0,fx1);
        x2 = x1 - ((x1 - x0)/(fx1 - fx0))*fx1;
        x0 = x1;
        x1 = x2;
    }while(fabs(fx1) > objetivo && i<max_it);
    
    fprintf(archivo,"\\end{tabular}\n");
    fprintf(archivo,"\\end{center}\n");
    fclose(archivo);
}

void guardartablasecantelatex(FILE* archivo,int i, double x1,double x0, double fx)
{
    fprintf(archivo,"%d & %.13g & %.13g & %.13g \\\\\n",i,x1,x0,fx); 
}