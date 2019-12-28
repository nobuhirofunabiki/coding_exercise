classdef ExampleClass < handle
    properties (Constant)
        x = 0
    end
    properties (SetAccess = immutable)
        y
    end

    methods (Access = public)
        function obj = ExampleClass(args)
            % obj.x = args.x;
            % -> this does not work...
            obj.y = args.y;
        end
    end

    methods (Access = public)
        function output = getY(this)
            output = this.y;
        end

        function setY(this, arg)
            this.y = arg;
        end
    end
end