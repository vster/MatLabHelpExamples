% Load data
load relatedsig.mat;

figure
ax(1) = subplot(311);
plot((0:numel(T1)-1)/Fs1,T1,'k'); ylabel('Template 1'); grid on
ax(2) = subplot(312);
plot((0:numel(T2)-1)/Fs2,T2,'r'); ylabel('Template 2'); grid on
ax(3) = subplot(313);
plot((0:numel(S)-1)/Fs,S,'b'); ylabel('Signal'); grid on
xlabel('Time (secs)');
linkaxes(ax(1:3),'x')
axis([0 1.61 -4 4])