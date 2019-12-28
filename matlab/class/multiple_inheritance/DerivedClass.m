classdef DerivedClass < BaseClass1 & BaseClass2
    properties (SetAccess = protected)
        variable
    end

    methods (Access = public)
        function obj = DerivedClass(args)
            disp("DerivedClass constructor is called");
            obj@BaseClass1(args);
            obj@BaseClass2(args);
            obj.variable = args.variable;
        end
    end
end