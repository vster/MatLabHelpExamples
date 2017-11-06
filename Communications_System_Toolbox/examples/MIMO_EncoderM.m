function [y1,y2]=MIMO_EncoderM(u)
%#codegen
persistent hMIMOencoder
if isempty(hMIMOencoder)
    hMIMOencoder=comm.OSTBCEncoder('NumTransmitAntennas', 2);
end
tmp=step(hMIMOencoder,u);
y1=tmp(:,:,1);
y2=tmp(:,:,2);