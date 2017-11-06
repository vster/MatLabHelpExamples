function z=MIMO_DecoderM(u, y1,y2)
%#codegen
persistent hMIMOdecoder
if isempty(hMIMOdecoder)
    hMIMOdecoder=comm.OSTBCCombiner('NumTransmitAntennas', 2,...
        'NumReceiveAntennas',1);
end
[LEN,Tx]=size(y1);
tmp=complex(zeros(LEN,Tx,2));
tmp(:,:,1)=y1;
tmp(:,:,2)=y2;
z=step(hMIMOdecoder,u,tmp);
