classdef BaseClass
    properties (SetAccess = protected)
        base_property
    end

    methods
        function obj = BaseClass(args)
            disp("BaseClass constructor is called");
            obj.base_property = args.base_property;
        end
    end
end