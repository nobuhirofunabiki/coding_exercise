classdef ClassB < handle
    properties (SetAccess = private)
        object_ClassA
        property_b
    end

    methods
        function obj = ClassB(args)
            disp("ClassB constructor is called");
            obj.object_ClassA = ClassA(args);
            obj.property_b = args.property_b;
        end
    end
end