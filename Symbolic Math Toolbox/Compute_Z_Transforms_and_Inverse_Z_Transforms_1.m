% Compute Z-Transforms and Inverse Z-Transforms
syms p(n) z
eq = p(n + 2) - p(n + 1) - p(n);
Zeq = ztrans(eq, n, z)

syms Pz
Zeq = subs(Zeq,{ztrans(p(n), n, z), p(0), p(1)}, {Pz, 1, 2})

eq = collect(Zeq, Pz)

P = solve(eq, Pz)

p = iztrans(P, z, n);
p = simplify(p)

m = 1:10;
y = double(subs(p,n,m));
plot(m, real(y),'rO')
title('Rabbit Population');
xlabel('years'); ylabel('p');
grid on

