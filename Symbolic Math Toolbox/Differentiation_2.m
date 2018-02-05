%% Differentiation
%
% This example shows how to find first and second derivatives
% using Symbolic Math Toolbox(TM).
%
% Copyright 2010-2012 The MathWorks, Inc.

%% First Derivatives: Finding Local Minima and Maxima
% Computing the first derivative of an expression helps you find 
% local minima and maxima of that expression. For example, create 
% the rational expression where the numerator and 
% denominator are polynomial expressions. Before creating a
% symbolic expression, you declare symbolic variables.
% By default, solutions that include imaginary components are included  
% in the result. If you are interested in real 
% numbers only, you can set the assumption that x belongs to the
% set of real numbers. This assumption allows you to avoid complex numbers
% in symbolic solutions and it also can improve performance:
syms x real;
f = (3*x^3 + 17*x^2 + 6*x + 1)/(2*x^3 - x + 3)

%%
% Plotting this expression shows that the expression has horizontal and
% vertical asymptotes, a local minimum between -1 and 0, and a local 
% maximum between 1 and 2:
ezplot(f)
hold on
grid
hold off
%%
% To find a horizontal asymptote, compute the limit of f 
% for x approaching positive and negative infinities. The horizontal 
% asymptote is x = 3/2:
limit(f, x, -inf)
limit(f, x, inf)
%%
% To find a vertical asymptote of f, find the roots of 
% the polynomial expression that represents the denominator of f:
solve(2*x^3 - x + 3, x)
%%
% You can approximate the exact solution numerically by using the double
% function. To access the result of the previous evaluation, use the 
% default variable name ans:
double(ans)
%%
% Now find the local minimum and maximum of f. If the point
% is a local extremum (either minimum or maximum), the first 
% derivative of the expression at that point is equal to zero. To compute 
% the derivative of an expression, use the diff function:
g = diff(f, x)
%%
% To find the local extrema of f, solve the equation g = 0:
solve(g, x)
%%
% And again approximate the exact solution numerically by using the double
% function applied to ans:
double(ans)
%%
% The expression f has a local maximum at 
% x = 1.286 and a local minimum at 
% x = -0.189

%% Second Derivatives: Finding Inflection Points
% Computing the second derivative lets you find inflection points of
% the expression. The most efficient way to compute second or higher-order 
% derivatives is to use the parameter that specifies the order of the
% derivative:
h = diff(f, x, 2)
%%
% To find inflection points of f, solve the equation h = 0.
% The solver cannot solve this equation symbolically. Instead, the
% toolbox calls the numeric solver and calculates floating-point
% approximations of the solutions:
solve(h, x)
%%
% The expression f has two inflection points: x = 1.865 and 
% x = 0.579


displayEndOfDemoMessage(mfilename)
