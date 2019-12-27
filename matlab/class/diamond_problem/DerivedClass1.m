classdef DerivedClass1 < BaseClass
    properties (SetAccess = protected)
        derived_1_property
    end

    methods
        function obj = DerivedClass1(args)
            disp("DerivedClass1 constructor is called");
            obj@BaseClass(args);
            obj.derived_1_property = args.derived_1_property;
        end
    end
end