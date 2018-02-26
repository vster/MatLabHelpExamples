% charpoly
% Characteristic polynomial of matrix

syms x;
A = sym([1 1 0; 0 1 0; 0 0 1]);
charpoly(A, x)

A = sym([1 1 0; 0 1 0; 0 0 1]);
charpoly(A)

A = sym([1 2; 3 4]);
P = charpoly(A)

B = ([1 2; 3 4]);
P = charpoly(B)