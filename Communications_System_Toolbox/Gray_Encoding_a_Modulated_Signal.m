% Create 8-PSK Gray encoded modulator
hMod = modem.pskmod('M',8,'SymbolOrder','Gray');
% Create a scatter plot
scatterPlot = commscope.ScatterPlot('SamplesPerSymbol',1,...
    'Constellation',hMod.Constellation);
% Show constellation
scatterPlot.PlotSettings.Constellation = 'on';
scatterPlot.PlotSettings.ConstellationStyle = 'rd';
% Add symbol labels
hold on;
k=log2(hMod.M);
for jj=1:hMod.M
        text(real(hMod.Constellation(jj))-0.15,imag(hMod.Constellation(jj))+0.15,...
        dec2base(hMod.SymbolMapping(jj),2,k));
end
hold off;