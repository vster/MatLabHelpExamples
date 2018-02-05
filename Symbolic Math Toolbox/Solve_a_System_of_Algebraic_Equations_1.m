% Solve a System of Algebraic Equations

syms x y alpha
[sol_x,sol_y] = solve(x^2*y^2 == 0, x-y/2 == alpha)
[sol_x,sol_y] = solve(x^2*y^2 == 1, x-y/2 == alpha)

pretty(sol_x)
pretty(sol_y)

syms u v a
S = solve(u^2 - v^2 == a^2, u + v == 1, a^2 - 2*a == 3)
S.a
s2 = [S.a(2), S.u(2), S.v(2)]
M = [S.a, S.u, S.v]

clear u v x y
syms u v x y
S = solve(x + 2*y == u, 4*x + 5*y == v);
sol = [S.x; S.y]

A = [1 2; 4 5];
b = [u; v];
z = A\b
