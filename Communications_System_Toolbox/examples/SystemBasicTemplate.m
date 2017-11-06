classdef SystemBasicTemplate < testconsole.SystemBasicAPI 
%SystemBasicTemplate Template for creating a system

%   Copyright 2009 The MathWorks, Inc.

    %===========================================================================
    % Test Parameters
    properties         
    end
    
    %===========================================================================
    methods (Access = protected)
        function register(obj) 
            %REGISTER Register the system with a test console
            %    REGISTER(H) registers test parameters and test probes of the
            %    system, H, with a test console.
        end  
    end
    
    %===========================================================================
    methods
        function obj = SystemBasicTemplate
            %SystemBasicTemplate Construct a system
            
            obj.Description = 'System Name';
        end
        
        %-----------------------------------------------------------------------
        function reset(obj)
            %RESET   Reset the system
            %   RESET(H) resets the internal states of the system, H.
        end
        
        %-----------------------------------------------------------------------
        function setup(obj)
            %SETUP   Initialize the system
            %   SETUP(H) gets current test parameter value(s) from the test
            %   console and initializes system, H, accordingly.
        end
        
        %-----------------------------------------------------------------------
        function run(obj)
            %RUN    Run the system simulation
            %    RUN(H) runs the system simulation for current parameter values
            %    for one iteration.
        end
    end
end
