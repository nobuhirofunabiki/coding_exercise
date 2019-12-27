classdef SubSubClass < SubClass
    properties (SetAccess = protected)
        value_subsub
    end

    methods
        function obj = SubSubClass(args)
            obj@SubClass(args);
            obj.value_subsub = args.value_subsub;
            obj.checkArguments(args);
        end
    end

    methods (Access = private)
        function checkArguments(this, args)
            disp("Check the constructor arguments of SubSubClass");
        end
    end
end