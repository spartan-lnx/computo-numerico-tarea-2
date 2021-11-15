#include "include/main.h"
#include "include/biseccion.h"
#include "include/puntofijo.h"
#include "include/newton.h"
#include "include/secante.h"

int main(void)
{
    double alpha1 = -0.75, alpha2 = 1.75, alpha3 = 3.15;
    double objetivo = 0.0001;
    double epsilon1 = 0.1, epsilon2 = 0.01, epsilon3 = 0.0001;

    metodobiseccion("hola.txt", alpha1, alpha2,objetivo, FUNCIONFACIL);
    return 0;
}