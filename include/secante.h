#include "main.h"

int metodosecante(double x0,double x1, double objetivo, double calculos [][3],int maxit);
void actualizartablasecante(double calculos[][3],int i, double x1, double x0, double fx1);
void mostrartablasecante(double calculos[][3],int n,int cifras_significativas);
void guardartablasecantelatex(double calculos[][3],int n,int cifras_significativas, char nombre[]);