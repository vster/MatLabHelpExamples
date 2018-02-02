% Perform Symbolic Computations
% Simplify Symbolic Expressions

phi = sym('(1 + sqrt(5))/2');
f = phi^2 - phi - 1

% You can simplify this answer by entering
simplify(f)

% expand
syms x
f = (x ^2- 1)*(x^4 + x^3 + x^2 + x + 1)*(x^4 - x^3 + x^2 - x + 1);
expand(f)

% factor
syms x
g = x^3 + 6*x^2 + 11*x + 6;
factor(g)

% horner
syms x
h = x^5 + x^4 + x^3 + x^2 + x;
horner(h)

% Substitutions in Symbolic Expressions
clear
syms x y
f = x^2*y + 5*x*sqrt(y);
subs(f, x, 3)

% Substitute One Symbolic Variable for Another
subs(f, y, x)

% Substitute a Matrix into a Polynomial
syms x
f = x^3 - 15*x^2 - 24*x + 350;
A = [1 2 3; 4 5 6];
subs(f,A)

% Substitution in a Matrix Sense.
% Create the polynomial:
syms x
f = x^3 - 15*x^2 - 24*x + 350;
% Create the magic square matrix:
A = magic(3)
% Get a row vector containing the numeric coefficients of the polynomial f:
b = sym2poly(f)
% Substitute the magic square matrix A into the polynomial f. 
A^3 - 15*A^2 - 24*A + 350*eye(3)
% The polyvalm command provides an easy way to obtain the same result:
polyvalm(b,A)

%Substitute the Elements of a Symbolic Matrix
clear
syms a b c
A = [a b c; c a b; b c a]
% To replace the (2, 1) element of A with beta and the variable b throughout the matrix with variable alpha, enter
alpha = sym('alpha');
beta = sym('beta');
A(2,1) = beta;
A = subs(A,b,alpha)

% Estimate Precision of Numeric to Symbolic Conversions


