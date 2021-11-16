#include "main.h"
#include "funciones.h"

int metodopuntofijo(double x,double objetivo, double calculos[][2], int maxit);
void actualizartablapuntofijo(double calculos[][2],int i, double x, double fx);
void mostrartablapuntofijo(double calculos[][2], int n, int cifras_significativas);
void guardartablapuntofijolatex(double calculos[][2], int n, int cifras_significativas, char nombre[]);