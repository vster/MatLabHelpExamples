M = 16;                     % Alphabet size
x = randi([0 M-1],5000,1);  % Message signal
Nsamp = 4;                  % Oversampling rate

% Use 16-QAM modulation.
hMod = modem.qammod(M);
hDemod = modem.qamdemod(hMod);


% Create a scatter plot and show constellation
scatterPlot = commscope.ScatterPlot('SamplesPerSymbol',1,...
    'Constellation',hMod.Constellation);
scatterPlot.PlotSettings.Constellation = 'on';

% Modulate
y = modulate(hMod,x);

% Follow with rectangular pulse shaping.
ypulse = rectpulse(y,Nsamp);

% Transmit signal through an AWGN channel.
ynoisy = awgn(ypulse,10,'measured');

% Create scatter plot from noisy data.
update(scatterPlot,ynoisy)

% Downsample at the receiver.
ydownsamp = intdump(ynoisy,Nsamp);

% Demodulate to recover the message.
z = demodulate(hDemod,ydownsamp);

% Check symbol error rate.
[num,rt] = symerr(x,z)