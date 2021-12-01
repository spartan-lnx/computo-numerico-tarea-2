#include "include/main.h"
#include "include/biseccion.h"
#include "include/puntofijo.h"
#include "include/newton.h"
#include "include/secante.h"
#include "include/muller.h"
#include "include/horner.h"
#include "include/misc.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void playgroundbiseccion(void);
void playgroundpuntofijo(void);
void playgroundsecante(void);
void playgroundnewton(void);
void playgroundmuller(void);
void playgroundbiseccion3b(void);
void playgroundnewton3b(void);
void playgroundsecante3b(void);
void playgroundmuller3b(void);
void playgroundhorner(void);
void playgroundejercicio4(void);


int main(void)
{
    //playgroundbiseccion(); //completado
    //playgroundpuntofijo(); //completado
    //playgroundsecante(); //completado
    //playgroundnewton(); //completado
    //playgroundbiseccion3b(); //completado
    //playgroundnewton3b(); //completado
    //playgroundsecante3b(); //completado
    //playgroundmuller3b(); //completado
    //playgroundhorner(); //completado
    playgroundejercicio4();
    return 0;
}


void playgroundbiseccion(void)
{
    double calculos[MAXIT100][4];
    double objetivo = 0.00000000001;
    int n;

    n = metodobiseccion(ALPHA1, ALPHA2, objetivo, FUNCIONFACIL, calculos, MAXIT100);
    mostrartablabiseccion(calculos, n, 11);
    guardartablabiseccionlatex(calculos, n, 11, "biseccionalpha1alpha2.txt");

    n = metodobiseccion(ALPHA1, ALPHA3, objetivo, FUNCIONFACIL, calculos, MAXIT100);
    mostrartablabiseccion(calculos, n, 11);
    guardartablabiseccionlatex(calculos, n, 11, "biseccionalpha1alpha3.txt");
}

void playgroundpuntofijo(void)
{
    double calculos[MAXIT100][2];
    double objetivo = 0.00000000001;
    int n;

    n = metodopuntofijo(ALPHA1, objetivo, calculos, MAXIT100);
    mostrartablapuntofijo(calculos, n,11);
    guardartablapuntofijolatex(calculos, n, 11, "puntofijoalpha1.txt");

    n = metodopuntofijo(ALPHA2, objetivo, calculos, MAXIT100);
    mostrartablapuntofijo(calculos, n,11);
    guardartablapuntofijolatex(calculos, n, 11, "puntofijoalpha2.txt");

    n = metodopuntofijo(ALPHA3, objetivo, calculos, MAXIT100);
    mostrartablapuntofijo(calculos, n,11);
    guardartablapuntofijolatex(calculos, n, 11, "puntofijoalpha3.txt");
}

void playgroundsecante(void)
{
    double calculos[MAXIT100][3];
    double objetivo = 0.0000000000001;
    int n;

    n = metodosecante(ALPHA1,ALPHA2,objetivo,calculos,MAXIT100);
    mostrartablasecante(calculos, n, 13);
    guardartablasecantelatex(calculos,n,13,"secantealpha1alpha2.txt");

    n = metodosecante(ALPHA1,ALPHA3,objetivo,calculos,MAXIT100);
    mostrartablasecante(calculos, n, 13);
    guardartablasecantelatex(calculos,n,13,"secantealpha1alpha3.txt");

    n = metodosecante(ALPHA2,ALPHA3,objetivo,calculos,MAXIT100);
    mostrartablasecante(calculos, n, 13);
    guardartablasecantelatex(calculos,n,13,"secantealpha2alpha3.txt");
}

void playgroundnewton(void)
{
    double calculos[MAXIT100][2];
    double objetivo = 0.0000000000001;
    int n;

    n = metodonewton(calculos, ALPHA1, objetivo, EXACTA, EPSILON1, MAXIT100);
    mostrartablanewton(calculos, n, 13);
    guardartablanewtonlatex(calculos, n, 13, "newtonexactaalpha1.txt"); //no converge por errores de redondeo

    n = metodonewton(calculos, ALPHA2, objetivo, EXACTA, EPSILON1, MAXIT100);
    mostrartablanewton(calculos, n, 13);
    guardartablanewtonlatex(calculos, n, 13, "newtonexactaalpha2.txt");

    n = metodonewton(calculos, ALPHA3, objetivo, EXACTA, EPSILON1, MAXIT100);
    mostrartablanewton(calculos, n, 13);
    guardartablanewtonlatex(calculos, n, 13, "newtonexactaalpha3.txt");

    //===============================================================================//

    n = metodonewton(calculos, ALPHA1, objetivo, ADELANTE, EPSILON1, MAXIT100);
    mostrartablanewton(calculos, n, 13);
    guardartablanewtonlatex(calculos, n, 13, "newtonadelantealpha1epsilon1.txt");

    n = metodonewton(calculos, ALPHA1, objetivo, DETRAS, EPSILON1, MAXIT100);
    mostrartablanewton(calculos, n, 13);
    guardartablanewtonlatex(calculos, n, 13, "newtondetrasalpha1epsilon1.txt");

    n = metodonewton(calculos, ALPHA1, objetivo, CENTRAL, EPSILON1, MAXIT100);
    mostrartablanewton(calculos, n, 13);
    guardartablanewtonlatex(calculos, n, 13, "newtoncentralalpha1epsilon1.txt");

    //******************************************************************************//

    n = metodonewton(calculos, ALPHA2, objetivo, ADELANTE, EPSILON1, MAXIT100);
    mostrartablanewton(calculos, n, 13);
    guardartablanewtonlatex(calculos, n, 13, "newtonadelantealpha2epsilon1.txt");

    n = metodonewton(calculos, ALPHA2, objetivo, DETRAS, EPSILON1, MAXIT100);
    mostrartablanewton(calculos, n, 13);
    guardartablanewtonlatex(calculos, n, 13, "newtondetrasalpha2epsilon1.txt");

    n = metodonewton(calculos, ALPHA2, objetivo, CENTRAL, EPSILON1, MAXIT100);
    mostrartablanewton(calculos, n, 13);
    guardartablanewtonlatex(calculos, n, 13, "newtoncentralalpha2epsilon1.txt");

    //******************************************************************************//

    n = metodonewton(calculos, ALPHA3, objetivo, ADELANTE, EPSILON1, MAXIT100);
    mostrartablanewton(calculos, n, 13);
    guardartablanewtonlatex(calculos, n, 13, "newtonadelantealpha3epsilon1.txt");

    n = metodonewton(calculos, ALPHA3, objetivo, DETRAS, EPSILON1, MAXIT100);
    mostrartablanewton(calculos, n, 13);
    guardartablanewtonlatex(calculos, n, 13, "newtondetrasalpha3epsilon1.txt");

    n = metodonewton(calculos, ALPHA3, objetivo, CENTRAL, EPSILON1, MAXIT100);
    mostrartablanewton(calculos, n, 13);
    guardartablanewtonlatex(calculos, n, 13, "newtoncentralalpha3epsilon1.txt");

    //===============================================================================//

    n = metodonewton(calculos, ALPHA1, objetivo, ADELANTE, EPSILON2, MAXIT100);
    mostrartablanewton(calculos, n, 13);
    guardartablanewtonlatex(calculos, n, 13, "newtonadelantealpha1epsilon2.txt");

    n = metodonewton(calculos, ALPHA1, objetivo, DETRAS, EPSILON2, MAXIT100);
    mostrartablanewton(calculos, n, 13);
    guardartablanewtonlatex(calculos, n, 13, "newtondetrasalpha1epsilon2.txt");

    n = metodonewton(calculos, ALPHA1, objetivo, CENTRAL, EPSILON2, MAXIT100);
    mostrartablanewton(calculos, n, 13);
    guardartablanewtonlatex(calculos, n, 13, "newtoncentralalpha1epsilon2.txt");

    //******************************************************************************//

    n = metodonewton(calculos, ALPHA2, objetivo, ADELANTE, EPSILON2, MAXIT100);
    mostrartablanewton(calculos, n, 13);
    guardartablanewtonlatex(calculos, n, 13, "newtonadelantealpha2epsilon2.txt");

    n = metodonewton(calculos, ALPHA2, objetivo, DETRAS, EPSILON2, MAXIT100);
    mostrartablanewton(calculos, n, 13);
    guardartablanewtonlatex(calculos, n, 13, "newtondetrasalpha2epsilon2.txt");

    n = metodonewton(calculos, ALPHA2, objetivo, CENTRAL, EPSILON2, MAXIT100);
    mostrartablanewton(calculos, n, 13);
    guardartablanewtonlatex(calculos, n, 13, "newtoncentralalpha2epsilon2.txt");

    //******************************************************************************//

    n = metodonewton(calculos, ALPHA3, objetivo, ADELANTE, EPSILON2, MAXIT100);
    mostrartablanewton(calculos, n, 13);
    guardartablanewtonlatex(calculos, n, 13, "newtonadelantealpha3epsilon2.txt");

    n = metodonewton(calculos, ALPHA3, objetivo, DETRAS, EPSILON2, MAXIT100);
    mostrartablanewton(calculos, n, 13);
    guardartablanewtonlatex(calculos, n, 13, "newtondetrasalpha3epsilon2.txt");

    n = metodonewton(calculos, ALPHA3, objetivo, CENTRAL, EPSILON2, MAXIT100);
    mostrartablanewton(calculos, n, 13);
    guardartablanewtonlatex(calculos, n, 13, "newtoncentralalpha3epsilon2.txt");

    //===============================================================================//

    n = metodonewton(calculos, ALPHA1, objetivo, ADELANTE, EPSILON3, MAXIT100);
    mostrartablanewton(calculos, n, 13);
    guardartablanewtonlatex(calculos, n, 13, "newtonadelantealpha1epsilon3.txt");

    n = metodonewton(calculos, ALPHA1, objetivo, DETRAS, EPSILON3, MAXIT100);
    mostrartablanewton(calculos, n, 13);
    guardartablanewtonlatex(calculos, n, 13, "newtondetrasalpha1epsilon3.txt");

    n = metodonewton(calculos, ALPHA1, objetivo, CENTRAL, EPSILON3, MAXIT100);
    mostrartablanewton(calculos, n, 13);
    guardartablanewtonlatex(calculos, n, 13, "newtoncentralalpha1epsilon3.txt");

    //******************************************************************************//

    n = metodonewton(calculos, ALPHA2, objetivo, ADELANTE, EPSILON3, MAXIT100);
    mostrartablanewton(calculos, n, 13);
    guardartablanewtonlatex(calculos, n, 13, "newtonadelantealpha2epsilon3.txt");

    n = metodonewton(calculos, ALPHA2, objetivo, DETRAS, EPSILON3, MAXIT100);
    mostrartablanewton(calculos, n, 13);
    guardartablanewtonlatex(calculos, n, 13, "newtondetrasalpha2epsilon3.txt");

    n = metodonewton(calculos, ALPHA2, objetivo, CENTRAL, EPSILON3, MAXIT100);
    mostrartablanewton(calculos, n, 13);
    guardartablanewtonlatex(calculos, n, 13, "newtoncentralalpha2epsilon3.txt");

    //******************************************************************************//

    n = metodonewton(calculos, ALPHA3, objetivo, ADELANTE, EPSILON3, MAXIT100);
    mostrartablanewton(calculos, n, 13);
    guardartablanewtonlatex(calculos, n, 13, "newtonadelantealpha3epsilon3.txt");

    n = metodonewton(calculos, ALPHA3, objetivo, DETRAS, EPSILON3, MAXIT100);
    mostrartablanewton(calculos, n, 13);
    guardartablanewtonlatex(calculos, n, 13, "newtondetrasalpha3epsilon3.txt");

    n = metodonewton(calculos, ALPHA3, objetivo, CENTRAL, EPSILON3, MAXIT100);
    mostrartablanewton(calculos, n, 13);
    guardartablanewtonlatex(calculos, n, 13, "newtoncentralalpha3epsilon3.txt");
}

void playgroundmuller(void)
{
    int n;
    double calculos [100][4];
    n = metodomuller(calculos,-3,-2.2,-2,0.00001,100);
    mostrartablamuller(n, calculos, 13);
    guardartablamullerlatex(n, calculos, 13, "mullerbeta1alpha1gamma1.tex");
}

void playgroundmuller3b(void)
{
    int variante = EXACTAFUNCIONDIFICIL;
    int maxit = MAXIT100;
    double objetivo = 0.0000000000001;
    double calculos_raiz_j[100][17];
    double calculosBAG [100][4],calculosBbG[100][4],calculosBAb[100][4],calculosAbG[100][4];
    int i,j,nBAG,nBbG,nBAb,nAbG;
    char nombre[90] = {"megatablamuller0.txt"};
    char nombrelatex[90] = {"megatablamullerlatex0.txt"};
    double beta[5] = {-3,-2,-2,-1,1},gamma[5] = {-2,-1,-1,0,2};
    double alpha[5] = {-2.2,-1.6,-1.4,-0.76,1.7},b[5] = {-2.25,-1.65,-1.45,-0.81,1.65};

    for(j=0;j<5;j++)
    {
        nBAG = metodomuller(calculosBAG,beta[j],alpha[j],gamma[j],objetivo,maxit);
        nBbG = metodomuller(calculosBbG,beta[j],b[j],gamma[j],objetivo,maxit);
        nBAb = metodomuller(calculosBAb,beta[j],alpha[j],b[j],objetivo,maxit);
        nAbG = metodomuller(calculosAbG,alpha[j],b[j],gamma[j],objetivo,maxit);

        for(i=0;i<nBAG;i++)
        {
            calculos_raiz_j[i][0] = i;
            calculos_raiz_j[i][1] = calculosBAG[i][0];
            calculos_raiz_j[i][2] = calculosBAG[i][1];
            calculos_raiz_j[i][3] = calculosBAG[i][2];
            calculos_raiz_j[i][4] = calculosBAG[i][3];
        }

        if(i < maxit)
        {
            rellenarcerostablamuller(calculos_raiz_j,i,maxit,1,2,3,4);
        }

        for(i=0;i<nBbG;i++)
        {
            calculos_raiz_j[i][0] = i;
            calculos_raiz_j[i][5] = calculosBbG[i][0];
            calculos_raiz_j[i][6] = calculosBbG[i][1];
            calculos_raiz_j[i][7] = calculosBbG[i][2];
            calculos_raiz_j[i][8] = calculosBbG[i][3];
        }

        if(i < maxit)
        {
            rellenarcerostablamuller(calculos_raiz_j,i,maxit,5,6,7,8);
        }

        for(i=0;i<nBAb;i++)
        {
            calculos_raiz_j[i][0] = i;
            calculos_raiz_j[i][9] = calculosBAb[i][0];
            calculos_raiz_j[i][10] = calculosBAb[i][1];
            calculos_raiz_j[i][11] = calculosBAb[i][2];
            calculos_raiz_j[i][12] = calculosBAb[i][3];
        }

        if(i < maxit)
        {
            rellenarcerostablamuller(calculos_raiz_j,i,maxit,9,10,11,12);
        }

        for(i=0;i<nAbG;i++)
        {
            calculos_raiz_j[i][0] = i;
            calculos_raiz_j[i][13] = calculosAbG[i][0];
            calculos_raiz_j[i][14] = calculosAbG[i][1];
            calculos_raiz_j[i][15] = calculosAbG[i][2];
            calculos_raiz_j[i][16] = calculosAbG[i][3];
        }

        if(i < maxit)
        {
            rellenarcerostablamuller(calculos_raiz_j,i,maxit,13,14,15,16);
        }

        nombre[15] = j+49;
        nombrelatex[20] = j+49;
        guardarmegatablamuller(calculos_raiz_j,maxit,14,nombre);
        guardarmegatablamullerlatex(calculos_raiz_j,maxit,14,nombrelatex);
    }
}

void playgroundbiseccion3b(void)
{
    double calculos[MAXIT100][4];
    double objetivo = 0.00001;
    char nombre[30]={"biseccionbetagamma0.txt"};
    int n[5],i;
    double beta[5] = {-3,-2,-2,-1,1},gamma[5] = {-2,-1,-1,0,2};
    double alpha[5] = {-2.2,-1.6,-1.4,-0.76,1.7},b[5] = {-2.25,-1.65,-1.45,-0.81,1.65};
    for(i=4;i<5;i++)
    {
        n[i] = metodobiseccion(beta[i],gamma[i], objetivo, FUNCIONDIFICIL, calculos, MAXIT100);
        mostrartablabiseccion(calculos, n[i], 11);
        nombre[18] = i+49;
        guardartablabiseccionlatex(calculos, n[i], 11, nombre);
    }
}

void playgroundnewton3b(void)
{
    int variante = EXACTAFUNCIONDIFICIL;
    int maxit = MAXIT100;
    double objetivo = 0.0000000000001;
    int i,j,nbeta,ngamma,nalpha,nb;

    double beta[5] = {-3,-2,-2,-1,1},gamma[5] = {-2,-1,-1,0,2};
    double alpha[5] = {-2.2,-1.6,-1.4,-0.76,1.7},b[5] = {-2.25,-1.65,-1.45,-0.81,1.65};

    double calculosraiz_j[maxit][13];
    double calculosbeta[maxit][2],calculosgamma[maxit][2],calculosalpha[maxit][2];
    double calculosb[maxit][2];

    char nombretabla[90]={"megatablanewton0.txt"};
    char nombretablalatex[90]={"megatablalatexnewton0.txt"};
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
        nombretabla[15] = j+49;
        nombretablalatex[20] = j+49;
        guardarmegatablanewton(calculosraiz_j, maxit, 14,nombretabla);
        guardarmegatablanewtonlatex(calculosraiz_j, maxit, 14,nombretablalatex);
    }
}

void playgroundsecante3b(void)
{
    int maxit = MAXIT100;
    double objetivo = 0.000000000000000001;
    int i,j,nbetagamma,nbetaalpha,nalphagamma,nbetab,nbgamma;

    double beta[5] = {-3,-2,-2,-1,1},gamma[5] = {-2,-1,-1,0,2};
    double alpha[5] = {-2.2,-1.6,-1.4,-0.76,1.7},b[5] = {-2.25,-1.65,-1.45,-0.81,1.65};

    double calculosraiz_j[maxit][16];
    double calculosbetagamma[maxit][3],calculosbetaalpha[maxit][3],calculosalphagamma[maxit][3];
    double calculosbetab[maxit][3],calculosbgamma[maxit][3];

    char nombretabla[90]={"megatablasecante0.txt"};
    char nombretablalatex[90]={"megatablalatexsecante0.txt"};
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

        nombretabla[16] = j+49;
        nombretablalatex[21]=j+49;
        guardarmegatablasecante(calculosraiz_j, maxit, 14, nombretabla);
        guardarmegatablasecantelatex(calculosraiz_j, maxit, 14, nombretablalatex);
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

void playgroundejercicio4(void)
{
    int coeforig[10] = {756,2448,1605,-2583,-4705,-2069,1643,1773,-20,-300};
    int coefderiv[9] = {6804,19584,11235,-15498,-23525,-8276,4929,3546,-20};
    double fx, fxprime,x,objetivo = 0.000000000001;;
    int i=0, maxit = 100;
    double calculos[100][2];
     
    x = 0.9; //dentro de R1 0.6180339887499 //listo
    //x = -0.9; //dentro de R1 -0.83333336013785 //listo //listo x 2 porque es doble :)
    //x = 3.11; //dentro de R2 1.1547005383793 //listo
    //x = -3.11; //dentro de R2 -1.6180339887499 //listo :))
    //x = -1.15; //dentro de R2 -1.1547005383793 //listo
    //x = 0.45; //dentro de R1 0.42857142857143 //listo
    //x = 1.15; //dentro de R2 1.1547005383793 :(
    //x = 7.22;

// 1.1547005383793
// 0.6180339887499
// 0.42857142857143
// -0.83333336013785 //doble
// -1.6180339887499
// -1.1547005383793


    do{
        fx = metodohorner(coeforig,x,10);
        fxprime = metodohorner(coefderiv,x,9);
        actualizartablanewton(calculos, i++, x, fx);
        x = x - (fx/fxprime);
    }while(fabs(fx) > objetivo && i < maxit);
    mostrartablanewton(calculos,i,14);
    
    double qn[10];
    
    //desinflando el polinomio por pimera vez
    qn[0] = (double)coeforig[0];
    for(i=1;i<=8;i++)
    {
        qn[i] = (double)coeforig[i] + qn[i-1]*x;
    }

    printf("\nmostrando el nuevo polinomio desinflado\n");
    for(i=0;i<9;i++)
    {
        printf("%fx^%d ",qn[i],8-i);
    }
    printf("\n");

    double qnp[10];

    //derivando el polinomio desinflado
    for(i=0;i<8;i++)
    {
        qnp[i] = qn[i]*(8-i);
        //printf("%.14gx^%d ",qn[i]*(8-i),8-i-1);
    }

    printf("\nimprimiendo la derivada del polinomio desinflado\n");
    for(i=0;i<8;i++)
    {
        printf("%fx^%d ",qnp[i],7-i);
    }
    printf("\n");

    x = 7.2;
    i=0;
    double calculos2[100][2];
    do{
        fx = metodohornerdouble(qn,x,9);
        fxprime = metodohornerdouble(qnp,x,8);
        actualizartablanewton(calculos2, i++, x, fx);
        x = x - (fx/fxprime);
    }while(fabs(fx) > objetivo && i < maxit);

    double qn2[10],qnp2[10];

    //desinflando el polinomio por segunda vez
    qn2[0] = qn[0];
    for(i=1;i<=7;i++)
    {
        qn2[i] = qn[i] + qn2[i-1]*x;
    }

    //derivada de ese nuevo polinomio
    for(i=0;i<7;i++)
    {
        qnp2[i] = qn2[i]*(7-i);
        //printf("%.14gx^%d ",qn[i]*(8-i),8-i-1);
    }

    printf("\nmostrando el nuevo polimomio\n");
    for(i=0;i<8;i++)
    {
        printf("%fx^%d ",qn2[i],7-i);
    }
    printf("\n");

    printf("\nimprimiendo la derivada del polinomio desinflado\n");
    for(i=0;i<7;i++)
    {
        printf("%fx^%d ",qnp2[i],6-i);
    }
    printf("\n");

    x = 7.2;
    i=0;
    double calculos3[100][2];
    do{
        fx = metodohornerdouble(qn2,x,8);
        fxprime = metodohornerdouble(qnp2,x,7);
        actualizartablanewton(calculos3, i++, x, fx);
        x = x - (fx/fxprime);
    }while(fabs(fx) > objetivo && i < maxit*4);
    
    //////////////////////////////////////////////////////////////////////
    double qn3[10],qnp3[10];

    //desinflando el polinomio por tercera vez
    qn3[0] = qn2[0];
    for(i=1;i<=6;i++)
    {
        qn3[i] = qn2[i] + qn3[i-1]*x;
    }

    //derivada de ese nuevo polinomio
    for(i=0;i<6;i++)
    {
        qnp3[i] = qn3[i]*(6-i);
        //printf("%.14gx^%d ",qn[i]*(8-i),8-i-1);
    }

    printf("\nmostrando el nuevo polimomio\n");
    for(i=0;i<7;i++)
    {
        printf("%fx^%d ",qn3[i],6-i);
    }
    printf("\n");

    printf("\nimprimiendo la derivada del polinomio desinflado\n");
    for(i=0;i<6;i++)
    {
        printf("%fx^%d ",qnp3[i],5-i);
    }
    printf("\n");

    x = 7.2;
    i=0;
    double calculos4[100][2];
    do{
        fx = metodohornerdouble(qn3,x,7);
        fxprime = metodohornerdouble(qnp3,x,6);
        actualizartablanewton(calculos4, i++, x, fx);
        x = x - (fx/fxprime);
    }while(fabs(fx) > objetivo && i < maxit);

//////////////////////////////////////////////////////////////////////
    double qn4[10],qnp4[10];

    //desinflando el polinomio por tercera vez
    qn4[0] = qn3[0];
    for(i=1;i<=5;i++)
    {
        qn4[i] = qn3[i] + qn4[i-1]*x;
    }

    //derivada de ese nuevo polinomio
    for(i=0;i<5;i++)
    {
        qnp4[i] = qn4[i]*(5-i);
        //printf("%.14gx^%d ",qn[i]*(8-i),8-i-1);
    }

    printf("\nmostrando el nuevo polimomio\n");
    for(i=0;i<6;i++)
    {
        printf("%fx^%d ",qn4[i],5-i);
    }
    printf("\n");

    printf("\nimprimiendo la derivada del polinomio desinflado\n");
    for(i=0;i<5;i++)
    {
        printf("%fx^%d ",qnp4[i],4-i);
    }
    printf("\n");

    x = 7.2;
    i=0;
    double calculos5[100][2];
    do{
        fx = metodohornerdouble(qn4,x,6);
        fxprime = metodohornerdouble(qnp4,x,5);
        actualizartablanewton(calculos5, i++, x, fx);
        x = x - (fx/fxprime);
    }while(fabs(fx) > objetivo && i < maxit);


//////////////////////////////////////////////////////////////////////
    double qn5[10],qnp5[10];

    //desinflando el polinomio por tercera vez
    qn5[0] = qn4[0];
    for(i=1;i<=4;i++)
    {
        qn5[i] = qn4[i] + qn5[i-1]*x;
    }

    //derivada de ese nuevo polinomio
    for(i=0;i<4;i++)
    {
        qnp5[i] = qn5[i]*(4-i);
        //printf("%.14gx^%d ",qn[i]*(8-i),8-i-1);
    }

    printf("\nmostrando el nuevo polimomio\n");
    for(i=0;i<5;i++)
    {
        printf("%fx^%d ",qn5[i],4-i);
    }
    printf("\n");

    printf("\nimprimiendo la derivada del polinomio desinflado\n");
    for(i=0;i<4;i++)
    {
        printf("%fx^%d ",qnp5[i],3-i);
    }
    printf("\n");

    x = 7.2;
    i=0;
    double calculos6[100][2];
    do{
        fx = metodohornerdouble(qn5,x,5);
        fxprime = metodohornerdouble(qnp5,x,4);
        actualizartablanewton(calculos6, i++, x, fx);
        x = x - (fx/fxprime);
    }while(fabs(fx) > objetivo && i < maxit);

//////////////////////////////////////////////////////////////////////
    double qn6[10],qnp6[10];

    //desinflando el polinomio por tercera vez
    qn6[0] = qn5[0];
    for(i=1;i<=3;i++)
    {
        qn6[i] = qn5[i] + qn6[i-1]*x;
    }

    //derivada de ese nuevo polinomio
    for(i=0;i<3;i++)
    {
        qnp6[i] = qn6[i]*(3-i);
        //printf("%.14gx^%d ",qn[i]*(8-i),8-i-1);
    }

    printf("\nmostrando el nuevo polimomio\n");
    for(i=0;i<4;i++)
    {
        printf("%fx^%d ",qn6[i],3-i);
    }
    printf("\n");

    printf("\nimprimiendo la derivada del polinomio desinflado\n");
    for(i=0;i<3;i++)
    {
        printf("%fx^%d ",qnp6[i],2-i);
    }
    printf("\n");

    x = 7.2;
    i=0;
    double calculos7[100][2];
    do{
        fx = metodohornerdouble(qn6,x,4);
        fxprime = metodohornerdouble(qnp6,x,3);
        actualizartablanewton(calculos7, i++, x, fx);
        x = x - (fx/fxprime);
    }while(fabs(fx) > objetivo && i < maxit);

//////////////////////////////////////////////////////////////////////
    double qn7[10];

    //desinflando el polinomio
    qn7[0] = qn6[0];
    for(i=1;i<=2;i++)
    {
        qn7[i] = qn6[i] + qn7[i-1]*x;
    }
    

    printf("\nmostrando el nuevo polimomio\n");
    for(i=0;i<3;i++)
    {
        printf("%fx^%d ",qn6[i],2-i);
    }
    printf("\n");

    printf("%f\n",qn7[1]*qn7[1] -4*qn7[0]*qn7[2]);

    double disc = qn7[1]*qn7[1] -4*qn7[0]*qn7[2];
    disc *=-1;
    printf("%f\n",sqrt(disc));
    printf("%f\n",2*qn7[0]);
    
    //mostrartablanewton(calculos7,i,14);
    //guardartablanewtonlatex(calculos7,i,14,"raiz7.txt");
    //printf("x = %f, f(x) = %f\n",x,metodohornerdouble(qn,x,9));

}