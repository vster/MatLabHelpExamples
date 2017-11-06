% REMOVEPHASEAMBIGUITYMSKSIGNALRECOVERY Compensate for the 90 degree phase
% ambiguity after applying the phase recovery algorithm. This script is used
% in commMSKSignalRecovery.m.

%   Copyright 2010 The MathWorks, Inc.
%   $Revision: 1.1.8.1 $ $Date: 2013/12/27 02:23:10 $


% Squaring should result in approx 1 for symbols at 0 or 180 degrees and
% approx -1 for symbols at 90 and 270 degrees
sig2 = rxSym.^2;
% Negate "off-beat" values. The result should be approx 1 or -1: 1 if the
% on-beat symbols are at 0 or 180 degrees and the off-beat symbols are at 90
% or 270 degrees; otherwise, -1.
sig2(2:2:end) = -sig2(2:2:end);
% If the average of the result of the above operations is negative, a 90
% degree phase shift is required.
phAdj = (pi/2)*(mean(real(sig2))<0);
rxSym = rxSym * exp(1i*phAdj);
