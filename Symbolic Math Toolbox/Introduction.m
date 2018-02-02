x = sym('x');

% You can combine the statements
a = sym('a'); 
t = sym('t'); 
x = sym('x'); 
y = sym('y');
% into one statement involving the "syms" function.
syms a t x y

% You can use symbolic variables in expressions and as arguments to many different functions.
r = x^2 + y^2
theta = atan(y/x)
e = exp(i*pi*t)

% It is sometimes desirable to use the "simplify" function to transform expressions into more convenient forms.
f = cos(x)^2 + sin(x)^2
f = simplify(f)

% Derivatives and integrals are computed by the "diff" and "int" functions.
diff(x^3)
int(x^3)
int(exp(-t^2))

[int(x^a), int(a^x), int(x^a,a), int(a^x,a)]

pi = sym('pi')
delta = sym('1/10')
s = sym('sqrt(2)')

t = 1/10, t = 0.1

sym(t,'f')
sym(t,'r')

%If no simple rational approximation can be found, an expression of the 
% form p*2^q with large integers p and q reproduces the floating point value exactly.
sym(1+sqrt(5),'r')

sym(t,'e')

digits(15)
sym(t,'d')

digits(25)
sym(t,'d')

n = 4;
A = x.^((0:n)'*(0:n))
D = diff(log(A))



