% Solving Algebraic Equations
clear
syms x
xsol = solve(x^4 + x^3 - x == 1, x)
xsol(xsol == real(xsol))

solve(sin(x) == 1, x)

% Solving Systems of Algebraic Equations
% The solve function can also be used to solve systems of equations. 
% Simply specify the system of equations and the variables to solve for.
clear
syms x y
[x2, y2] = solve(y + x^2 == 1, x - y == 10)

% As with an individual equation, if a system has an infinite number 
% of solutions, the solver returns only one solution.
[x3, y3] = solve(exp(x + y) == 1, x - y == 1)

% In some cases, you may be able to express the system of equations in matrix form.
A = [1 2; 3 4];
b = [5 6]';
x = A\b

% You can use the 'sym' command to solve the system exactly.
sym(A)\b

% Solving Ordinary Differential Equations (ODEs)
% You can solve various types of ordinary differential equations using 
% the dsolve function. For example, you can solve a simple 2nd order linear ODE.
clear
syms y(t)
D2y = diff(y,2);
Dy = diff(y);
dsolve(D2y + Dy + y == 0)

% You can specify initial conditions or boundary conditions along with an ODE.
ysol = dsolve(D2y == 2*t/Dy, y(0) == 0, Dy(0) == 1)

% You can visualize the solution to your differential equation using the ezplot function.
ezplot(ysol)



