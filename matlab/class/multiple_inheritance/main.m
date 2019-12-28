clc
clear
close all
restoredefaultpath

args.variable = 1;
object_ = DerivedClass(args);

object_.setVariable(4);

object_.makeValueSquareRoot();