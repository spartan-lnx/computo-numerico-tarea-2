function [ C,I ] = Figure( f, df, tol,maxIt,reL,reR,imD,imU,stepSize,...
root1, root2, root3,root4,root5,withIter,method,m,d)
    %Determines all the roots for all the inital points using one of the
    %root finding method.
    % INPUT
    % f function of rootfinding problem
    % df the function name or function handle to the derivative of f
    % tol the desired tolerance
    % maxIt maximum number of iterations
    % reL
    % reR
    % imD
    % imU
    % stepSize the step size between the initial points
    % root1−root5 All the roots of the function
    % withIter
    % method 0: Draw the figure with the Relaxed Newton's method.
    % 1: Draw the figure with Newton's method.
    % 2: Draw the figure with the Secant method (x1 determined with
    % Newton).
    % 3: Draw the figure with the Secant method (x0 determined with
    % x0= a+ad+i(b+bd).
    % m Value of m for the Relaxed Newton's method.
    % d Value of d for the Secant method.
    % OUTPUT
    % C Array with the color codes for which initial points end up
    % with which root .
    % I Array with the amount of iterations needed for convergence to
    % the roots.
    k=0;
    l=0;
    for b = [imD:+stepSize:imU]
    k=k+1;
    j=0;
    for a = [reL:+stepSize:reR]
    j = j+1;
    if method == 3;
    [rootCalc,flag,convHist,iter] = secant2(f,a,b,d,tol,maxIt);
    end
    if method == 2;
    [rootCalc,flag,convHist,iter] = secantN(f,df,a+i*b,tol,maxIt);
    end
    if method == 1
    [rootCalc,flag, convHist,iter] = newton(f,df,a+i*b,tol,maxIt);
    end
    if method == 0
    [rootCalc,flag, convHist,iter] = newtonRelaxed(f,df,a+i*b,...
    tol,maxIt,m);
    end
    l=l+1;
    I(l)=iter;
    %Determines which root has been calculated
if abs(rootCalc − root1) <= tol
    c = 6;
    else if abs(rootCalc − root2) <= tol
    c = 26;
    else if abs(rootCalc − root3) <= tol
    c = 36;
    else if abs(rootCalc − root4) <= tol
    c = 46;
    else if abs(rootCalc − root5) <= tol
    c = 56;
    else
    c = 0;
    end
    end
    end
    end
    end
    if withIter == 1 % If used depending on the amount of iterations
    % needed for convergence the color will be darker shade if
    % more iterations are needed.
    if iter < 10
    c = c+4 ;
    end
    if iter < 15 && iter >=10
    c = c+3 ;
    end
    if iter < 20 && iter >=15
    c = c+2 ;
    end
    if iter < 25 && iter >=20
    c = c+1;
    end
    if iter < 30 && iter >=25
    c = c;
    end
    if iter >=30
    c = c−1 ;
    end
    end
    C(k,j)=c;
    end
    end
    end