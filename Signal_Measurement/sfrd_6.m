rng default
Fs = 44.1e3;
f1 = 9.8e3;
f2 = 14.7e3;
f3 = 19.6e3;
N = 900;
nT = (0:N-1)/Fs;
x = 0.1 + sin(2*pi*f1*nT) + 100e-6*sin(2*pi*f2*nT) ...
        + 30e-6*sin(2*pi*f3*nT) + sqrt(1e-9)*randn(1,N);
% Plot the spectrum and SFDR of the signal. Display its fundamental harmonic and its largest spur.

sfdr(x,Fs);