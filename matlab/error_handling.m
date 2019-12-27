clc
clear
close all;
restoredefaultpath

m = 2;
if (m ~= 2)
    % Throw error and display message
    % error("m is not 1");
end
n = 1;
disp("pass error");

% Throw error if the condition is false
assert(m == 2, "m is not 1");

A = [0 0; 1 1];
size_A = size(A);
assert(isequal(size(A), [2 1]), "A is NOT correct size matrix");