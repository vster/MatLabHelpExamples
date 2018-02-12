% Assumptions on Symbolic Objects
% Default Assumption
syms z
assumptions(z)

% Set Assumptions
syms x
assume(x >= 0)
assumeAlso(x,'integer')

a = sym('a', 'real');
b = sym('b', 'real');
c = sym('c', 'positive');

syms a b real
syms c positive

% Check Existing Assumptions
assumptions(x)

assumptions

% Delete Symbolic Objects and Their Assumptions
syms x
assume(x,'real')

clear x

syms x real
clear x
syms x
solve(x^2 + 1 == 0, x)

syms x clear



