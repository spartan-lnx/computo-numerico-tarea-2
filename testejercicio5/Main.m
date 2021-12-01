clearvars
% Range of the figure
imD = −1;
imU = 1;
reL = −1;
reR = 1;
stepSize = 0.01;
% Functions
f = @(z)zˆ3+1;
df = @(z)3*zˆ2;
% Roots
root1 = −1;
root2 = (−1)ˆ(1/3);
root3 = −(−1)ˆ(2/3);
root4 = −1.5*pi;
root5 = −0.5*pi;
tol = 0.0000001; % The desired tolerance
maxIt = 100; % Maximum number of iterations
method = 0; % 0: Draw the figure with the Relaxed Newton's method
% 1: Draw the figure with Newton's method
% 2: Draw the figure with the Secant method (x1 determined
% with Newton)
% 3: Draw the figure with the Secant method (x0 determined
% with x0= a+ad+i(b+bd)
m = 0.5; % Value of m for the Relaxed Newton's method
d = 1; %Value of d for the Secant method
% Determines the roots with one of the root finding methods for all of
% the initial points.
[C,I] = Figure( f, df, tol,maxIt,reL,reR,imD,imU,stepSize, root1,...
root2,root3,root4,root5,0,method,m,d);
% Creates the figure
x = [reL reR];
y = [imD imU];
ax = gca;
load('MyColormaps','mycmap')
colormap(ax,mycmap)
clims = [1 64];
imagesc(x,y,C,clims)
colorbar
ylabel('Im(z)')
xlabel('Re(z)')
set(gca,'YDir','normal')