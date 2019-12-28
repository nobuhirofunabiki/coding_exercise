classdef SubClass < SuperClass
    properties (SetAccess = protected)
        value_sub
    end

    methods
        function obj = SubClass(args)
            obj@SuperClass(args);
            obj.value_sub = args.value_sub;
            obj.checkArguments(args);
        end
    end
    
    methods(Access = private)
        function checkArguments(this, args)
            disp("Check the constructor arguments of SubClass");
        end
    end
end