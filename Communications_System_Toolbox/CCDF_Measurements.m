% This example shows how to use the Complementary Cumulative Distribution 
% Function (CCDF) System object to measure the probability of a signal's 
% instantaneous power being greater than a specified level over its average power.

hCCDF = comm.CCDF('PAPROutputPort',true, ...
    'MaximumPowerLimit', 50);

% Create a 64-QAM modulator and an OFDM modulator. The QAM modulated signal 
% will be evaluated by itself and evaluated again after OFDM modulation is applied.

hMod = comm.RectangularQAMModulator('ModulationOrder',64);
hOFDM = comm.OFDMModulator('FFTLength', 256, 'CyclicPrefixLength', 32);

% Determine the input and output sizes of the OFDM modulator object using 
% the info method of the comm.OFDMModulator object.

info(hOFDM)
ofdmInputSize = hOFDM.info.DataInputSize;
ofdmOutputSize = hOFDM.info.OutputSize;

% Set the number of OFDM frames.

numFrames = 20;

% Allocate memory for the signal arrays.

qamSig = repmat(zeros(ofdmInputSize), numFrames, 1);
ofdmSig = repmat(zeros(ofdmOutputSize), numFrames, 1);

% Use the default random number generator to ensure repeatability.

rng default

% Generate the 64-QAM and OFDM signals for evaluation.

for k = 1:numFrames
    % Generate random data symbols
    data = randi([0, 63], ofdmInputSize);
    % Apply 64-QAM modulation
    tmpQAM = step(hMod, data);
    % Apply OFDM modulation to the QAM-modulated signal
    tmpOFDM = step(hOFDM, tmpQAM);
    % Save the signal data
    qamSig((1:ofdmInputSize)+(k-1)*ofdmInputSize(1)) = tmpQAM;
    ofdmSig((1:ofdmOutputSize)+(k-1)*ofdmOutputSize(1)) = tmpOFDM;
end

% Determine the average signal power, the peak signal power, and the PAPR 
% ratios for the two signals. The two signals being evaluated must be the 
% same length so the first 4000 symbols are evaluated.

[Fy, Fx, PAPR] = step(hCCDF, [qamSig(1:4000), ...
    ofdmSig(1:4000)]);

% Plot the CCDF data. Observe that the likelihood of the power of the OFDM 
% modulated signal being more than 3 dB above its average power level is 
% much higher than for the QAM modulated signal.

plot(hCCDF)
legend('QAM','OFDM','location','best')

% Compare the PAPR values for the QAM modulated and OFDM modulated signals.

fprintf('\nPAPR for 64-QAM = %5.2f dB\nPAPR for OFDM = %5.2f dB\n',...
    PAPR(1), PAPR(2))