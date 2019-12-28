clc
clear
close all
restoredefaultpath

args.x = 1;
args.y = 1;
object_ = ExampleClass(args);

% If you run the following sentence, it will return an error.
% 'y' is a immutable property
% object_.setY(2);

Y = object_.getY();