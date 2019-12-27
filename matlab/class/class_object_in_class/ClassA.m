classdef ClassA < handle
    properties (SetAccess = private)
        property_a
    end

    methods
        function obj = ClassA(args)
            disp("ClassA constructor is called");
            obj.property_a = args.property_a;
        end
    end
end