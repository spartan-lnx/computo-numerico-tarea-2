#include "../include/funciones.h"

double cosx_minus_x(double x)
{
    return (cos(x) - x);
}

double minus_sinx_minus_one(double x)
{
    return (-sin(x) - 1);
}

double derivada_adelante(double x, double epsilon)
{
    return (cosx_minus_x(x + epsilon) - cosx_minus_x(x))/epsilon;
}

double derivada_atras(double x, double epsilon)
{
    return (cosx_minus_x(x) - cosx_minus_x(x-epsilon))/epsilon;
}

double derivada_central(double x, double epsilon)
{
    return (cosx_minus_x(x + epsilon) - cosx_minus_x(x - epsilon))/2*epsilon;
}

double funcion_dificil(double x)
{
    return ((cos(2*M_PI*x)-6)*pow(x,3) - (2*cos(2*M_PI*x)+7)*pow(x,2) 
        -2*(cos(2*M_PI*x)-10)*x -3*cos(2*M_PI*x) + 19)/(15*x*x -x -40);
}

double derivada_funcion_dificil(double x)
{
    return (-30*M_PI*sin(2*M_PI*x)*pow(x,5)+ 2*M_PI*cos(2*M_PI*x)*pow(x,4)+
    15*M_PI*cos(2*M_PI*x)*pow(x,4) - 90*pow(x,4) + 80*M_PI*sin(2*M_PI*x)*pow(x,3)
    - 2*cos(2*M_PI*x)*pow(x,3)+ 12*pow(x,3) - 120*cos(2*M_PI*x)*pow(x,2) + 
    720*pow(x,2) + 60*sin(2*M_PI*x)*pow(x,4) - 4*sin(2*M_PI*x)*pow(x,3) -
    160*sin(2*M_PI*x)*pow(x,2) + 2*cos(2*M_PI*x)*pow(x,2) + 7*pow(x,2) + 
    160*cos(2*M_PI*x)*x + 560*x + 60*M_PI*sin(2*M_PI*x)*pow(x,3)- 4*M_PI*sin(2*M_PI*x)*pow(x,2)
    + 30*cos(2*M_PI*x)*pow(x,2)- 300*pow(x,2) - 160*M_PI*sin(2*M_PI*x)*x +
    80*cos(2*M_PI*x) - 800 + 90*M_PI*sin(2*M_PI*x)*pow(x,2) - 6*M_PI*sin(2*M_PI*x)*x
    + 90*cos(2*M_PI*x)*x - 240*M_PI*sin(2*M_PI*x) - 3*cos(2*M_PI*x) - 570*x + 19)/
    (pow((15*x*x - x - 40),2));
}

double funcionnovenogrado(double x)
{
    return (756*pow(x,9) + 2448*pow(x,8)+1605*pow(x,7)-2583*pow(x,6)-4705*pow(x,5)-
    2069*pow(x,4)+1643*pow(x,3)+1773*pow(x,2)-20*x-300);
}