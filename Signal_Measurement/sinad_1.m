n = 0:159;
x = cos(pi/4*n)+0.025*sin(pi/2*n);
rng default;
y = cos(pi/4*n)+0.025*sin(pi/2*n)+0.05*randn(size(n));
r = sinad(x)
powfund = 1;
powharm = 0.025^2;
thSINAD = 10*log10(powfund/powharm)