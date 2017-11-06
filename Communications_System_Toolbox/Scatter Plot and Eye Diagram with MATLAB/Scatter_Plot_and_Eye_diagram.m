%% Scatter Plot

% Set the RRC filter parameters.

span = 10;          % Filter span
rolloff = 0.2;      % Rolloff factor
sps = 8;            % Samples per symbol

% Create the filter coefficients using the rcosdesign function.

filtCoeff = rcosdesign(rolloff, span, sps);

% Generate random symbols for an alphabet size of 4.

rng('default')
data = randi([0 3],5000,1);

% Apply QPSK modulation.

dataMod = pskmod(data, 4, pi/4);

% Filter the modulated data.

txSig = upfirdn(dataMod,filtCoeff, sps);

% Calculate the SNR for an oversampled QPSK signal.

EbNo = 20;
snr = EbNo + 10*log10(2) - 10*log10(sps);

% Add AWGN to the transmitted signal.

rxSig = awgn(txSig,snr,'measured');

% Apply the RRC receive filter.

rxSigFilt = upfirdn(rxSig, filtCoeff, 1, sps);

% Demodulate the filtered signal.

dataOut = pskdemod(rxSigFilt, 4, pi/4, 'gray');

% Use the scatterplot function to show scatter plots of the signal before and after filtering.

h = scatterplot(sqrt(sps) * txSig(sps*span+1:end-sps*span), sps, 0, 'g.');
hold on
scatterplot(rxSigFilt(span+1:end-span), 1, 0, 'kx', h)
scatterplot(dataMod, 1, 0, 'r*', h)
legend('Transmit Signal','Received Signal','Ideal','location','best')

%% Eye Diagram

% Display the eye diagram for two symbol periods.

eyediagram(txSig(sps*span+1:end-sps*span), 2*sps)

% Change the rolloff factor to visualize its effect on the eye diagram 
% as its value is increased.

rolloff = 0.5;

% Generate new filter coefficients.

filtCoeff = rcosdesign(rolloff, span, sps);

% Apply the RRC filter.

txSig = upfirdn(dataMod,filtCoeff, sps);

% Display the eye diagram. You can see that the eye is more "open" when 
% the filter rolloff factor is increased.

eyediagram(txSig(sps*span+1:end-sps*span), 2*sps, 1, 0, 'r')



