#include "include/main.h"
#include "include/biseccion.h"
#include "include/puntofijo.h"
#include "include/newton.h"
#include "include/secante.h"
#include "include/misc.h"
#include <stdio.h>

void playgroundbiseccion(void);
void playgroundpuntofijo(void);
void playgroundsecante(void);
void playgroundnewton(void);
void metodonewtonejercicio3b(void);
//void metodonewtonejercicio3b(double totalcalculos[][13], int raices, double beta[], 
   // double gamma[], double alpha[], double b[],double objetivo, int variante,int maxit);

int main(void)
{
    //playgroundbiseccion();
    //playgroundpuntofijo();   
    //playgroundsecante();
    //playgroundnewton();
    metodonewtonejercicio3b();
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

void metodonewtonejercicio3b(void)
{
    int variante = EXACTAFUNCIONDIFICIL;
    int maxit = MAXIT64;
    double objetivo = OBJETIVO;
    int i,nbeta,ngamma,nalpha,nb,raices;

    double beta[5] = {-3,-2,-2,-1,1},gamma[5] = {-2,-1,-1,0,2};
    double alpha[5] = {-2.2,-1.6,-1.4,-0.76,1.76},b[5] = {-2.25,-1.65,-1.45,-0.81,1.65};

    double totalcalculos[maxit][13];
    double calculosbeta[maxit][2],calculosgamma[maxit][2],calculosalpha[maxit][2];
    double calculosb[maxit][2];
    
    nbeta = metodonewton(calculosbeta, beta[0],objetivo,variante,0,maxit);
    ngamma = metodonewton(calculosgamma, gamma[0],objetivo,variante,0,maxit);
    nalpha = metodonewton(calculosalpha, alpha[0],objetivo,variante,0,maxit);
    nb = metodonewton(calculosb, b[0],objetivo,variante,0,maxit);

    for(i = 0;i < nbeta;i++)
    {
        totalcalculos[i][0] = i;
        totalcalculos[i][1] = calculosbeta[i][0];
        totalcalculos[i][2] = calculosbeta[i][1];
        totalcalculos[i][3] = fabs(calculosbeta[i+1][0] - calculosbeta[i][0]); //cuidado con el ultimo
    }

    if(i < maxit)
    {
        rellenarcerostabla(totalcalculos,i,maxit,1,2,3);
    }

    for(i = 0;i < ngamma;i++)
    {
        totalcalculos[i][0] = i;
        totalcalculos[i][4] = calculosgamma[i][0];
        totalcalculos[i][5] = calculosgamma[i][1];
        totalcalculos[i][6] = fabs(calculosgamma[i+1][0] - calculosgamma[i][0]); //cuidado con el ultimo
    }

    if(i < maxit)
    {
        rellenarcerostabla(totalcalculos,i,maxit,4,5,6);
    }

    for(i = 0;i < nalpha;i++)
    {
        totalcalculos[i][0] = i;
        totalcalculos[i][7] = calculosalpha[i][0];
        totalcalculos[i][8] = calculosalpha[i][1];
        totalcalculos[i][9] = fabs(calculosalpha[i+1][0] - calculosalpha[i][0]); //cuidado con el ultimo
    }

    if(i < maxit)
    {
        rellenarcerostabla(totalcalculos,i,maxit,7,8,9);
    }

    for(i = 0;i < nb;i++)
    {
        totalcalculos[i][0] = i;
        totalcalculos[i][10] = calculosb[i][0];
        totalcalculos[i][11] = calculosb[i][1];
        totalcalculos[i][12] = fabs(calculosb[i+1][0] - calculosb[i][0]); //cuidado con el ultimo
    }

    if(i < maxit)
    {
        rellenarcerostabla(totalcalculos,i,maxit,10,11,12);
    }

    guardarmegatablanewton(totalcalculos, maxit, 14,"megatablaraiz1.txt");
    guardarmegatablanewtonlatex(totalcalculos, maxit, 14,"megatablalatexraiz1.txt");
}