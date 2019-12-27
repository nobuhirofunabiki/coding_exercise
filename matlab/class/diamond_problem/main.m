clc
clear
close all
restoredefaultpath

args.base_property = 0;
args.derived_1_property = 1;
args.derived_2_property = 2;
args.derived_derived_property = 3;

object = DerivedDerivedClass(args);