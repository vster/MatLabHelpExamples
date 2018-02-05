%% Integration
%
% This example shows how to compute definite and indefinite integrals
% using Symbolic Math Toolbox(TM).
%
% Copyright 2010-2012 The MathWorks, Inc.

%% Indefinite Integrals
% To integrate a mathematical expression f means to find an expression F
% such that the first derivative of F is f. Integration is a more
% complicated task than differentiation. In contrast to differentiation,
% there is no general algorithm for computing integrals of an arbitrary
% expression. For example, create the following expression f:
syms x; 
f = sin(x)/x
%%
% You can visualize an expression by using the plot command. For example,
% create the plot of f for the values of variable x from -15
% to 15:
ezplot(f, [-15, 15])
%%
% To compute integrals use the int function. When you integrate an
% expression, the result often involves much more complicated functions
% than those you use in the original expression. For example, the integral 
% of a simple trigonometric expression sin(x)/x is a special function (the
% sine integral function):
F = int(f, x)
%%
% You also can visualize the sine integral function:
ezplot(F, [-15, 15])
%% Definite Integrals
% The int function also allows you to compute definite integrals. To
% compute a definite integral, specify the upper and lower limits of the
% integration interval. For example, you can compute the integral of f =
% sin(x)/x for the interval from -15 to 15:
int(f, x, -15, 15)
%%
% You also can use infinities when specifying one or both sides of the
% integration interval. For example, you can integrate the function f 
% from 0 to positive infinity:
int(f, x, 0, inf)
%%
% Integrating f from negative infinity to 0 gives the same result:
int(f, x, -inf, 0)
%%
% You can also compute the integral of f over the set of all real numbers:
int(f, x, -inf, inf)

displayEndOfDemoMessage(mfilename)
