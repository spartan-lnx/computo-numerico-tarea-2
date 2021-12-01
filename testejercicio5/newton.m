function [root, flag, convHist,k] = newton(f, df, x0, tol,...
    maxIt)
    % Determines the root for the inital guess x0
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
    x=x0;
    convHist = zeros(maxIt, 1);
    for k=1:maxIt
    % create new x
    xNew=x−(f(x)/df(x));
    % update solution
    update = xNew − x;
    x = xNew;
    % compute error estimate
    convHist(k) = abs(update);
    % check convergence
    if convHist(k) < tol
    flag = 0;
    break
    end
    end
    root = x;