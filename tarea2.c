#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define EXACTA 1
#define ADELANTE 2
#define DETRAS 3
#define CENTRAL 4

#define FUNCIONFACIL 5
#define FUNCIONDIFICIL 6

#define EXACTAFUNCIONDIFICIL 7

void biseccion(char nombre[],double a,double b,double error,int funcion);
void printtablebiseccion(int i, double a, double b, double c, double fc);
void savetablebiseccionlatex(FILE* archivo, int i, double a, double b, double c, double fc,int cifras_significativas);

void puntofijo(char nombre[],double x,double error);
void printtablepuntofijo(int i,double x, double fx);
void savetablepuntofijolatex(FILE* archivo,int i, double x, double fx);

void metodonewton(char nombre[],double x, double error,int variante, double epsilon);
void savetablenewtonlatex(FILE* archivo,int i, double x, double fx,int cifras_significativas);

void metodosecante(char nombre[],double x0,double x1, double error);
void savetablesecante(FILE* archivo,int i, double x1,double x0, double fx);

double cosx_minus_x(double x);
double minus_sinx_minus_one(double x);
double derivada_adelante(double x, double epsilon);
double derivada_atras(double x, double epsilon);
double derivada_central(double x, double epsilon);

double funcion_dificil(double x);
double derivada_funcion_dificil(double x);

int main(void)
{
    double alpha1 = -0.75, alpha2 = 1.75, alpha3 = 3.15;
    double error = 0.0001;
    double epsilon1 = 0.1, epsilon2 = 0.01, epsilon3 = 0.0001;
    
    //biseccion("alpha1alpha2bisec.txt",alpha1,alpha2,error,FUNCIONFACIL); //[alpha1,alpha2]
    //biseccion("alpha2alpha3bisec.txt",alpha2,alpha3,error,FUNCIONFACIL); //[alpha2,alpha3] no es valido este intervalo
    
    //==========================================================================//
    
    //puntofijo("alpha1puntofijo.txt",alpha1,error); //alpha1
    //puntofijo("alpha2puntofijo.txt",alpha2,error); //alpha2
    //puntofijo("alpha3puntofijo.txt",alpha3,error); //alpha3
    
    //==========================================================================//
    
    //metodonewton("alpha1newtonexacto.txt",alpha1,error,EXACTA,0); //alpha1 no converge
    //metodonewton("alpha2newtonexacto.txt",alpha2,error,EXACTA,0); //alpha2
    //metodonewton("alpha3newtonexacto.txt",alpha3,error,EXACTA,0); //alpha3
    
    //==========================================================================//
    
    //metodonewton("alpha1newtonadelanteepsion1.txt",alpha1,error,ADELANTE,epsilon1); //alpha1
    //metodonewton("alpha1newtonatrasepsilon1.txt",alpha1,error,DETRAS,epsilon1); //alpha1
    //metodonewton("alpha1newtoncentralepsilon1.txt",alpha1,error,CENTRAL,epsilon1); //alpha1 no converge
    
    //metodonewton("alpha1newtonadelanteepsion2.txt",alpha1,error,ADELANTE,epsilon2); //alpha1
    //metodonewton("alpha1newtonatrasepsilon2.txt",alpha1,error,DETRAS,epsilon2); //alpha1
    //metodonewton("alpha1newtoncentralepsilon2.txt",alpha1,error,CENTRAL,epsilon2); //alpha1 no converge
    
    //metodonewton("alpha1newtonadelanteepsion3.txt",alpha1,error,ADELANTE,epsilon3); //alpha1 no converge
    //metodonewton("alpha1newtonatrasepsilon3.txt",alpha1,error,DETRAS,epsilon3); //alpha1
    //metodonewton("alpha1newtoncentralepsilon3.txt",alpha1,error,CENTRAL,epsilon3); //alpha1 no converge
    
    //==========================================================================//
    
    //metodonewton("alpha2newtonadelanteepsion1.txt",alpha2,error,ADELANTE,epsilon1); //alpha2
    //metodonewton("alpha2newtonatrasepsilon1.txt",alpha2,error,DETRAS,epsilon1); //alpha2
    //metodonewton("alpha2newtoncentralepsilon1.txt",alpha2,error,CENTRAL,epsilon1); //alpha2 no converge
    
    //metodonewton("alpha2newtonadelanteepsion2.txt",alpha2,error,ADELANTE,epsilon2); //alpha2
    //metodonewton("alpha2newtonatrasepsilon2.txt",alpha2,error,DETRAS,epsilon2); //alpha2
    //metodonewton("alpha2newtoncentralepsilon2.txt",alpha2,error,CENTRAL,epsilon2); //alpha2 no converge
    
    //metodonewton("alpha2newtonadelanteepsion3.txt",alpha2,error,ADELANTE,epsilon3); //alpha2
    //metodonewton("alpha2newtonatrasepsilon3.txt",alpha2,error,DETRAS,epsilon3); //alpha2
    //metodonewton("alpha2newtoncentralepsilon3.txt",alpha2,error,CENTRAL,epsilon3); //alpha2 no converge
    
     //==========================================================================//
    
    //metodonewton("alpha3newtonadelanteepsion1.txt",alpha3,error,ADELANTE,epsilon1); //alpha3 no converge
    //metodonewton("alpha3newtonatrasepsilon1.txt",alpha3,error,DETRAS,epsilon1); //alpha3
    //metodonewton("alpha3newtoncentralepsilon1.txt",alpha3,error,CENTRAL,epsilon1); //alpha3 no converge
    
    //metodonewton("alpha2newtonadelanteepsion2.txt",alpha3,error,ADELANTE,epsilon2); //alpha3 no converge
    //metodonewton("alpha2newtonatrasepsilon2.txt",alpha3,error,DETRAS,epsilon2); //alpha3
    //metodonewton("alpha3newtoncentralepsilon2.txt",alpha3,error,CENTRAL,epsilon2); //alpha3 no converge
    
    //metodonewton("alpha3newtonadelanteepsion3.txt",alpha3,error,ADELANTE,epsilon3); //alpha3
    //metodonewton("alpha3newtonatrasepsilon3.txt",alpha3,error,DETRAS,epsilon3); //alpha3
    //metodonewton("alpha3newtoncentralepsilon3.txt",alpha3,error,CENTRAL,epsilon3); //alpha3 no converge
    
    //metodosecante("asdad",alpha1,alpha2,error);
    //metodosecante("asdad",alpha1,alpha3,error);
    //metodosecante("asdad",alpha2,alpha3,error);
    
    //biseccion("alpha1.txt",-3,-2,error,FUNCIONDIFICIL); //funciona
    //biseccion("alpha2.txt",-2,-1,error,FUNCIONDIFICIL); //1.42 si, 1.6 no
    //biseccion("alpha4.txt",-1,0,error,FUNCIONDIFICIL); //funciona
    //biseccion("alpha5.txt",1,2,error,FUNCIONDIFICIL); //no funciona porque se indetermina en 1.5
    
    
    //biseccion("alpha2-1.txt",-2,-1.55,error,FUNCIONDIFICIL); //bueno
    //biseccion("alpha2-2.txt",-1.65,-1,error,FUNCIONDIFICIL); //malo
    //biseccion("alpha5-1.txt",1,2.05,error,FUNCIONDIFICIL); //no funciona
    //biseccion("alpha5-2.txt",0.95,2,error,FUNCIONDIFICIL); //no funciona

    //metodonewton("prueba1.txt", -3, error, EXACTAFUNCIONDIFICIL, 1); //beta_1 FUNCIONAAAA! :)
    //metodonewton("prueba2.txt", -2, error, EXACTAFUNCIONDIFICIL, 1); //beta_2 y beta_3 //no converge
    //metodonewton("prueba3.txt", -1, error, EXACTAFUNCIONDIFICIL, 1); //beta_4 //converge
    //metodonewton("prueba4.txt", 1, error, EXACTAFUNCIONDIFICIL, 1); //beta_5 //no converge

    //metodonewton("prueba5.txt", -2, error, EXACTAFUNCIONDIFICIL, 1); //gamma_1 //no converge
    //metodonewton("prueba6.txt", -1, error, EXACTAFUNCIONDIFICIL, 1); //gamma_2 y gamma_3 //converge
    //metodonewton("prueba7.txt", 0, error, EXACTAFUNCIONDIFICIL, 1); //gamma_4 //converge
    //metodonewton("prueba8.txt", 2, error, EXACTAFUNCIONDIFICIL, 1); //gamma_5 //no converge

    //metodonewton("prueba9.txt", -2.2, error, EXACTAFUNCIONDIFICIL, 1); //alpha_1 //converge
    //metodonewton("prueba10.txt", -1.6, error, EXACTAFUNCIONDIFICIL, 1); //alpha_2 //no converge
    //metodonewton("prueba11.txt", -1.4, error, EXACTAFUNCIONDIFICIL, 1); //alpha_3 //no converge
    //metodonewton("prueba12.txt", -0.76, error, EXACTAFUNCIONDIFICIL, 1); //alpha_4 //converge
    //metodonewton("prueba13.txt", 1.7, error, EXACTAFUNCIONDIFICIL, 1); //alpha_5 //converge

    //metodonewton("prueba14.txt", -2.25, error, EXACTAFUNCIONDIFICIL, 1); //b_1 //converge
    //metodonewton("prueba15.txt", -1.65, error, EXACTAFUNCIONDIFICIL, 1); //b_2 //no converge
    //metodonewton("prueba16.txt", -1.45, error, EXACTAFUNCIONDIFICIL, 1); //b_3 //converge
    //metodonewton("prueba17.txt", -0.81, error, EXACTAFUNCIONDIFICIL, 1); //b_4 //converge
    //metodonewton("prueba18.txt", 1.65, error, EXACTAFUNCIONDIFICIL, 1); //b_5 //converge

    //metodonewton("prueba19.txt", -2.15, error, EXACTAFUNCIONDIFICIL, 1); //b_1 //converge
    //metodonewton("prueba20.txt", -1.55, error, EXACTAFUNCIONDIFICIL, 1); //b_2 //no converge
    //metodonewton("prueba21.txt", -1.34, error, EXACTAFUNCIONDIFICIL, 1); //b_3 //no converge
    //metodonewton("prueba22.txt", -0.71, error, EXACTAFUNCIONDIFICIL, 1); //b_4 //converge
    //metodonewton("prueba23.txt", 1.75, error, EXACTAFUNCIONDIFICIL, 1); //b_5 //converge

    return 0;
}

void biseccion(char nombre[],double a,double b,double error,int funcion)
{
    double c,fc;
    FILE* archive = fopen(nombre,"w+");
    int i = 0,max_it=50;
    
    fprintf(archive,"\\begin{tabular}{c c c c c}\n");
    fprintf(archive,"it & a & b & c & f(c) \\\\ \n");
    printf("it\ta\t\tb\t\tc\t\tfc\n");
    
    switch(funcion)
    {
        case FUNCIONFACIL:
        {
            do{
                c = (a+b)/2;
                fc = (cosx_minus_x(c));
                printtablebiseccion(i++,a,b,c,fc);
                savetablebiseccionlatex(archive,i++,a,b,c,fc,11);
                if(fabs(fc) < error || i>max_it)
                {
                    break;
                }
                else
                {
                    if(fc*cosx_minus_x(a) <= 0)
                    {
                        b = c;
                    }
                    else
                    {
                        a = c;
                    } 
                }
            }while(1==1);
         
            break;   
        }
        case FUNCIONDIFICIL:
        {
            do{
                c = (a+b)/2;
                fc = (funcion_dificil(c));
                printtablebiseccion(i++,a,b,c,fc);
                savetablebiseccionlatex(archive,i++,a,b,c,fc,5);
                if(fabs(fc) < error || i>max_it)
                {
                    break;
                }
                else
                {
                    if(fc*funcion_dificil(a) <= 0)
                    {
                        b = c;
                    }
                    else
                    {
                        a = c;
                    } 
                }
            }while(1==1);
            break;   
        }
    }
    
    fprintf(archive,"\\end{tabular}\n");
    fclose(archive);
}

void puntofijo(char nombre[],double x,double error)
{
    int i=0;
    double fx;
    FILE* archive = fopen(nombre,"w+");
    fprintf(archive,"\\begin{tabular}{c c c}\n");
    fprintf(archive,"it & x_i & f(x_i)\\\\ \n");
    printf("it\txi\t\tfxi\n");
    do{
        fx = cosx_minus_x(x);
        printtablepuntofijo(i,x,fx);
        savetablepuntofijolatex(archive,i,x,fx);
        x = fx + x;
        i++;
    }while(fabs(fx) > error);
    fprintf(archive,"\\end{tabular}\n");
    fclose(archive);
}

void metodonewton(char nombre[],double x, double error,int variante, double epsilon)
{
    double fx,fxprime;
    int i=0,max_it = 50;
    FILE* archive = fopen(nombre,"w+");
    
    fprintf(archive,"\\begin{tabular}{c c c}\n");
    fprintf(archive,"it & x_i & f(x_i)\\\\ \n");
    printf("it\txi\t\t\tfxi\n");
    switch(variante)
    {
        case EXACTA:
        {
            do{
                fx = cosx_minus_x(x);
                fxprime = minus_sinx_minus_one(x);
                printf("%d\t%.13g\t\t%.13g\n",i++,x,fx);
                savetablenewtonlatex(archive,i,x,fx,13);
                x = x - (fx/fxprime);
            }while(fabs(fx) > error && i<max_it);
            break;
        }
        
        case ADELANTE:
        {
            do{
                fx = cosx_minus_x(x);
                fxprime = derivada_adelante(x,epsilon);
                printf("%d\t%.13g\t\t%.13g\n",i++,x,fx);
                savetablenewtonlatex(archive,i,x,fx,13);
                x = x - (fx/fxprime);
            }while(fabs(fx) > error && i<max_it);   
            break;
        }
        
        case DETRAS:
        {
            do{
                fx = cosx_minus_x(x);
                fxprime = derivada_atras(x,epsilon);
                printf("%d\t%.13g\t\t%.13g\n",i++,x,fx);
                savetablenewtonlatex(archive,i,x,fx,13);
                x = x - (fx/fxprime);
            }while(fabs(fx) > error&& i<max_it);
            break;
        }
        
        case CENTRAL:
        {
            do{
                fx = cosx_minus_x(x);
                fxprime = derivada_central(x,epsilon);
                printf("%d\t%.13g\t\t%.13g\n",i++,x,fx);
                savetablenewtonlatex(archive,i,x,fx,13);
                x = x - (fx/fxprime);
            }while(fabs(fx) > error && i<max_it);
            break;
        }

        case EXACTAFUNCIONDIFICIL:
        {
             do{
                fx = funcion_dificil(x);
                fxprime = derivada_funcion_dificil(x);
                printf("%d\t%.14g\t\t%.14g\n",i++,x,fx);
                savetablenewtonlatex(archive,i,x,fx,14);
                x = x - (fx/fxprime);
            }while(fabs(fx) > error && i<90);
            break;
        }
    }
    fprintf(archive,"\\end{tabular}\n");
    fclose(archive);
}

void metodosecante(char nombre[],double x0,double x1, double error)
{
    double fx0, fx1,x2;
    int i = 0,max_it=50;
    FILE* archive = fopen(nombre,"w+");
    
    fprintf(archive,"\\begin{tabular}{c c c c}\n");
    fprintf(archive,"it & $x_i$ & $x_{i-1}$ & $f(x_i)$\\\\\n");
    printf("it\tx_i\t\t\tx_{i-1}\t\t\tf(x_i)\n");
    
    do{
        fx0 = cosx_minus_x(x0);
        fx1 = cosx_minus_x(x1);
        printf("%d\t%.13g\t\t%.13g\t\t%.13g\n",i++,x1,x0,fx1);
        savetablesecante(archive,i,x1,x0,fx1);
        x2 = x1 - ((x1 - x0)/(fx1 - fx0))*fx1;
        x0 = x1;
        x1 = x2;
    }while(fabs(fx1) > error && i<max_it);
    
    fprintf(archive,"\\end{tabular}\n");
    fclose(archive);
}

void printtablebiseccion(int i, double a, double b, double c, double fc)
{
    printf("%d\t%.11g\t%.11g\t%.11g\t%.11g\n",i,a,b,c,fc);
}

void printtablepuntofijo(int i,double x, double fx)
{
    printf("%d\t%.11g\t%.11g\n",i,x,fx);
}

void savetablesecante(FILE* archivo,int i, double x1,double x0, double fx)
{
    fprintf(archivo,"%d & %.13g & %.13g & %.13g \\\\\n",i,x1,x0,fx); 
}

void savetablenewtonlatex(FILE* archivo,int i, double x, double fx, int cifras_significativas)
{
    if(cifras_significativas==13)
        fprintf(archivo,"%d & %.13g & %.13g \\\\\n",i,x,fx);
    else
        fprintf(archivo,"%d & %.14g & %.14g \\\\\n",i,x,fx);
}

void savetablepuntofijolatex(FILE* archivo,int i, double x, double fx)
{
    fprintf(archivo,"%d & %.11g & %.11g \\\\\n",i,x,fx);
}

void savetablebiseccionlatex(FILE* archivo, int i, double a, double b, double c, double fc,int cifras_significativas)
{
    if(cifras_significativas == 11)
        fprintf(archivo,"%d & %.11g & %.11g & %.11g & %.11g \\\\\n",i,a,b,c,fc);
    else
        fprintf(archivo,"%d & %.5g & %.5g & %.5g & %.5g \\\\\n",i,a,b,c,fc);
}

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
