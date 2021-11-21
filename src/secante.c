#include "../include/secante.h"
#include "../include/funciones.h"
#include <stdio.h>

int metodosecante(double x0,double x1, double objetivo, double calculos [][3],int maxit)
{
    double fx0, fx1,x2;
    int i = 0;
    
    do{
        fx0 = cosx_minus_x(x0);
        fx1 = cosx_minus_x(x1);
        actualizartablasecante(calculos, i++, x1, x0,fx1);
        x2 = x1 - ((x1 - x0)/(fx1 - fx0))*fx1;
        x0 = x1;
        x1 = x2;
    }while(fabs(fx1) > objetivo && i<maxit);
    return i;
}

void actualizartablasecante(double calculos[][3],int i, double x1, double x0, double fx1)
{
    calculos[i][0] = x1;
    calculos[i][1] = x0;
    calculos[i][2] = fx1;
}

void mostrartablasecante(double calculos[][3],int n,int cifras_significativas)
{
    int i;
    switch (cifras_significativas) 
    {
        case 13:
        {
            printf("it\tx_i\t\t\tx_{i-1}\t\t\tf(x_i)\n");
            for(i=0;i < n; i++)
            {
                printf("%d\t%-8.13g\t\t%-8.13g\t\t%-8.13g\n",i+1,calculos[i][0],calculos[i][1],calculos[i][2]);
            }
            break;
        }

        default:
        {
            printf("it\tx_i\t\t\tx_{i-1}\t\t\tf(x_i)\n");
            for(i=0;i < n; i++)
            {
                printf("%d\t%-8.10g\t\t%-8.10g\t\t%-8.10g\n",i+1,calculos[i][0],calculos[i][1],calculos[i][2]);
            }
            break;
        }
    }
}

void guardartablasecantelatex(double calculos[][3],int n,int cifras_significativas, char nombre[])
{
    int i;
    FILE* archivo = fopen(nombre,"w+");

    fprintf(archivo,"\\begin{center}\n");
    fprintf(archivo,"\\begin{tabular}{c c c c}\n");
    fprintf(archivo,"it & $x_i$ & $x_{i-1}$ & $f(x_i)$\\\\\n");

    switch (cifras_significativas) 
    {
        case 13:
        {
            for(i=0;i < n; i++)
            {
                fprintf(archivo,"%d & %.13g & %.13g & %.13g\\\\\n",i+1,calculos[i][0],calculos[i][1],calculos[i][2]);
            }
            break;
        }

        default:
        {
            for(i=0;i < n; i++)
            {
                fprintf(archivo,"%d & %.10g & %.10g & %.10g\\\\\n",i+1,calculos[i][0],calculos[i][1],calculos[i][2]);
            }
            break;
        }
    } 

    fprintf(archivo,"\\end{tabular}\n");
    fprintf(archivo,"\\end{center}\n");
    fclose(archivo);
}

void guardarmegatablasecante(double totalcalculos[][16], int n, int cifras_significativas, char nombre[])
{
    int i;
    FILE* archivo = fopen(nombre, "w+");
    
    switch(cifras_significativas)
    {
        case 14:
        {
            fprintf(archivo,"it\t\tBi\t\t\t\t\t\t\t  Gi\t\t\t\t\t\t\tf(xi)\t\t\t\t\t\t");  
            fprintf(archivo,"  Bi\t\t\t\t\t\t\tAi\t\t\t\t\t\t\t  f(xi)\t\t\t\t\t\t\tAi\t\t\t\t\t\t\t  Gi\t\t\t\t\t\t\t");
            fprintf(archivo,"f(xi)\t\t\t\t\t\t  Bi\t\t\t\t\t\t\tbi\t\t\t\t\t\t\t  f(xi)\t\t\t\t\t\t\tbi\t\t\t\t\t\t\t");
            fprintf(archivo,"  Gi\t\t\t\t\t\t\tf(xi)\t\t\t\t\t\t\n");
            // printf(archivo,"it\t\tBi\t\t\t\t\t\t\t  Gi\t\t\t\t\t\t\tBGdiff\t\t\t\t\t\t");  
            // fprintf(archivo,"  Bi\t\t\t\t\t\t\tAi\t\t\t\t\t\t\t  BAdiff\t\t\t\t\t\tAi\t\t\t\t\t\t\t  Gi\t\t\t\t\t\t\t");
            // fprintf(archivo,"AGdiff\t\t\t\t\t\t  Bi\t\t\t\t\t\t\tbi\t\t\t\t\t\t\t  Bbdiff\t\t\t\t\t\tbi\t\t\t\t\t\t\t");
            // fprintf(archivo,"  Gi\t\t\t\t\t\t\tbGdiff\t\t\t\t\t\t\n");
            for(i=0;i < n; i++)
            {
                fprintf(archivo,"%d\t\t%-30.14g%-30.14g%-30.14g%-30.14g%-30.14g%-30.14g%-30.14g%-30.14g%-30.14g%-30.14g%-30.14g%-30.14g%-30.14g%-30.14g%-30.14g\n",i,totalcalculos[i][1],totalcalculos[i][2],totalcalculos[i][3],
                totalcalculos[i][4],totalcalculos[i][5],totalcalculos[i][6],totalcalculos[i][7],totalcalculos[i][8],
                totalcalculos[i][9],totalcalculos[i][10],totalcalculos[i][11],totalcalculos[i][12],totalcalculos[i][13],totalcalculos[i][14],totalcalculos[i][15]);
            }
            break;
        }

        default:
        {
           fprintf(archivo,"it\t\tBi\t\t\t\t\t\t\t  Gi\t\t\t\t\t\t\tBGdiff\t\t\t\t\t\t");  
            fprintf(archivo,"Bi\t\t\t\t\t\t\tAi\t\t\t\t\t\t  BAdiff\t\t\t\t\t\t\tAi\t\t\t\t\t\t\t  Gi\t\t\t\t\t\t\t");
            fprintf(archivo,"AGdiff\t\t\t\t\t\t  Bi\t\t\t\t\t\t\tbi\t\t\t\t\t\t  Bbdiff\t\t\t\t\t\t bi\t\t\t\t\t\t\t");
            fprintf(archivo,"Gi\t\t\t\t\t\tbGdiff\t\t\t\t\t\t\n");
            for(i=0;i < n; i++)
            {
                fprintf(archivo,"%d\t\t%-30.13g%-30.13g%-30.13g%-30.13g%-30.13g%-30.13g%-30.13g%-30.13g%-30.13g%-30.13g%-30.13g%-30.13g%-30.13g%-30.13g%-30.13g\n",i,totalcalculos[i][1],totalcalculos[i][2],totalcalculos[i][3],
                totalcalculos[i][4],totalcalculos[i][5],totalcalculos[i][6],totalcalculos[i][7],totalcalculos[i][8],
                totalcalculos[i][9],totalcalculos[i][10],totalcalculos[i][11],totalcalculos[i][12],totalcalculos[i][13],totalcalculos[i][14],totalcalculos[i][15]);
            }
            break;
        }
    }
    fclose(archivo);
}

void guardarmegatablasecantelatex(double totalcalculos[][16], int n, int cifras_significativas, char nombre[])
{
    int i;
    FILE* archivo = fopen(nombre, "w+");
    fprintf(archivo, "\\newgeometry{left=2 mm,top=2 mm,right=2 mm, bottom= 2 mm}\n");
    fprintf(archivo, "\\begin{sidewaysfigure}\n");
    fprintf(archivo, "\\tiny\n");
    fprintf(archivo, "\\begin{center}\n");
    fprintf(archivo,"\\begin{tabular}{|c|c|c|c|c|c|c|c|c|c|c|c|c|c|c|c|}\n");
    fprintf(archivo,"\\hline\n");
    fprintf(archivo,"&  \\multicolumn{15}{|c|}{Condición Inicial}\\\\\n");
    fprintf(archivo,"\\hline\n");
    fprintf(archivo, "& \\multicolumn{3}{|c|}{$x_1 = \\beta_j, x_0 = \\gamma_j$} & \\multicolumn{3}{|c|}{$x_1 = \\beta_j, x_0 = \\alpha_j$} & \\multicolumn{3}{|c|}{$x_1 = \\alpha_j, x_0 = \\gamma_j$} & \\multicolumn{3}{|c|}{$x_1 = \\beta_j, x_0 = b_j$} & \\multicolumn{3}{|c|}{$x_1 = b_j, x_0 = \\gamma_j$}\\\\\n");
    fprintf(archivo,"\\hline\n");
    fprintf(archivo,"Iteración & $x_i$ & $x_{i-1}$ & $f(x_i)$ & $x_i$ & $x_{i-1}$ & $f(x_i)$ & $x_i$ & $x_{i-1}$ & $f(x_i)$ & $x_i$ & $x_{i-1}$ & $f(x_i)$ & $x_i$ & $x_{i-1}$ & $f(x_i)$\\\\\n");
    switch(cifras_significativas)
    {
        case 14:
        {
            for(i=0;i < n; i++)
            {
                fprintf(archivo,"\\hline\n");
                fprintf(archivo,"%d & %.14g & %.14g & %.14g & %.14g & %.14g & %.14g & %.14g & %.14g & %.14g & %.14g & %.14g & %.14g & %.14g & %.14g & %.14g\\\\\n",i,totalcalculos[i][1],totalcalculos[i][2],totalcalculos[i][3],
                totalcalculos[i][4],totalcalculos[i][5],totalcalculos[i][6],totalcalculos[i][7],totalcalculos[i][8],
                totalcalculos[i][9],totalcalculos[i][10],totalcalculos[i][11],totalcalculos[i][12],totalcalculos[i][13],totalcalculos[i][14],totalcalculos[i][15]);
            }
            break;
        }

        default:
        {
            for(i=0;i < n; i++)
            {
                fprintf(archivo,"\\hline\n");
                fprintf(archivo,"%d & %.13g & %.13g & %.13g & %.13g & %.13g & %.13g & %.13g & %.13g & %.13g & %.13g & %.13g & %.13g & %.13g & %.13g & %.13g\\\\\n",i,totalcalculos[i][1],totalcalculos[i][2],totalcalculos[i][3],
                totalcalculos[i][4],totalcalculos[i][5],totalcalculos[i][6],totalcalculos[i][7],totalcalculos[i][8],
                totalcalculos[i][9],totalcalculos[i][10],totalcalculos[i][11],totalcalculos[i][12],totalcalculos[i][13],totalcalculos[i][14],totalcalculos[i][15]);
            }
            break;
        }
    }   
    fprintf(archivo,"\\hline\n");
    fprintf(archivo,"\\end{tabular}\n");
    fprintf(archivo,"\\end{center}\n");
    fprintf(archivo,"\\end{sidewaysfigure}\n");
    fprintf(archivo,"\\clearpage\n");
    fprintf(archivo,"\\restoregeometry\n");
    fclose(archivo);
}