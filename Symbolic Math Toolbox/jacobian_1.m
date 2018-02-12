% jacobian
% Jacobian of a Vector Function
syms x y z
jacobian([x*y*z, y^2, x + z], [x, y, z])

jacobian([x*y*z, y^2, x + z], [x; y; z])

% Jacobian of a Scalar Function
syms x y z
jacobian(2*x + 3*y + 4*z, [x, y, z])

gradient(2*x + 3*y + 4*z, [x, y, z])

% Jacobian with Respect to a Scalar
syms x y
jacobian([x^2*y, x*sin(y)], x)

diff([x^2*y, x*sin(y)], x)