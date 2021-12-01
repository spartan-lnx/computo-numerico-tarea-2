clearvars

L = 2;
n = 256;

negIm = -L/2;
posIm = L/2;
negRe = -L/2;
posRe = L/2;

funcion = @(z)z^3-1;
derivadafun = @(z)3*z^2;

raiz1 = 1;
raiz2 = complex(-0.5,-(sqrt(3))/2);
raiz3 = complex(-0.5,(sqrt(3))/2);

tamPaso = 0.01;
objetivo = 0.000001; % multiples objetivos: 10^-6, 10^-8, 10^-10,10^-12,10^-14
maxit = 16; % multiples maxit: 16, 8, 16, 32, 64, 128, 256, 512

[C,I] = pintarx(funcion, derivadafun, objetivo,maxit,negRe,posRe,negIm,posIm,tamPaso,raiz1, raiz2, raiz3);

% Creates the figure
x = [negRe posRe];
y = [negIm posIm];
ax = gca;

%load('MyColormaps','mycmap')
colormap(ax,prism)
clims = [1 64];
imagesc(x,y,C,clims)
colorbar
ylabel('Im(z)')
xlabel('Re(z)')
set(gca,'YDir','normal')