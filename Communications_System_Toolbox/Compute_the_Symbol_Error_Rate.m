% Create a random digital message
M = 16;                     % Alphabet size
x = randi([0 M-1],5000,1);  % Random symbols

% Use 16-QAM modulation.
hMod = modem.qammod(M);
hDemod = modem.qamdemod(hMod);

% Create a scatter plot and show constellation
scatterPlot = commscope.ScatterPlot('SamplesPerSymbol',1,...
    'Constellation',hMod.Constellation);
scatterPlot.PlotSettings.Constellation = 'on';

% Modulate
y = modulate(hMod,x);

% Transmit signal through an AWGN channel.
ynoisy = awgn(y,20,'measured');

% Create scatter plot from noisy data.
update(scatterPlot,ynoisy);

% Demodulate ynoisy to recover the message.
z=demodulate(hDemod,ynoisy);

% Check symbol error rate.
[num,rt] = symerr(x,z)