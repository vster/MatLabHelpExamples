% minpoly
% Minimal polynomial of matrix

syms x;
A = sym([1 1 0; 0 1 0; 0 0 1]);
minpoly(A, x)

A = sym([1 1 0; 0 1 0; 0 0 1]);
minpoly(A)

A = sym([0 2 0; 0 0 2; 2 0 0]);
P = minpoly(A)

B = [0 2 0; 0 0 2; 2 0 0];
P = minpoly(B)
