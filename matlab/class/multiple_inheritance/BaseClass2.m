classdef BaseClass2 < handle
    properties (SetAccess = immutable)
        % variable
        % -> It's impossible to have the same name property with another base class
    end
    properties (Abstract = true, SetAccess = protected)
        variable
    end

    methods (Access = protected)
        function obj = BaseClass2(args)
            disp("BaseClass2 constructor is called");
            % obj.variable = args.variable;
        end
    end
       
    methods (Access = public)
        function setVariable(this, variable)
            disp("setVariable of BaseClass2 is called");
            this.variable = variable;
        end
    end
end