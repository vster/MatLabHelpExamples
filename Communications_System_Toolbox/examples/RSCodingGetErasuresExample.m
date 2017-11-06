function erasuresVector = RSCodingGetErasuresExample(inputData, numErasures)
%   RSCodingGetErasuresExample
%   Find erasures vector for various doc examples.
%
%   This MATLAB file is in support of doc examples and may be removed in a later
%   release.
%
%   erasuresVector = getErasuresRSCodingDemo(inputData, numErasures) finds a
%   vector of indices, that point to the numErasures worst performance
%   symbols in inputData. Then it creates an output vector, erasuresVector,
%   of length length(inputData) with the elements corresponding to the worst
%   case symbol indices set to one and all other elements set to zero.

%   Copyright 2010-2014 The MathWorks, Inc.

collapsedData = abs([real(inputData) imag(inputData)]);

collapsedData = abs(collapsedData - 4);
collapsedData = abs(collapsedData - 2);
collapsedData = abs(collapsedData - 1);
collapsedData = max(collapsedData,[],2);
[~, idx] = sort(collapsedData);
erasuresIdx = idx(end-numErasures+1: end);

erasuresVector = zeros(length(inputData),1);
erasuresVector(erasuresIdx) = 1;
