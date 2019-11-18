clear
clc
close all;
restoredefaultpath

f = {};

for i = 1:3
    f{end+1} = @(x) (x.^2);
end

for i = 1:size(f,2)
    f{i}(i)
end