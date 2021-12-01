function [root,flag,convHist,k] = secantN(f,df,x0,tol,maxIt)
    % Determines the root for the inital guess where x1 is determined using
    % Newton's method.
    % INPUT
    % f function of rootfinding problem
    % df the function name or function handle to the derivative of f
    % x0 initial guess
    % tol the desired tolerance
    % maxIt maximum number of iterations
    % OUTPUT
    % root root of f
    % flag if 0: attained desired tolerance
    % if 1: reached maxIt nr of iterations
    % convHist convergence history
    % k amount of iterations needed
    flag=1;
    x1 = newton(f, df, x0, tol,1);
    x2 = (x0*f(x1) − x1*f(x0))/(f(x1) − f(x0));
    for k=1:maxIt
    x0 = x1;
    x1 = x2;
    x2 = (x0*f(x1) − x1*f(x0))/(f(x1) − f(x0));
    update = f(x2);
    % compute error estimate
    convHist(k) = abs(update);
    % check convergence
    if convHist(k) < tol
    flag = 0;
    break
    end
    end
    root = x2;
    end