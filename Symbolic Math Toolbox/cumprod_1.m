% cumprod

% Cumulative Product of a Vector
V = 1./factorial(sym([1:5]))
prod_V = cumprod(V)

% Cumulative Product of Each Column in a Symbolic Matrix
syms x y
A = sym([0, 1, 2; 3, 4, 5; 1, 2, 3])
B = [x, 2*x + 1, 3*x + 2; 1/y, y, 2*y]

productA = cumprod(A)
productB = cumprod(B)

% Cumulative Product of Each Row in a Symbolic Matrix
syms x y
A = sym([0, 1, 2; 3, 4, 5; 1, 2, 3])
B = [x, 2*x + 1, 3*x + 2; 1/y, y, 2*y]

productA = cumprod(A,2)
productB = cumprod(B,2)

