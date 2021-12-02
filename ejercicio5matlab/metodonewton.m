function [root,k] = metodonewton(funcion, derivadafun, x, objetivo,maxit)

fx = 0;
fxprime = 0;
for k=1:maxit
    fx = funcion(x);
    fxprime = derivadafun(x);
    x = x - (fx/fxprime);
    if(abs(fx) < objetivo)
        break
    end
end
root = x;