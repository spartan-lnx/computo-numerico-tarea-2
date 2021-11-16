int metodonewton(double calculos[][2],double x, double objetivo,int variante, double epsilon,int maxit);
void actualizartablanewton(double calculos[][2],int i,double x, double fx);
void mostrartablanewton(double calculos[][2],int n, int cifras_significativas);
void guardarmegatablanewton(double totalcalculos[][13],int n, int cifras_significativas,char nombre[]);
void guardarmegatablanewtonlatex(double totalcalculos[][13],int n, int cifras_significativas,char nombre[]);
void guardartablanewtonlatex(double calculos[][2],int n, int cifras_significativas, char nombre[]);