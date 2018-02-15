% symsum
% Evaluate the Sum of a Series
syms k
symsum(k)
symsum(1/k^2)

% Evaluate the Sum of a Series Specifying Bounds
syms k
symsum(k^2, 0, 10)
symsum(1/k^2,1,Inf)

syms k
symsum(k^2, [0, 10])
symsum(1/k^2, [1; Inf])

% Evaluate the Sum of a Series Specifying the Summation Index and Bounds
syms k x
symsum(x^k/sym('k!'), k, 0, Inf)