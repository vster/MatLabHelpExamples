classdef DPSKModulation < testconsole.SystemBasicAPI 
%DPSKModulation Differential phase shift keying (DPSK) modulation system
%   H = DPSKModulation returns a differential phase shift keying modulation
%   system with Eb/No, modualtion order (M), and Doppler shift as test
%   parameters.

%   Copyright 2009 The MathWorks, Inc.

    %=======================================================================
    % Test Parameters
    properties
        %EbNo    Bit energy to noise power spectral density ratio
        EbNo = 10;
        %M       Modulation Order
        M = 4;
        %MaxDopplerShift Maximum Doppler shift (Hz)
        MaxDopplerShift = 0;
    end
    
    %=======================================================================

    % Internal variables
    properties (Access = private)
        SNR
        Modulator
        Demodulator
        Channel
        FrameLength = 2e5;
    end
    
    %=======================================================================
    methods (Access = protected)
        function register(obj) 
            %REGISTER Register the system with a test console
            %    REGISTER(H) registers test parameters and test probes of the
            %    system, H, with a test console.

            registerTestParameter(obj,'EbNo',0,[-50 50]);
            registerTestParameter(obj,'M',4,[2 1024]);
            registerTestParameter(obj,'MaxDopplerShift',0, [0 1000]);
        
            registerTestProbe(obj,'TxBits')   
            registerTestProbe(obj,'RxBits')   
        end  
    end
    
    %=======================================================================
    methods
        function obj = DPSKModulation
            %DPSKModulation Construct a DPSK modulation system
            
            obj.Description = 'DPSK modulation';

            %Create Channel
            obj.Channel = rayleighchan;
            obj.Channel.MaxDopplerShift = obj.MaxDopplerShift;
            obj.Channel.ResetBeforeFiltering = 0;
            
            % Create modulator/demodulator objects
            obj.Modulator = modem.dpskmod('M', obj.M);
            obj.Modulator.InputType = 'Bit';
            obj.Demodulator = modem.dpskdemod(obj.Modulator);
        end
        
        %-------------------------------------------------------------------
        function reset(obj)
            %RESET   Reset the system
            %   RESET(H) resets the internal states of the system, H.

            reset(obj.Channel);
            reset(obj.Modulator);
            reset(obj.Demodulator);
        end
        
        %-------------------------------------------------------------------
        function setup(obj)
            %SETUP   Initialize the system
            %   SETUP(H) gets current test parameter value(s) from the test
            %   console and initializes system, H, accordingly.
            
            nSamp = 1;      % Oversampling rate
            numSym = 1e4;   % Number of symbols to process
            
            % Get simulation value for M and calculate k
            obj.M = getTestParameter(obj,'M');
            k = log2(obj.M);          % Number of bits per symbol
            obj.Modulator.M = obj.M;
            obj.Demodulator.M = obj.M;
            obj.FrameLength = k*numSym;
            
            % Get simulation value for EbNo and calculate SNR
            obj.EbNo = getTestParameter(obj,'EbNo');
            obj.SNR = obj.EbNo + 10*log10(k) - 10*log10(nSamp);
            
            % Get simulation value for maximum Doppler shift
            obj.Channel.MaxDopplerShift = ...
                getTestParameter(obj,'MaxDopplerShift');
        end
        
        %-------------------------------------------------------------------
        function run(obj)
            %RUN    Run the system simulation
            %    RUN(H) runs the system simulation for current parameter
            %    values for one iteration.
            
            %% Signal Source
            % Create a binary data stream as a column vector.
            x = randi([0 1],obj.FrameLength,1);
            % Log transmitted data to a probe
            setTestProbeData(obj,'TxBits',x);
            
            %% Modulation
            % Modulate
            y = modulate(obj.Modulator,x);
            
            %% Transmitted Signal
            yTx = y;
            
            %% Channel
            % Send signal over an AWGN channel.
            % Pass through channel
            chOut = filter(obj.Channel,yTx);
            yChan = awgn(chOut,obj.SNR,'measured');
            
            %% Received Signal
            yRx = yChan;
            
            %% Demodulation
            % Demodulate
            z = demodulate(obj.Demodulator,yRx);
            % Log received data to a probe
            setTestProbeData(obj,'RxBits',z);
        end
    end
end
