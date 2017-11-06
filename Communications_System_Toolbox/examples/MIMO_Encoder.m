function [y1,y2] = MIMO_Encoder(u)
%#codegen
persistent hMIMOEncoder
if isempty(hMIMOEncoder)
hMIMOEncoder = comm.OSTBCEncoder('NumTransmitAntennas', 2);
end
y=step(hMIMOEncoder,u);
y1=y(:,:,1);
y2=y(:,:,2);