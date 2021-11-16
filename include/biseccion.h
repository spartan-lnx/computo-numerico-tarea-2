#include "main.h"

int metodobiseccion(double a,double b,double objetivo,int funcion, double calculos[][4],int maxit);
void actualizartablabiseccion(double calculos[][4],int i,double a,double b, double c, double fc);
void mostrartablabiseccion(double calculos[][4],int n,int cifras_significativas);
void guardartablabiseccionlatex(double calculos[][4],int n,int cifras_significativas, char nombre[]);