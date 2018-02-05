% Solve Univariate Equations
syms x
solve(x^2 - 1)
solve(x^2 + 4*x + 1 == 0)

syms x
solve(x^4 + 1 == 2*x^2 - 1)

% Solve Multivariate Equations
syms a b c x
solve(a*x^2 + b*x + c == 0, a)
solve(a*x^2 + b*x + c == 0, b)

syms a b c x
S=solve(a*x^2 + b*x + c == 0)
pretty(S)

% Solve a System of Equations Returning Solutions as a Structure Array
syms x y
S = solve(x + y == 1, x - 11*y == 5)
S = [S.x S.y]

% Solve a System of Equations Assigning the Solutions to Variables
syms a u v
[solutions_a, solutions_u, solutions_v] =...
 solve(a*u^2 + v^2 == 0, u - v == 1, a^2 + 6 == 5*a)
solutions = [solutions_a, solutions_u, solutions_v]
pretty(solutions)

% Specify the Order of Returned Solutions
syms a b
[b, a] = solve(a + b == 1, 2*a - b == 4, b, a)

% Return Numeric Solutions
syms x
solve(sin(x) == x^2 - 1)

ezplot(sin(x), -2, 2)
hold on
ezplot(x^2 - 1, -2, 2)
hold off

evalin(symengine, 'numeric::solve(sin(x) = x^2 - 1, x = 0..2)')

% Return Parameterized Solutions
syms x
solve(sin(1/sqrt(x)) == 0, x)
solve(sin(1/x) == 0, x)

% Return Real Solutions
syms x
solve(x^5 == 3125, x)

solve(x^5 == 3125, x, 'Real', true)

% Return One Solution
syms x
solve(sin(x) + cos(2*x) == 1, x)

solve(sin(x) + cos(2*x) == 1, x, 'PrincipalValue', true)

% Apply Simplification Rules That Shorten the Result
syms x
solve(x^(7/2) + 1/x^(7/2) == 1, x)

solve(x^(7/2) + 1/x^(7/2) == 1, x,...
'IgnoreAnalyticConstraints', true)

% Ignore Assumptions on Variables
syms x positive
solve(x^2 + 5*x - 6 == 0, x)
solve(x^2 + 5*x - 6 == 0, x, 'IgnoreProperties', true)
syms x clear

% Specify Maximal Degree of Polynomials for Which the Solver Uses Explicit Formulas
syms x a
solve(x^4 + 2*x + a == 0, x)
s = solve(x^4 + 2*x + a == 0, x, 'MaxDegree', 4);
pretty(s)




















