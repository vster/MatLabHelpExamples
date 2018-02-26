% det
% Compute determinant of symbolic matrix

syms a b c d
det([a, b; c, d])

A = sym([2/3 1/3; 1 1])
r = det(A)