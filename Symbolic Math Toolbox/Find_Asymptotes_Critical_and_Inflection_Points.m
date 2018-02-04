% Find Asymptotes, Critical and Inflection Points
% Define a Function

syms x
num = 3*x^2 + 6*x -1;
denom = x^2 + x - 3;
f = num/denom
ezplot(f)
grid

% Find Asymptotes
limit(f, inf)

% To find the vertical asymptotes of f, set the denominator 
% equal to 0 and solve by entering the following command:
roots = solve(denom)

ezplot(f)
hold on % Keep the graph of f in the figure
% Plot horizontal asymptote
plot([-2*pi 2*pi], [3 3],'g')
% Plot vertical asymptotes
plot(double(roots(1))*[1 1], [-5 10],'r')
plot(double(roots(2))*[1 1], [-5 10],'r')
title('Horizontal and Vertical Asymptotes')
hold off

% Find Maximum and Minimum
f1 = diff(f)
f1 = simplify(f1)
pretty(f1)
crit_pts = solve(f1)

ezplot(f)
hold on
plot(double(crit_pts), double(subs(f,crit_pts)),'ro')
title('Maximum and Minimum of f')
text(-5.5,3.2,'Local minimum')
text(-2.5,2,'Local maximum')
hold off

% Find Inflection Point
f2 = diff(f1);
inflec_pt = solve(f2);
double(inflec_pt)

inflec_pt = inflec_pt(1);
pretty(simplify(inflec_pt))

ezplot(f, [-9 6])
hold on
plot(double(inflec_pt), double(subs(f,inflec_pt)),'ro')
title('Inflection Point of f')
text(-7,2,'Inflection point')
hold off





