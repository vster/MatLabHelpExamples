% curl
% Curl of vector field

syms x y z
curl([x^3*y^2*z, y^3*z^2*x, z^3*x^2*y], [x, y, z])

syms x y z
f = x^2 + y^2 + z^2;
curl(gradient(f, [x, y, z]), [x, y, z])

syms x y z
V = [x^2*y, y^2*z, z^2*x];
gradient(divergence(V, [x, y, z])) - curl(curl(V, [x, y, z]), [x, y, z])