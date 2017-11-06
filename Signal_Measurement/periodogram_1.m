iq_data=Y;
sampleRate=1/XDelta;

N= length(iq_data);
acquisitionTime=N/sampleRate;
returnedSpan = sampleRate/1.25;

nfft = length(iq_data);
[pxx, f]     = periodogram(iq_data, [], nfft, sampleRate);
p = bandpower(pxx,f,'psd');
freqrange=[-2E5 +2E5];
p2 = bandpower(iq_data,sampleRate,freqrange);
plottingRatio=1.25/acquisitionTime;
pxx_log=10*log10(plottingRatio*10*fftshift(pxx));
pmax=max(pxx_log)+20;
pmin=min(pxx_log);
fmax=max(f);

% axes(handles.axes_spectrum);
plot(f-max(f)/2, 10*log10(plottingRatio*10*fftshift(pxx)), 'm')
% axis([-max(f)/2 max(f)/2 -100 pmax*1.2]);
xlabel('f, Hz');
grid on;

% pxx = pburg(iq_data,10);
[pxx, f]     = spectrogram(iq_data);
plottingRatio=1.25/acquisitionTime;
pxx_log=10*log10(plottingRatio*10*fftshift(pxx));
pmax=max(pxx_log)+20;
pmin=min(pxx_log);
fmax=max(f);

% axes(handles.axes_spectrum);
plot(f-max(f)/2, 10*log10(plottingRatio*10*fftshift(pxx)), 'm')
% axis([-max(f)/2 max(f)/2 -100 pmax*1.2]);
xlabel('f, Hz');
grid on;