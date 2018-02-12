% laplacian

syms x y t
laplacian(1/x^3 + y^2 - log(t))

syms x y z
f(x, y, z) = 1/x + y^2 + z^3;

L = laplacian(f, [x y z])

syms f(x, y)
divergence(gradient(f(x, y)), [x y])