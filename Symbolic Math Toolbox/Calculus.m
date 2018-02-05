clear
% To manipulate a symbolic variable, create an object of type SYM.
x = sym('x')

% Once a symbolic variable is defined, you can use it to build functions. 
% EZPLOT makes it easy to plot symbolic expressions.
f(x) = 1/(5+4*cos(x))
ezplot(f)

% Evaluate the function at x=pi/2 using math notation.
f(pi/2)

% Many functions can work with symbolic variables. For example, DIFF differentiates a function.
f1 = diff(f)
ezplot(f1)

% DIFF can also find the Nth derivative. Here is the second derivative.
f2 = diff(f,2)
ezplot(f2)

% INT integrates functions of symbolic variables. The following is an 
% attempt to retrieve the original function by integrating the second derivative twice.
g = int(int(f2))
ezplot(g)

% At first glance, the plots for f and g look the same. Look carefully, 
% however, at their formulas and their ranges on the y-axis.
subplot(1,2,1)
ezplot(f)
subplot(1,2,2)
ezplot(g)

% e is the difference between f and g. It has a complicated formula, but its graph looks like a constant.
e = f - g
subplot(1,1,1)
ezplot(e)

% To show that the difference really is a constant, simplify the equation. 
% This confirms that the difference between them really is a constant.
e = simplify(e)
ezplot(e)