load mtlb
ORDER = 14;
[Pburg,F] = pburg(mtlb(1:512),ORDER,1024,fs);
plot(F,10*log10(Pburg))

[Pxx,F] = pyulear(mtlb(1:512),ORDER,1024,fs);
plot(F,10*log10(Pxx))