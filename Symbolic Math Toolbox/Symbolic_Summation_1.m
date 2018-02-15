% Symbolic Summation

syms x k
s1 = symsum(1/k^2, 1, inf)
s2 = symsum(x^k, k, 0, inf)