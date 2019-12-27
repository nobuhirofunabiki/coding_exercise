%% Test code for 'mvnpdf' function
% Multivariate normal probability density function
% ref: https://www.mathworks.com/help/stats/mvnpdf.html

clc
clear
close all;
restoredefaultpath

vec0 = [0,0];
vec1 = [1,1];
vec2 = [10000, 10000];
mu = zeros(1,2);
Sigma = 10.^10*eye(2);
rng('default')
P0 = mvnpdf(vec0, mu, Sigma);
P1 = mvnpdf(vec1, mu, Sigma);
P2 = mvnpdf(vec2, mu, Sigma);