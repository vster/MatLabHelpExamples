t = 0:1/1000:2;
y = chirp(t,0,1,150);
spectrogram(y,256,250,256,1000,'yaxis')