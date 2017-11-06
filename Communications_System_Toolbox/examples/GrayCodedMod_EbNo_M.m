classdef GrayCodedMod_EbNo_M < testconsole.SystemBasicAPI 
%GrayCodedMod_EbNo_M Gray coded modulation system
%   H = GrayCodedMod_EbNo_M returns a Gray coded QAM modulation system
%   with Eb/No and M as test parameters.

%   Copyright 2009 The MathWorks, Inc.

    %===========================================================================
    % Test Parameters
    properties
        EbNo = 0;
        M = 16;
    end
    
    %===========================================================================
    methods (Access = protected)
        function register(obj) 
            %REGISTER Register the system with a test console
            %    REGISTER(H) registers test parameters and test probes of the
            %    system, H, with a test console.

            registerTestParameter(obj,'EbNo',0,[-50 50]);
            registerTestParameter(obj,'M',16,[2 1024]);
        
            registerTestProbe(obj,'TxBits')   
            registerTestProbe(obj,'RxBits')   
        end  
    end
    
    %===========================================================================
    methods
        function obj = GrayCodedMod_EbNo_M
            %GrayCodedModulation Construct a Gray coded modulation system
            
            obj.Description = 'Gray coded modulation (Eb/No, M)';
        end
        
        %-----------------------------------------------------------------------
        function reset(obj)
            %RESET   Reset the system
            %   RESET(H) resets the internal states of the system, H.
        end
        
        %-----------------------------------------------------------------------
        function setup(obj)
            %SETUP   Initialize the system
            %   SETUP(H) gets current test parameter value(s) from the test
            %   console and initializes system, H, accordingly.
        end
        
        %-----------------------------------------------------------------------
        function run(obj)
            %RUN    Run the system simulation
            %    RUN(H) runs the system simulation for current parameter values
            %    for one iteration.
            
            %% Setup
            % Define parameters.
            % M = 16;           % Size of signal constellation
            M = getTestParameter(obj,'M');
            k = log2(M);        % Number of bits per symbol
            n = 3e4;            % Number of bits to process
            nSamp = 1;          % Oversampling rate
            
            %% Create Modulator and Demodulator
            hMod = modem.qammod(M);         % Create a 16-QAM modulator
            hMod.InputType = 'Bit';         % Accept bits as inputs
            hMod.SymbolOrder = 'Gray';      % Accept bits as inputs
            hDemod = modem.qamdemod(hMod);  % Create a 16-QAM based on the modulator
            
            %% Signal Source
            % Create a binary data stream as a column vector.
            x = randi([0 1],n,1); % Random binary data stream
            setTestProbeData(obj,'TxBits',x);
            
            %% Modulation
            % Modulate using 16-QAM.
            y = modulate(hMod,x);
            
            %% Transmitted Signal
            yTx = y;
            
            %% Channel
            % Send signal over an AWGN channel.
            % EbNo = 10; % In dB
            EbNo = getTestParameter(obj,'EbNo');

            SNR = EbNo + 10*log10(k) - 10*log10(nSamp);
            yNoisy = awgn(yTx,SNR,'measured');
            
            %% Received Signal
            yRx = yNoisy;
            
            %% Demodulation
            % Demodulate signal using 16-QAM.
            z = demodulate(hDemod,yRx);
            setTestProbeData(obj,'RxBits',z);

        end
    end
end
