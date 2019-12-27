classdef DerivedClass2 < BaseClass
    properties (SetAccess = protected)
        derived_2_property
    end

    methods
        function obj = DerivedClass2(args)
            disp("DerivedClass2 constructor is called")
            obj@BaseClass(args);
            obj.derived_2_property = args.derived_2_property;
        end
    end
end