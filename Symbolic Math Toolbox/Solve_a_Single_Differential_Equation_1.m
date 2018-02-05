% Solve a Single Differential Equation

% First-Order Linear ODE
syms y(t)
y(t) = dsolve(diff(y) == t*y)

syms y(t)
y(t) = dsolve(diff(y) == t*y, y(0) == 2)

% Nonlinear ODE
syms x(t)
x(t) = dsolve((diff(x) + x)^2 == 1, x(0) == 0)

% Second-Order ODE with Initial Conditions
syms y(x)
Dy = diff(y);
y(x) = dsolve(diff(y, 2) == cos(2*x) - y, y(0) == 1, Dy(0) == 0);
y(x) = simplify(y)

% Third-Order ODE
syms u(x)
Du = diff(u);
D2u = diff(u, 2);
u(x) = dsolve(diff(u, 3) == u, u(0) == 1, Du(0) == -1, D2u(0) == pi)

% More ODE Examples
syms y(t)
dsolve(diff(y) + 4*y == exp(-t), y(0) == 1)

syms y(x)
dsolve(2*x^2*diff(y, 2) + 3*x*diff(y) - y == 0)

syms y(x)
dsolve(diff(y, 2) == x*y, y(0) == 0, y(3) == besselk(1/3, 2*sqrt(3))/pi)









