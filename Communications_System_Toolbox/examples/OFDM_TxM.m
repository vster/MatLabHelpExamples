function y  = OFDM_TxM(u,P)
%#codegen
% OFDM Transmitter includes:
%   Pack data with guards, add DC, reorder
%   IFFT and gain scale - per symbol per antenna port
%  Add cylic prefix - different length across symbols in a slot
%   Serialize subframe per antenna port
N=256;
CP=32;
Offset=28;
width=200;
u2=[P,u]; 
persistent hifft
if isempty(hifft)
    hifft = dsp.IFFT;
end
% input & output dimensions and 
len = size(u,1);
numSymb=3;
slotLen=N+CP;
% Pack data, add DC, and reorder, gurard band
tmp = complex(zeros(N, numSymb));
tmp(Offset+(1:len),      :) =  u2;
tmp=tmp([N/2+1:N,1:N/2]',:);

% IFFT processing
x = step(hifft,tmp);
x2 = x.*(N/sqrt(width));

% For a subframe of data
y = complex(zeros(numSymb*slotLen, 1));
for n = 0:1:numSymb-1
     y(n*slotLen+(1:CP)      ) = x2((N-CP+1:N), n+1);
     y(n*slotLen+CP+(1:N))  = x2(1:N,               n+1);
end