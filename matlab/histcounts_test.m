clc
clear
close all;
restoredefaultpath

u1 = 8.505801979072472e-04;
Ns = 20;
edges = [0 0 0.1 0.1 0.3 0.3 0.3 0.5 0.5 0.8 0.8 0.8 1.0];
values = u1:1/Ns:1;
% [hoge, idx] = histcounts(u1:1/Ns:1, edges);
[hoge, idx] = histc(u1:1/Ns:1, edges);

% 'histc' and 'histcounts' return different results.