classdef DerivedDerivedClass < DerivedClass1 & DerivedClass2
    properties (SetAccess = private)
        derived_derived_property
    end

    methods
        function obj = DerivedDerivedClass(args)
            disp("DerivedDerivedClass constructor is called")
            obj@DerivedClass1(args);
            obj@DerivedClass2(args);
            obj.derived_derived_property = args.derived_derived_property;
        end
    end
end