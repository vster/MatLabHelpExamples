% Norm of matrix or vector

A = inv(sym(magic(3)));
norm2 = norm(A)

vpa(norm2, 20)

A = inv(sym(magic(3)));
norm1 = norm(A, 1)
normf = norm(A, 'fro')
normi = norm(A, inf)

vpa(norm1, 20)
vpa(normf, 20)
vpa(normi, 20)

syms Vx Vy Vz
V = [Vx; Vy; Vz];
norm1 = norm(V, 1)
norm2 = norm(V)
norm3 = norm(V, 3)

normi = norm(V, inf)
normni = norm(V, -inf)
normf = norm(V, 'fro')


