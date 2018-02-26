% adjoint
% Adjoint of symbolic square matrix

syms x y z
A = sym([x y z; 2 1 0; 1 0 2]);
X = adjoint(A)

isAlways(A*X == det(A)*eye(3))

isAlways(det(A)*eye(3) == X*A)

syms a b c d
A = [a b; c d];
invA = adjoint(A)/det(A)

isAlways(invA == inv(A))