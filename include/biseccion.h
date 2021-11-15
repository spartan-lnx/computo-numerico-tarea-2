#include "main.h"
#include "funciones.h"

void metodobiseccion(char nombre[],double a,double b,double objetivo,int funcion);
void mostrartablabiseccion(int i, double a, double b, double c, double fc,int cifras_significativas);
void guardartablabiseccionlatex(FILE* archivo, int i, double a, double b, double c, double fc,int cifras_significativas);