function  y=Encode_Modulate(u)
%codegen
persistent hConvEncoder hModulator 
if isempty(hConvEncoder)
%  System objects
    hConvEncoder=comm.ConvolutionalEncoder(...
        'TerminationMethod','Terminated');
    hModulator = comm.PSKModulator('ModulationOrder',4, ...
        'PhaseOffset',pi/4, ...
        'BitInput',true);
end
% Apply functionality
    u1 = step(hConvEncoder, u);                                              % Convolutional Encoder
    y = step(hModulator, u1);                                                   % QPSK Modulator
  