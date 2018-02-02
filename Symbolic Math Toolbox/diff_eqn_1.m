clear
syms y(t)
D2y = diff(y,2);
Dy = diff(y);
dsolve(D2y - Dy + y == 2)

% You can specify initial conditions or boundary conditions along with an ODE.
ysol = dsolve(D2y == 2*t/Dy, y(0) == 0, Dy(0) == 1)

% You can visualize the solution to your differential equation using the ezplot function.
ezplot(ysol)
