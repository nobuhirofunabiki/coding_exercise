clc
clear
close all;
restoredefaultpath

m = 1;
if (m ~= 2)
    % Throw error and display message
    % error("m is not 1");
end
n = 1;
disp("pass error");

% Throw error if the condition is false
assert(m == 2, "m is not 1");