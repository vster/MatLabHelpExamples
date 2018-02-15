% cumsum
% Cumulative Sum of a Vector
V = 1./factorial(sym([1:5]))
sum_V = cumsum(V)

% Cumulative Sum of Each Column in a Symbolic Matrix
syms x y
A = sym([0, 1, 2; 3, 4, 5; 1, 2, 3])
B = [x, 2*x + 1, 3*x + 2; 1/y, y, 2*y]

sumA = cumsum(A)
sumB = cumsum(B)

% Cumulative Sum of Each Row in a Symbolic Matrix
syms x y
A = sym([0, 1, 2; 3, 4, 5; 1, 2, 3])
B = [x, 2*x + 1, 3*x + 2; 1/y, y, 2*y]

sumA = cumsum(A,2)
sumB = cumsum(B,2)