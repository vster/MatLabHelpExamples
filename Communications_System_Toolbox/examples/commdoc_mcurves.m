%% Varying Parameters and Managing a Set of Simulations
% This example, described in the Getting Started chapter of the
% Communications Toolbox documentation, aims to solve the following
% problem:
%
% Modify the modulation example in Modulating a Random Signal
% (COMMDOC_MOD) so that it computes the BER for alphabet sizes (M)
% of 4, 8, 16, and 32 and for integer values of EbNo between
% 0 and 7. For each value of M, plot the BER as a function of
% EbNo using a logarithmic scale for the vertical axis.

% Copyright 1996-2011 The MathWorks, Inc.

%% Initial Setup
MVec = [4 8 16 32]; % Values of M to consider
EbNoVec = 0:7;      % Values of EbNo to consider
n = 3e4;            % Number of bits to process
nSamp = 1;          % Oversampling rate

%% Create Modulator and Demodulator
% Create RectangularQAMModulator  and RectangularQAMDemodulator System
% objects.
hMod = comm.RectangularQAMModulator('BitInput', true);         
hDemod = comm.RectangularQAMDemodulator ('BitOutput', true);  

%% Create AWGNChannel System object
% Create an AWGNChannel System object and set its NoiseMethod property to
% 'Signal to noise ratio (SNR)'.
hChan = comm.AWGNChannel('NoiseMethod', 'Signal to noise ratio (SNR)');

%% Create ErrorRate calculator System object
% Create a ErrorRate calculator System object to compare decoded bits to
% the original transmitted bits.
hErrorCalc = comm.ErrorRate;

%% Preallocate space for results.
berVec = zeros(3, length(EbNoVec),length(MVec)); 

%% Simulation loops
for idxM = 1:length(MVec)
    %% Setup
    % Define parameters.
    M = MVec(idxM); % Size of signal constellation
    release(hMod); release(hDemod); release(hChan);
    hMod.ModulationOrder = M;     % Set modulator constellation size
    hDemod.ModulationOrder = M;   % Set demodulator constellation size
    k = log2(M);    % Number of bits per symbol
    for idxEbNo = 1:length(EbNoVec)
        reset(hErrorCalc)
        %% Signal Source
        % Create a binary data stream as a column vector.
        x = randi([0 1],n,1); % Random binary data stream
        
        %% Modulation
        % Modulate signal.
        y = step(hMod,x);
        
        %% Transmitted Signal
        yTx = y;
        
        %% Channel
        % Calculate and set the 'SNR' and 'SignalPower' property of the
        % AWGNChannel object and send signal over the AWGN channel.
        EbNo = EbNoVec(idxEbNo); % In dB
        SNR = EbNo + 10*log10(k) - 10*log10(nSamp);
        hChan.SNR = SNR;
        hChan.SignalPower = (yTx' * yTx)/ length(yTx);
        yNoisy = step(hChan, yTx);
        
        %% Received Signal
        yRx = yNoisy;
        
        %% Demodulation
        % Demodulate signal.
        z = step(hDemod,yRx);
        
        %% BER Computation
        % Compare x and z to obtain the number of errors and
        % the bit error rate.
        berVec(:,idxEbNo,idxM)=step(hErrorCalc,x,z);
        
    end % End of loop over EbNo values

    %% Plot a Curve.
    markerchoice = '.xo*';
    plotsym = [markerchoice(idxM) '-']; % Plotting style for this curve
    semilogy(EbNoVec,berVec(1,:,idxM),plotsym); % Plot one curve.
    drawnow; % Update the plot instead of waiting until the end.
    hold on; % Make sure next iteration does not remove this curve.
end % End of loop over M values

%% Complete the plot.
title('Performance of M-QAM for Varying M');
xlabel('EbNo (dB)'); ylabel('BER');
legend('M = 4','M = 8','M = 16','M = 32',...
   'Location','SouthWest');