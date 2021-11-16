#include "include/main.h"
#include "include/biseccion.h"
#include "include/puntofijo.h"
#include "include/newton.h"
#include "include/secante.h"

void playgroundbiseccion(void);
void playgroundpuntofijo(void);
void playgroundsecante(void);
void playgroundnewton(void);

int main(void)
{
    //playgroundbiseccion();
    //playgroundpuntofijo();   
    //playgroundsecante();
    playgroundnewton();
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