n = 0:23;
rng default
x = exp(1j*2*pi*0.5*n)+exp(1j*2*pi*0.52*n)+ ...
    0.2/sqrt(2)*(randn(size(n))+1j*randn(size(n)));

periodogram(x,rectwin(length(x)),128,1);

[X,R] = corrmtx(x,14,'mod');
[S,F] = pmusic(R,2,[],1,'corr');
plot(F,S,'linewidth',2); set(gca,'xlim',[0.46 0.60]);
grid on; xlabel('Hz'); ylabel('Pseudospectrum');