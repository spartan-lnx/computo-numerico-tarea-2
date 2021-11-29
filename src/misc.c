#include "../include/misc.h"
#include "../include/main.h"
#include "../include/funciones.h"
#include <stdio.h>

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

void rellenarcerostablamuller(double totalcalculos[][17],int i,int maxit,int l,int m,int n,int o)
{
    int j;
    for(j=i;j<maxit;j++)
    {
        totalcalculos[j][0] = j;
        totalcalculos[j][l] = 0;
        totalcalculos[j][m] = 0;
        totalcalculos[j][n] = 0;
        totalcalculos[j][o] = 0;
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

void mostrartablanovenogrado(int n,double calculos[][3])
{
    int i;

    printf("Metodo Tradicional\t\t\tMetodo Horner\n");
    printf("it\txk\t\tf(xk)\t\tf(xk)\n");
    for(i=0; i < n;i++)
    {
        printf("%d\t%-10.6g\t%-10.6g\t%-10.6g\n",i,calculos[i][0],calculos[i][1],calculos[i][2]);
    }
}

void guardartablanovenogradolatex(int n,double calculos[][3],char nombre[])
{
    int i;
    FILE* archivo = fopen(nombre,"w+");

    fprintf(archivo,"\\begin{center}\n");
    fprintf(archivo,"\\begin{tabular}{c c c c}\n");
    fprintf(archivo,"it & $x_k$ & $f(x_k)$ & $h(x_k)$\\\\\n");
    for(i=0; i < n;i++)
    {
        fprintf(archivo,"%d & %.6g & %.6g & %.6g\\\\\n",i,calculos[i][0],calculos[i][1],calculos[i][2]);
    }
    fprintf(archivo,"\\end{tabular}\n");
    fprintf(archivo,"\\end{center}\n");
    fclose(archivo);
}