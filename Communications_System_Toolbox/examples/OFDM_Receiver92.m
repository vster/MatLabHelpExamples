function y = OFDM_Receiver92(u)
%#codegen
N=256;
CP=32;
width=200;
Offset=28;

x0=reshape(u,numel(u)/2,2);
Index1=CP+(1:N)';
tmp=x0(Index1,:);

% FFT processing
x = fft(tmp, N, 1);
x =  x./(N/sqrt(width));

% For a subframe of data
y = complex(zeros(width+1, 2));

% Unpack data, remove DC, and reorder
y(1:(width/2), :) = x(N/2+Offset+1:N, :);
y(width/2+1:width+1, :) = x(1:width/2+1, :);




