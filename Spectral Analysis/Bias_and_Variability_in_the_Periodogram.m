B2 = 1;
A2 = [1 -0.75 0.5];
fvtool(B2,A2);

[H2,W2] = freqz(B2,A2,1e3,1);
max(20*log10(abs(H2)))-min(20*log10(abs(H2)))

fvtool(B2,A2,'analysis','polezero');

B4 = 1;
A4 = [1 -2.7607 3.8106 -2.6535 0.9238];
fvtool(B4,A4);

fvtool(B4,A4,'analysis','polezero');

[H4,W4] = freqz(B4,A4,1e3,1);
max(20*log10(abs(H4)))-min(20*log10(abs(H4)))

rng default;
x = randn(1e3,1);
y2 = filter(B2,A2,x);
y4 = filter(B4,A4,x);
subplot(211)
plot(y2); title('AR(2) Process');
xlabel('Time'); ylabel('Amplitude');
subplot(212);
plot(y4); title('AR(4) Process');
xlabel('Time'); ylabel('Amplitude');

Fs = 1;
NFFT = length(y2);
[psdAR2,Fxx] = periodogram(y2,rectwin(length(y2)),length(y2),1);
psdAR4 = periodogram(y4,rectwin(length(y2)),length(y2),1);
subplot(211)
plot(Fxx,10*log10(psdAR2));
hold on;
plot(W2,20*log10(abs(H2)),'r','linewidth',2);
title('AR(2) PSD and Periodogram');
subplot(212)
plot(Fxx,10*log10(psdAR4));
hold on;
plot(W4,20*log10(abs(H4)),'r','linewidth',2);
xlabel('Hz'); ylabel('dB');
title('AR(4) PSD and Periodogram');

[psdAR4H,Fxx] = periodogram(y4,hamming(length(y4)),NFFT,Fs);
plot(Fxx,10*log10(psdAR4H));
hold on;
plot(W4,20*log10(abs(H4)),'r','linewidth',2);
xlabel('Hz'); ylabel('dB');
title('AR(4) PSD and Periodogram with Hamming Window');
legend('Periodogram with Hamming Window','AR(4) PSD',...
    'Location','NorthEast');

NW = 3.5;
[psdmtm,Fxx] = pmtm(y4,NW,NFFT,Fs);
plot(Fxx,10*log10(psdmtm));
hold on;
plot(W4,20*log10(abs(H4)),'r','linewidth',2);
xlabel('Hz'); ylabel('dB');
legend('Multitaper Estimate','AR(4) PSD', ...
    'Location','NorthEast');