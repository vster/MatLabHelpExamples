function commsccc_setup
%SCCC_SETUP Set up workspace variables for the SCCC Iterative Decoding example commsccc.mdl

% Copyright 1996-2011 The MathWorks, Inc.
% $Revision: 1.1.8.1 $  $Date: 2014/01/20 21:45:15 $

% Get parameter names and values from mask
mask_ws_vars = get_param([gcs '/Model Parameters'],'maskwsvariables');

if ~isempty(mask_ws_vars)
    for i = 1:length(mask_ws_vars),
        curr_var = mask_ws_vars(i).Name;
        evalin('base',[curr_var ' = ' num2str(mask_ws_vars(i).Value) ';']);
    end      
else
    % add this part so that the model can be executed from MATLAB command
    % line
    evalin('base','SCCC_EbN0dB = 1.5;');
    evalin('base','SCCC_len     = 1024;');
    evalin('base','SCCC_numIter = 6;');
    evalin('base','SCCC_seed = 19046;');
end    
    % Set up other parameters in the MATLAB workspace as needed
    evalin('base','SCCC_trellis1 = poly2trellis(3, [7 5],7);');                   % rate 1/2
    evalin('base','SCCC_trellis2 = poly2trellis([3 3],[7 0 5;0 7 6],[7 7]);');    % rate 2/3
    
    evalin('base','SCCC_R1 = log2(SCCC_trellis1.numInputSymbols)/log2(SCCC_trellis1.numOutputSymbols);');
    evalin('base','SCCC_R2 = log2(SCCC_trellis2.numInputSymbols)/log2(SCCC_trellis2.numOutputSymbols);');
    evalin('base','SCCC_R  = SCCC_R1 * SCCC_R2;');          % Overall code rate = 1/2*2/3 = 1/3
    
    evalin('base','SCCC_Es = 1;');                          % Signal energy is 1         
    evalin('base','SCCC_Eb = SCCC_Es/SCCC_R;');             % Bit energy is 3
    
    evalin('base','SCCC_EbN0 = 10.0.^(0.1*SCCC_EbN0dB);');  % Convert from dB to linear
    evalin('base','SCCC_N0   = SCCC_Eb/SCCC_EbN0;');        % Calculate N0
    evalin('base','SCCC_Var  = SCCC_N0/2;');                % Calculate channel noise variance
    
    evalin('base','clear SCCC_R1 SCCC_R2 SCCC_EbN0 SCCC_Es SCCC_Eb SCCC_N0;');
    
