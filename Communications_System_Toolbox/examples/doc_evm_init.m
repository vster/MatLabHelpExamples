function paramEVM = doc_evmex
% helper function for EVM Measurements in an EDGE System 

% Copyright 2008 The MathWorks, Inc.

%% Error Vector Magnitude (EVM)
% The error vector magnitude (EVM) is a measure of the difference between a
% reference waveform, which is the error-free modulated signal, and the
% actual transmitted waveform.  EVM is used to quantify the modulation
% accuracy of a transmitter.  

%% System Parameters
% An EDGE system has the following system parameters.  

Tnormal = 6/1625000;     % Normal symbol duration in seconds

%%
% The EDGE standard specifies that the measurements are performed during the
% useful part of the burst, excluding tail bits, over at least 200 bursts.
% To account for filter delays, we include 9 more symbols in the simulation
% of the transmitted symbol.  We chose to oversample the transmitted signal
% by four.  We assume an SNR of 60 dB to account for transmitter and test
% hardware imperfections.
Nsamp = 4;
burstLen1 = 174+78+174;  % Number of symbols in the useful part of the burst
burstLen2 = burstLen1+9; % Number of symbols in the burst
numBursts = 200;         % Number of bursts

%Nsamp  = 4;              % Number of samples that represents a symbol
Fs = Nsamp/Tnormal;      % Final sampling rate

% Phase rotation
phi = 67.5; % 3pi/8

% SNR
SNR = 60;

%% Initialization
% We use 'User-defined' symbol order for the MODEM.PSKMOD object
% to create the required symbol mapping.  The 8-PSK symbols are continuously
% rotated with $$3\pi/8$ radians per symbol before pulse shaping.
%
% We use a helper function to compute the filter
% coefficients and use a direct-form FIR digital filter, DFILT.DFFIR, to
% create the pulse shaping filter.  We normalize the filter to obtain
% unity gain at the main tap.

% Create a linearized GMSK pulse shaping filter
c0 = commEDGE_getLinearizedGMSKPulse(Nsamp);
c0 = c0/max(c0);

%% 
% *Measurement filter*
%
% The standard defines the measurement filter as a raised
% cosine filter with a roll-off factor of 0.25.  We use the
% FDESIGN.PULSESHAPING object to create this filter.  Since the window is
% defined over 7.5 symbol durations, we design the filter to be eight
% symbols long.  The measurement filter is windowed by multiplying its
% impulse response by a raised cosine window.  We use a helper function to
% create the window.

% Design a raised cosine filter with roll off factor 0.25
Nsym = 8;       % Filter order in symbols
beta = 0.25;    % Roll-off factor
measFiltDef = fdesign.pulseshaping(Nsamp, 'Raised Cosine', ...
    'Nsym,Beta', Nsym, beta, Nsamp/Tnormal);
hMeasFilt = design(measFiltDef);

% Apply the window and normalize the filter gain
w = commEDGE_getRaisedCosineWindow(Nsamp);
hMeasFilt.Numerator = hMeasFilt.Numerator.*w;
c1 = hMeasFilt.Numerator;


% Calculate delays
refSigDelay = (length(c0) - 1) / 2;
delayXUptoS = (length(c1) - 1)/2;
rcvSigDelay = refSigDelay + delayXUptoS;
%% Creat Structure and store parameters
paramEVM = struct('Tnormal', Tnormal, 'Nsamp', Nsamp, 'burstLen1', burstLen1, 'burstLen2', burstLen2,...
                  'numBursts', numBursts, 'phi', phi, 'SNR', SNR, 'c0', c0,...
                   'c1', c1, 'refSigDelay', refSigDelay, 'rcvSigDelay', rcvSigDelay);



function c0 = commEDGE_getLinearizedGMSKPulse(Nsamp)
% commEDGE_getLinearizedGMSKPulse Design a pulse shaping filter for EDGE system
% as defined in [1].  This filter is a linearised GMSK pulse, i.e. the main
% component in a Laurant decomposition of the GMSK modulation.
%
% c0 = commEDGE_getLinearisezGMSKPulse(Nsamp) design a filter with Nsamp samples
% per symbol and returns in c0.
%
% Reference 1: 3GPP TS 45.004 v7.2.0, GSM/EDGE Radio Access Network; Modulation,
% Release 7

delta = 1/Nsamp;

% First calculate S(t) for 0<=t<=8T.  Note that we are using normalized time.
cnt = 1;
s = zeros(1, ceil(8/delta)+1);
for t = 0:delta:4
    s(cnt) = sin(pi*intg(t, delta));
    cnt = cnt + 1;
end    
for t = delta:delta:4
    s(cnt) = sin(pi/2 - pi*intg(t, delta));
    cnt = cnt + 1;
end

%  Calculate c0
s0 = s(1:5*Nsamp+1);
s1 = s(1+Nsamp:6*Nsamp+1);
s2 = s(1+2*Nsamp:7*Nsamp+1);
s3 = s(1+3*Nsamp:8*Nsamp+1);
c0 = s0.*s1.*s2.*s3;

%===============================================================================
% Helper functions
function x = intg(t, delta)
% Calculate integral 0 to t of g(t)
if t
    n = 0:delta/10:t;
    g = (1/(2))*(Q(2*pi*0.3*(n-5/2)/(sqrt(log(2)))) - Q(2*pi*0.3*(n-3/2)/(sqrt(log(2)))));
    x = trapz(n, g);
else
    x = 0;
end
%-------------------------------------------------------------------------------
function y = Q(x)
% Calcualte Q function using complementary error function
y = 0.5*erfc(x/sqrt(2));


function w = commEDGE_getRaisedCosineWindow(Nsamp)
% commEDGE_getRaisedCosineWindow Design a rasied cosine window for modulation
% accuracy measurement of an EDGE signal as defined in [1].  This window has a
% raised cosine shape.
%
% W = commEDGE_getRaisedCosineWindow(Nsamp) design a filter with Nsamp samples
% per symbol and returns in W.
%
% Reference 1: 3GPP TS 45.005 v8.1.0, GSM/EDGE Radio Access Network; Radio
% transmission and reception, Release 8


Tnormal = 6/1625000;     % Normal sysmbol duration in seconds


% Cerate time and window vectors
t = 0:Tnormal/Nsamp:4*Tnormal;
w = size(t);

% Calculate the right half of the window
w(t<1.5*Tnormal) = 1;
tIdx = find((t>=1.5*Tnormal)&(t<3.75*Tnormal));
w(tIdx) = 0.5*(1+cos(pi*(t(tIdx)-1.5*Tnormal)/(2.25*Tnormal)));
w(t>=3.75*Tnormal) = 0;

% Add the left half
w = [w(end:-1:1) w(2:end)];

%% Selected Bibliography
% [1] 3GPP TS 45.004, "Radio Access Network; Modulation," Release 7,
% v7.2.0, 2008-02
% [2] 3GPP TS 45.005, "Radio Access Network; Radio transmission and
% reception," Release 8, v8.1.0, 2008-05
% [3] Laurent, Pierre, "Exact and Approximate Construction of Digital Phase
% Modulations by Superposition of Amplitude Modulated Pulses (AMP)," IEEE
% Trans. Comm., Vol. COM-34, No. 2, Feb. 1986, pp. 150-160. 