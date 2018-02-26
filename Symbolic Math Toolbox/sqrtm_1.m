% sqrtm
% Matrix square root

A = [2 -2 0; -1 3 0; -1/3 5/3 2];
X = sqrtm(A)

A = sym([2 -2 0; -1 3 0; -1/3 5/3 2]);
X = sqrtm(A)

isAlways(X^2 == A)

A = vpa(sym([0 0; 0 5/3]), 100);
[X,resnorm] = sqrtm(A)