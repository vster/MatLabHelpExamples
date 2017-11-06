% Copyright 2006 The MathWorks, Inc.

if(~exist('hPhaseNoise256QAM')||(exist('hPhaseNoise256QAM')&&~ishandle(hPhaseNoise256QAM)))
    % create only one figure
    openfig ('commphasenoise_256qam.fig');
    hPhaseNoise256QAM = gcf;
end
