load mtlb
[Pxx,F] = pwelch(mtlb,hamming(256),128,1024,Fs);
plot(F,10*log10(Pxx))

ORDER = 14;
[Pxx,F] = pyulear(mtlb,ORDER,1024,fs);
plot(F,10*log10(Pxx))