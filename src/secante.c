#include "../include/secante.h"
#include "../include/funciones.h"

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