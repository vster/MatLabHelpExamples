% Solve a System of Differential Equations
syms f(t) g(t)
S = dsolve(diff(f) == 3*f + 4*g, diff(g) == -4*f + 3*g)
f(t) = S.f
g(t) = S.g

syms f(t) g(t)
[f(t), g(t)] = dsolve(diff(f) == 3*f + 4*g,...
diff(g) == -4*f + 3*g, f(0) == 0, g(0) == 1)

syms x(t) y(t)
A = [1 2; -1 1];
B = [1; t];
Y = [x; y];

S = dsolve(diff(Y) == A*Y + B);
x = S.x
y = S.y

simplify(x)
simplify(y)