classdef BaseClass1 < handle
    properties (SetAccess = protected)
        % variable
    end
    properties (Abstract = true, SetAccess = protected)
        variable
    end

    methods (Access = protected)
        function obj = BaseClass1(args)
            disp("BaseClass1 constructor is called");
            % obj.variable = args.variable;
        end
    end

    methods (Access = public)
        function makeValueSquareRoot(this)
            disp("makeValueSquareRoot of BaseClass1 is called");
            this.variable = sqrt(this.variable);
        end
    end
end