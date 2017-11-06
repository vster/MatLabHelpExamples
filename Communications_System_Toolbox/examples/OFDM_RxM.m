function y = OFDM_RxM(u)
%#codegen
N=256;
CP=32;
width=200;
Offset=28;
numSymb=3;

x0=reshape(u,numel(u)/numSymb,numSymb);
Index1=CP+(1:N)';
tmp=x0(Index1,:);

% FFT processing
x1 = fft(tmp, N, 1);
x =  (sqrt(width)/N)*x1;

IndexA=Offset+N/2+1:N;
IndexB=1:(N/2-Offset+1);
Index=[IndexA,IndexB]';
% Unpack data, remove DC, and reorder
y=x(Index,:);