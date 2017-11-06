exdata = [
        9007        7750        8162        7717        7792        7836
        8106        6981        7306        7461        6957        6892
        8928        8038        8124        7776        7726        7791
        9137        8422        7870        7925        8106        8129
       10017        8714        9387        8634        8890        9115
       10826        9512        9556        8945        9299        9434
       11317       10120       10093       10078       10625       10484
       10744        9823        9620        9179        9302        9827
        9713        8743        8285        8037        8314        9110
        9938        9129        8433        8488        8850        9070
        9161        8710        8160        7874        8265        8633
        8927        8680        8034        8647        8796        9240];
    
 ts = reshape(exdata,72,1);
 years = linspace(1973,1979,72);
 plot(years,ts,'bo-','markerfacecolor',[0 0 1]); xlabel('Year');
 ylabel('Number of Accidental Deaths'); grid on;
 
 tsdft = fft(ts-mean(ts));
 freq = 0:1/72:1/2;
 plot(freq.*12,abs(tsdft(1:length(ts)/2+1)),'bo-','markerfacecolor',[0 0 1]);
 xlabel('Cycles/Year'); ylabel('Magnitude');
 set(gca,'xtick', [1/6 1 2 3 4 5 6])
 
N = 72;
 freqbin = N/12+1;
 freqbins = [freqbin N-freqbin+2];
 tsfit = zeros(72,1);
 tsfit(freqbins) = tsdft(freqbins);
 tsfit = ifft(tsfit,'symmetric');
 mu = mean(ts);
 tsfit = mu+tsfit;
 
 plot(years,ts,'bo-','markerfacecolor',[0 0 1]); xlabel('Year');
 ylabel('Number of Accidental Deaths'); grid on;
 hold on;
 plot(years,tsfit,'r','linewidth',2);
 legend('Data','Fitted Model');
 
 figure
 resid = ts-tsfit;
 [xc,lags] = xcorr(resid,50,'coeff');
 stem(lags(51:end),xc(51:end),'markerfacecolor',[0 0 1]);
 hold on;
 lconf = -1.96*ones(51,1)/sqrt(72);
 uconf = 1.96*ones(51,1)/sqrt(72);
 plot(lags(51:end),lconf,'r','linewidth',2);
 plot(lags(51:end),uconf,'r','linewidth',2);
 xlabel('Lag'); ylabel('Correlation Coefficient');
 title('Autocorrelation of Residuals');
 
 tsfit2dft = zeros(72,1);
 [Y,I] = sort(abs(tsdft),'descend');
 indices = I(1:6);
 tsfit2dft(indices) = tsdft(indices);
 
 norm(1/sqrt(72)*tsdft,2)/norm(ts-mean(ts),2)
 
 norm(1/sqrt(72)*tsfit2dft,2)/norm(ts-mean(ts),2)
 
 figure
 tsfit2 = mu+ifft(tsfit2dft,'symmetric');
 plot(years,ts,'bo-','markerfacecolor',[0 0 1]); xlabel('Year');
 ylabel('Number of Accidental Deaths'); grid on;
 hold on;
 plot(years,tsfit,'r','linewidth',2);
 plot(years,tsfit2,'k','linewidth',2);
 legend('Data','1 Frequency','3 Frequencies');
 
 figure
 resid = ts-tsfit2;
 [xc,lags] = xcorr(resid,50,'coeff');
 stem(lags(51:end),xc(51:end),'markerfacecolor',[0 0 1]);
 hold on;
 lconf = -1.96*ones(51,1)/sqrt(72);
 uconf = 1.96*ones(51,1)/sqrt(72);
 plot(lags(51:end),lconf,'r','linewidth',2);
 plot(lags(51:end),uconf,'r','linewidth',2);
 xlabel('Lag'); ylabel('Correlation Coefficient');
 title('Autocorrelation of Residuals');
 
 X = ones(72,7);
 X(:,2) = cos(2*pi/72*(0:71))';
 X(:,3) = sin(2*pi/72*(0:71))';
 X(:,4) = cos(2*pi*6/72*(0:71))';
 X(:,5) = sin(2*pi*6/72*(0:71))';
 X(:,6) = cos(2*pi*12/72*(0:71))';
 X(:,7) = sin(2*pi*12/72*(0:71))';
 beta = X\ts;
 tsfit_lm = X*beta;
 max(abs(tsfit_lm-tsfit2))