% vectorPotential

syms x y z
vectorPotential([x^2*y, -1/2*y^2*x, -x*y*z], [x y z])

syms x y z
f(x,y,z) = 2*y^3 - 4*x*y;
g(x,y,z) = 2*y^2 - 16*z^2+18;
h(x,y,z) = -32*x^2 - 16*x*y^2;
A = vectorPotential([f; g; h], [x y z])

syms x y z
V = [x^2 2*y z];
divergence(V, [x y z])

vectorPotential(V, [x y z])