classdef SuperClass < handle
    properties (SetAccess = protected)
        value_super
    end

    methods
        function obj = SuperClass(args)
            obj.value_super = args.value_super;
            obj.checkArguments(args);
        end
    end

    methods(Access = private)
        function checkArguments(this, args)
            disp("Check the constructor arguments of SuperClass");
        end
    end
end