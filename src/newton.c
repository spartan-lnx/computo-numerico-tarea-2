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
            printf("it\txi\t\t\t\tfxi\n");
            for(i = 0; i < n; i++)
            {
                printf("%d\t%-16.14g\t\t%-16.14g\n",i,calculos[i][0],calculos[i][1]);
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

void guardarmegatablanewton(double totalcalculos[][13],int n, int cifras_significativas,char nombre[])
{
    int i;
    FILE* archivo = fopen(nombre, "w+");
    switch(cifras_significativas)
    {
        case 13:
        {
            fprintf(archivo,"it\t\tBxi\t\t\t\t\t\t\t  Bfxi\t\t\t\t\t\t\tBdiff\t\t\t\t\t\t  Gxi\t\t\t\t\t\t\tGfxi\t\t\t\t\t\t  Gdiff\t\t\t\t\t\t\tAxi\t\t\t\t\t\t\t  Afxi\t\t\t\t\t\t\tAdiff\t\t\t\t\t\t  bxi\t\t\t\t\t\t\tbfxi\t\t\t\t\t\t  bdiff\n");
            for(i = 0; i < n; i++)
            {
                fprintf(archivo,"%d\t\t%-30.13g%-30.13g%-30.13g%-30.13g%-30.13g%-30.13g%-30.13g%-30.13g%-30.13g%-30.13g%-30.13g%-30.13g\n",i,totalcalculos[i][1],totalcalculos[i][2],totalcalculos[i][3],
                totalcalculos[i][4],totalcalculos[i][5],totalcalculos[i][6],totalcalculos[i][7],totalcalculos[i][8],
                totalcalculos[i][9],totalcalculos[i][10],totalcalculos[i][11],totalcalculos[i][12]);
            }
            break;
        }
        case 14:
        {
            fprintf(archivo,"it\t\tBxi\t\t\t\t\t\t\t  Bfxi\t\t\t\t\t\t\tBdiff\t\t\t\t\t\t  Gxi\t\t\t\t\t\t\tGfxi\t\t\t\t\t\t  Gdiff\t\t\t\t\t\t\tAxi\t\t\t\t\t\t\t  Afxi\t\t\t\t\t\t\tAdiff\t\t\t\t\t\t  bxi\t\t\t\t\t\t\tbfxi\t\t\t\t\t\t  bdiff\n");
            for(i = 0; i < n; i++)
            {
                fprintf(archivo,"%d\t\t%-30.14g%-30.14g%-30.14g%-30.14g%-30.14g%-30.14g%-30.14g%-30.14g%-30.14g%-30.14g%-30.14g%-30.14g\n",i,totalcalculos[i][1],totalcalculos[i][2],totalcalculos[i][3],
                totalcalculos[i][4],totalcalculos[i][5],totalcalculos[i][6],totalcalculos[i][7],totalcalculos[i][8],
                totalcalculos[i][9],totalcalculos[i][10],totalcalculos[i][11],totalcalculos[i][12]);
            }
            break;
        }
        default:
        {
            fprintf(archivo,"it\t\tBxi\t\t\t\t\t\t\t  Bfxi\t\t\t\t\t\t\tBdiff\t\t\t\t\t\t  Gxi\t\t\t\t\t\t\tGfxi\t\t\t\t\t\t  Gdiff\t\t\t\t\t\t\tAxi\t\t\t\t\t\t\t  Afxi\t\t\t\t\t\t\tAdiff\t\t\t\t\t\t  bxi\t\t\t\t\t\t\tbfxi\t\t\t\t\t\t  bdiff\n");
            for(i = 0; i < n; i++)
            {
                fprintf(archivo,"%d\t\t%-30.10g%-30.10g%-30.10g%-30.10g%-30.10g%-30.10g%-30.10g%-30.10g%-30.10g%-30.10g%-30.10g%-30.10g\n",i,totalcalculos[i][1],totalcalculos[i][2],totalcalculos[i][3],
                totalcalculos[i][4],totalcalculos[i][5],totalcalculos[i][6],totalcalculos[i][7],totalcalculos[i][8],
                totalcalculos[i][9],totalcalculos[i][10],totalcalculos[i][11],totalcalculos[i][12]);
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

void guardarmegatablanewtonlatex(double totalcalculos[][13],int n, int cifras_significativas,char nombre[])
{
int i;
    FILE* archivo = fopen(nombre, "w+");

    fprintf(archivo, "\\begin{center}\n");
    fprintf(archivo,"\\begin{tabular}{|c|c|c|c|c|c|c|c|c|c|c|c|c|}\n");
    fprintf(archivo,"\\hline\n");
    fprintf(archivo,"&  \\multicolumn{9}{|c|}{Condición Inicial}\\\\\n");
    fprintf(archivo,"\\hline\n");
    fprintf(archivo, "& \\multicolumn{3}{|c|}{$\\beta_i$} & \\multicolumn{2}{|c|}{$\\gamma_i$} & \\multicolumn{2}{|c|}{$\\alpha_i$} & \\multicolumn{2}{|c|}{$b_i$}\\\\");
    fprintf(archivo,"\\hline\n");
    fprintf(archivo,"Iteración & $x_k$ & $f_k$ & $|x_{k+1}-x_k|$ & $x_k$ & $\\ldots$ & $x_k$ & $\\ldots$ & $x_k$ & $\\ldots$ \\\\");

    switch(cifras_significativas)
    {
        case 13:
        {
            for(i = 0; i < n; i++)
            {
                fprintf(archivo,"\\hline\n");
                fprintf(archivo,"%d & %.13g & %.13g & %.13g & %.13g & %.13g & %.13g & %.13g & %.13g & %.13g & %.13g & %.13g & %.13g\\\\\n",i,totalcalculos[i][1],totalcalculos[i][2],totalcalculos[i][3],
                totalcalculos[i][4],totalcalculos[i][5],totalcalculos[i][6],totalcalculos[i][7],totalcalculos[i][8],
                totalcalculos[i][9],totalcalculos[i][10],totalcalculos[i][11],totalcalculos[i][12]);
            }
            break;
        }
        case 14:
        {
            for(i = 0; i < n; i++)
            {
                fprintf(archivo,"\\hline\n");
                fprintf(archivo,"%d & %.14g & %.14g & %.14g & %.14g & %.14g & %.14g & %.14g & %.14g & %.14g & %.14g & %.14g & %.14g\\\\\n",i,totalcalculos[i][1],totalcalculos[i][2],totalcalculos[i][3],
                totalcalculos[i][4],totalcalculos[i][5],totalcalculos[i][6],totalcalculos[i][7],totalcalculos[i][8],
                totalcalculos[i][9],totalcalculos[i][10],totalcalculos[i][11],totalcalculos[i][12]);
            }
            break;
        }
        default:
        {
            for(i = 0; i < n; i++)
            {
                fprintf(archivo,"\\hline\n");
                fprintf(archivo,"%d & %.10g & %.10g & %.10g & %.10g & %.10g & %.10g & %.10g & %.10g & %.10g & %.10g & %.10g & %.10g\\\\\n",i,totalcalculos[i][1],totalcalculos[i][2],totalcalculos[i][3],
                totalcalculos[i][4],totalcalculos[i][5],totalcalculos[i][6],totalcalculos[i][7],totalcalculos[i][8],
                totalcalculos[i][9],totalcalculos[i][10],totalcalculos[i][11],totalcalculos[i][12]);
            }
            break;
        }
    }

    fprintf(archivo,"\\hline\n");
    fprintf(archivo,"\\end{tabular}\n");
    fprintf(archivo,"\\end{center}\n");
    fclose(archivo);
}