function ploteye(x, nSamp, varargin)
%PLOTEYE Plot line-based eye diagram
%   PLOTEYE(X, NSAMP) generates an eye diagram of signal X, where each
%   symbol is represented with NSAMP samples. The eye diagram traces two
%   symbol periods.  NSAMP must be a positive real integer.  X can be
%   a real or complex vector.  If X is a real vector, PLOTEYE generates one
%   eye diagram.  If X is a complex vector, PLOTEYE generates two eye
%   diagrams, one for the real (in-phase) signal and one for the imaginary
%   (quadrature) signal.  PLOTEYE plots X with the first point and every
%   NSAMPth point thereafter centered on the horizontal axis.
%
%   PLOTEYE(X, NSAMP, NSYM) generates an eye diagram that traces NSYM
%   symbol periods.  NSYM must be a positive real integer.
%
%   See also PLOT, COMMSCOPE.EYEDIAGRAM, COMMSCOPE, COMMSCOPE/TYPES.

%   Copyright 2007 The MathWorks, Inc.

% Check if X is valid
[M N] = size(x);
if ( (N~=1) && (M~=1) )
    error('comm:ploteye:XNotVector', 'Input X must be a vector.');
end

% Check if NSAMP is valid
if ( ~isreal(nSamp) || (round(nSamp)~=nSamp) || (nSamp <= 0) || ...
        ischar(nSamp) || ~isscalar(nSamp) || isinf(nSamp) || isnan(nSamp) )
    error('comm:ploteye:NonPositiveNSamp', ['NSAMP must be a finite ' ...
        'positive real integer.']);
end

% Check if NSYM is defined
if ( nargin < 3 )
    % Not defined, set to default
    nSym = 2;
elseif ( nargin == 3 )
    % Defined
    nSym = varargin{1};
elseif ( nargin > 3 )
    error('comm:ploteye:TooManyInputs','Too many input arguments.')
end

% Check if NSYM is valid
if ( ~isreal(nSym) || (round(nSym)~=nSym) || (nSym <= 0) || ...
        ischar(nSym) || ~isscalar(nSym) || isinf(nSamp) || isnan(nSamp) )
    error('comm:ploteye:NonPositiveNSym', ['NSYM must be a finite positive ' ...
        'real integer.']);
end

% Determine the maximum and minimum amplitude values
maxAmp = ceil(max(max(real(x)), max(imag(x))));
minAmp = floor(min(min(real(x)), min(imag(x))));

% Calculate available number of traces
sampsPerTrace = nSym*nSamp;
numTraces = floor(length(x) / sampsPerTrace);

% Calculate the delay value to place the first sample at the center of the
% eye diagram
delay = round(sampsPerTrace/2)+1;

% Create an eye diagram object
eyescope = commscope.eyediagram( ...
    'MinimumAmplitude', minAmp, ...
    'MaximumAmplitude', maxAmp, ...
    'SamplingFrequency', 1, ...
    'SamplesPerSymbol', nSamp, ...
    'SymbolsPerTrace', nSym, ...
    'MeasurementDelay', delay, ...
    'PlotType', '2D Line', ...
    'NumberOfStoredTraces', numTraces, ...
    'RefreshPlot', 'off');

% Update the eye diagram data
update(eyescope, x);

% Export the eye diagram data
[eyec eyel] = exportdata(eyescope);

% Calculate time axis in term of symbols
t = 0:1/nSamp:sampsPerTrace/nSamp;

% Plot the eye diagram.  If X is real, then create one axis.  Otherwise
% create one axis for the in-phase component and one for the quadrature.
if isreal(x)
    figure('Position', figposition([10 40 25 30]));

    plot(t, eyel, 'b');
    title('Eye Diagram');
    xlabel('Time (Symbols)'); ylabel('Amplitude'); grid on;
else
    figure('Position', figposition([10 40 25 45]));

    subplot(211); plot(t, real(eyel), 'b');
    title('Eye Diagram for In-Phase Signal');
    xlabel('Time (Symbols)'); ylabel('Amplitude'); grid on;

    subplot(212); plot(t, imag(eyel), 'b');
    title('Eye Diagram for Quadrature Signal');
    xlabel('Time (Symbols)'); ylabel('Amplitude'); grid on;
end

%--------------------------------------------------------------------------
% [EOF]