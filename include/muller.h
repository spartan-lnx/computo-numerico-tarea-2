int metodomuller(double calculos[][4], double x0, double x1, double x2, double objetivo, int maxit);
void actualizartablamuller(int i, double calculos[][4], double x0, double x1, double x2, double fx2);
void mostrartablamuller(int n, double calculos[][4], int cifras_significativas);
void guardarmegatablamuller(double totalcalculos[][17], int n, int cifras_significativas, char nombre[]);
void guardarmegatablamullerlatex(double totalcalculos[][17], int n, int cifras_significativas, char nombre[]);
void guardartablamullerlatex(int n, double calculos[][4], int cifras_significativas, char nombre[]);