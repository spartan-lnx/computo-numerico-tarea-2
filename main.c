#include "include/main.h"
#include "include/biseccion.h"
#include "include/puntofijo.h"
#include "include/newton.h"
#include "include/secante.h"
#include "include/horner.h"
#include "include/misc.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void playgroundbiseccion(void);
void playgroundpuntofijo(void);
void playgroundsecante(void);
void playgroundnewton(void);
void playgroundnewton3b(void);
void playgroundsecante3b(void);
void playgroundhorner(void);


int main(void)
{
    //playgroundbiseccion();
    //playgroundpuntofijo();   
    //playgroundsecante();
    //playgroundnewton();
    //playgroundnewton3b();
    //playgroundsecante3b();
    playgroundhorner();
    return 0;
}


void playgroundbiseccion(void)
{
    double calculos[MAXIT64][4];
    int n;

    n = metodobiseccion(ALPHA1, ALPHA2, OBJETIVO, FUNCIONFACIL, calculos, MAXIT64);

    mostrartablabiseccion(calculos, n, 11);
    guardartablabiseccionlatex(calculos, n, 11, "pruebabiseccion.txt");
}

void playgroundpuntofijo(void)
{
    double calculos[MAXIT64][2];
    int n;

    n = metodopuntofijo(ALPHA1, OBJETIVO, calculos, MAXIT64);
    mostrartablapuntofijo(calculos, n,11);
    guardartablapuntofijolatex(calculos, n, 11, "pruebapuntofijo.txt");
}

void playgroundsecante(void)
{
    double calculos[MAXIT64][3];
    int n;

    n = metodosecante(ALPHA1,ALPHA2,OBJETIVO,calculos,MAXIT64);
    mostrartablasecante(calculos, n, 13);
    guardartablasecantelatex(calculos,n,13,"pruebasecante.txt");
}

void playgroundnewton(void)
{
    double calculos[MAXIT64][2];
    int n;

    n = metodonewton(calculos, ALPHA2, OBJETIVO, EXACTA, EPSILON1, MAXIT64);
    mostrartablanewton(calculos, n, 13);
    guardartablanewtonlatex(calculos, n, 13, "pruebanewton.txt");
}

void playgroundnewton3b(void)
{
    int variante = EXACTAFUNCIONDIFICIL;
    int maxit = MAXIT64;
    double objetivo = OBJETIVO;
    int i,j,nbeta,ngamma,nalpha,nb;

    double beta[5] = {-3,-2,-2,-1,1},gamma[5] = {-2,-1,-1,0,2};
    double alpha[5] = {-2.2,-1.6,-1.4,-0.76,1.76},b[5] = {-2.25,-1.65,-1.45,-0.81,1.65};

    double calculosraiz_j[maxit][13];
    double calculosbeta[maxit][2],calculosgamma[maxit][2],calculosalpha[maxit][2];
    double calculosb[maxit][2];

    char nombretabla[90];
    char nombretablalatex[90];
    char buffer[20];

    for(j=0;j<5;j++)
    {
        nbeta = metodonewton(calculosbeta, beta[j],objetivo,variante,0,maxit);
        ngamma = metodonewton(calculosgamma, gamma[j],objetivo,variante,0,maxit);
        nalpha = metodonewton(calculosalpha, alpha[j],objetivo,variante,0,maxit);
        nb = metodonewton(calculosb, b[j],objetivo,variante,0,maxit);

        for(i = 0;i < nbeta;i++)
        {
            calculosraiz_j[i][0] = i;
            calculosraiz_j[i][1] = calculosbeta[i][0];
            calculosraiz_j[i][2] = calculosbeta[i][1];
            calculosraiz_j[i][3] = fabs(calculosbeta[i+1][0] - calculosbeta[i][0]); //cuidado con el ultimo
        }

        if(i < maxit)
        {
            rellenarcerostabla(calculosraiz_j,i,maxit,1,2,3);
        }

        for(i = 0;i < ngamma;i++)
        {
            calculosraiz_j[i][0] = i;
            calculosraiz_j[i][4] = calculosgamma[i][0];
            calculosraiz_j[i][5] = calculosgamma[i][1];
            calculosraiz_j[i][6] = fabs(calculosgamma[i+1][0] - calculosgamma[i][0]); //cuidado con el ultimo
        }

        if(i < maxit)
        {
            rellenarcerostabla(calculosraiz_j,i,maxit,4,5,6);
        }

        for(i = 0;i < nalpha;i++)
        {
            calculosraiz_j[i][0] = i;
            calculosraiz_j[i][7] = calculosalpha[i][0];
            calculosraiz_j[i][8] = calculosalpha[i][1];
            calculosraiz_j[i][9] = fabs(calculosalpha[i+1][0] - calculosalpha[i][0]); //cuidado con el ultimo
        }

        if(i < maxit)
        {
            rellenarcerostabla(calculosraiz_j,i,maxit,7,8,9);
        }

        for(i = 0;i < nb;i++)
        {
            calculosraiz_j[i][0] = i;
            calculosraiz_j[i][10] = calculosb[i][0];
            calculosraiz_j[i][11] = calculosb[i][1];
            calculosraiz_j[i][12] = fabs(calculosb[i+1][0] - calculosb[i][0]); //cuidado con el ultimo
        }

        if(i < maxit)
        {
            rellenarcerostabla(calculosraiz_j,i,maxit,10,11,12);
        }
        
        sprintf(buffer,"%d",j+1);
        strcat(nombretabla, "megatabla");
        strcat(nombretabla, buffer);
        strcat(nombretablalatex, nombretabla);
        strcat(nombretabla, ".txt");
        strcat(nombretablalatex, "latex");
        strcat(nombretablalatex, ".txt");

        guardarmegatablanewton(calculosraiz_j, maxit, 14,nombretabla);
        guardarmegatablanewtonlatex(calculosraiz_j, maxit, 14,nombretablalatex);

        strcpy(nombretabla, "");
        strcpy(nombretablalatex, "");
        strcpy(buffer, "");
    }
}

void playgroundsecante3b(void)
{
    int maxit = MAXIT64;
    double objetivo = OBJETIVO;
    int i,j,nbetagamma,nbetaalpha,nalphagamma,nbetab,nbgamma;

    double beta[5] = {-3,-2,-2,-1,1},gamma[5] = {-2,-1,-1,0,2};
    double alpha[5] = {-2.2,-1.6,-1.4,-0.76,1.76},b[5] = {-2.25,-1.65,-1.45,-0.81,1.65};

    double calculosraiz_j[maxit][16];
    double calculosbetagamma[maxit][3],calculosbetaalpha[maxit][3],calculosalphagamma[maxit][3];
    double calculosbetab[maxit][3],calculosbgamma[maxit][3];

    char nombretabla[90];
    char nombretablalatex[90];
    char buffer[20];

    for(j=0;j<5;j++)
    {
        nbetagamma = metodosecante(beta[j], gamma[j], objetivo, calculosbetagamma, maxit);
        nbetaalpha = metodosecante(beta[j], alpha[j], objetivo, calculosbetaalpha, maxit);
        nalphagamma = metodosecante(alpha[j], gamma[j], objetivo, calculosalphagamma, maxit);
        nbetab = metodosecante(beta[j], b[j], objetivo, calculosbetab, maxit);
        nbgamma = metodosecante(b[j], gamma[j], objetivo, calculosbgamma, maxit);

        for(i=0;i<nbetagamma;i++)
        {
            calculosraiz_j[i][0] = i;
            calculosraiz_j[i][1] = calculosbetagamma[i][0];
            calculosraiz_j[i][2] = calculosbetagamma[i][1];
            calculosraiz_j[i][3] = calculosbetagamma[i][2];
        }

        if(i < maxit)
        {
            rellenarcerostablasecante(calculosraiz_j,i,maxit,1,2,3);
        }

        /////////////////////////////////////////////////////////////////////////////

        for(i=0;i<nbetaalpha;i++)
        {
            calculosraiz_j[i][0] = i;
            calculosraiz_j[i][4] = calculosbetaalpha[i][0];
            calculosraiz_j[i][5] = calculosbetaalpha[i][1];
            calculosraiz_j[i][6] = calculosbetaalpha[i][2];
        }

        if(i < maxit)
        {
            rellenarcerostablasecante(calculosraiz_j,i,maxit,4,5,6);
        }

        /////////////////////////////////////////////////////////////////////////////

        for(i=0;i<nalphagamma;i++)
        {
            calculosraiz_j[i][0] = i;
            calculosraiz_j[i][7] = calculosalphagamma[i][0];
            calculosraiz_j[i][8] = calculosalphagamma[i][1];
            calculosraiz_j[i][9] = calculosalphagamma[i][2];
        }

        if(i < maxit)
        {
            rellenarcerostablasecante(calculosraiz_j,i,maxit,7,8,9);
        }
    
        /////////////////////////////////////////////////////////////////////////////

        for(i=0;i<nbetab;i++)
        {
            calculosraiz_j[i][0] = i;
            calculosraiz_j[i][10] = calculosbetab[i][0];
            calculosraiz_j[i][11] = calculosbetab[i][1];
            calculosraiz_j[i][12] = calculosbetab[i][2];
        }

        if(i < maxit)
        {
            rellenarcerostablasecante(calculosraiz_j,i,maxit,10,11,12);
        }

        /////////////////////////////////////////////////////////////////////////////

        for(i=0;i<nbgamma;i++)
        {
            calculosraiz_j[i][0] = i;
            calculosraiz_j[i][13] = calculosbgamma[i][0];
            calculosraiz_j[i][14] = calculosbgamma[i][1];
            calculosraiz_j[i][15] = calculosbgamma[i][2];
        }

        if(i < maxit)
        {
            rellenarcerostablasecante(calculosraiz_j,i,maxit,13,14,15);
        }

        sprintf(buffer,"%d",j+1);
        strcat(nombretabla, "megatabla");
        strcat(nombretabla, buffer);
        strcat(nombretablalatex, nombretabla);
        strcat(nombretabla, ".txt");
        strcat(nombretablalatex, "latex");
        strcat(nombretablalatex, ".txt");

        guardarmegatablasecante(calculosraiz_j, maxit, 14, nombretabla);
        guardarmegatablasecantelatex(calculosraiz_j, maxit, 14, nombretablalatex);

        strcpy(nombretabla, "");
        strcpy(nombretablalatex, "");
        strcpy(buffer, "");
    }
}

void playgroundhorner(void)
{
    int k,n=81;
    double xk,fxk,fxkh;
    double resultados[n][3];
    int coef[10] = {756,2448,1605,-2583,-4705,-2069,1643,1773,-20,-300};
    for(k=0;k<n;k++)
    {
        xk = -4 + ((double)k/10);
        fxk = funcionnovenogrado(xk);
        fxkh = metodohorner(coef, xk, 10);
        resultados[k][0] = xk;
        resultados[k][1] = fxk;
        resultados[k][2] = fxkh;
    }

    mostrartablanovenogrado(n,resultados);
    guardartablanovenogradolatex(n, resultados, "tablahorner.txt");
}