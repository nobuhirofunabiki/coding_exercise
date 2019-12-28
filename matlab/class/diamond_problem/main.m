% (references)
% https://www.mathworks.com/matlabcentral/answers/93189-how-does-matlab-solve-the-diamond-problem-in-multiple-inheritance
% https://blogs.mathworks.com/developer/2015/06/08/diamond-of-death/

clc
clear
close all
restoredefaultpath

args.base_property = 0;
args.derived_1_property = 1;
args.derived_2_property = 2;
args.derived_derived_property = 3;

object = DerivedDerivedClass(args);