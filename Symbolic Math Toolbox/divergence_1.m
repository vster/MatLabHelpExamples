% divergence
% Divergence of vector field

syms x y z
divergence([x, 2*y^2, 3*z^3], [x, y, z])

syms x y z
divergence(curl([x, 2*y^2, 3*z^3], [x, y, z]), [x, y, z])

syms x y z
f = x^2 + y^2 + z^2;
divergence(gradient(f, [x, y, z]), [x, y, z])


