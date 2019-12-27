%% Test code for 'mvnpdf' function
% Multivariate normal probability density function
% ref: https://www.mathworks.com/help/stats/mvnpdf.html

clc
clear
close all;
restoredefaultpath

NUM_VAR = 65;

vec = ones(NUM_VAR,1);
mu = zeros(NUM_VAR,1);
Sigma = zeros(NUM_VAR, NUM_VAR); % Covariance matrix (not standard deviation)
for i = 1:NUM_VAR
    Sigma(i,i) = 1.^1;
end
rng('default')
P1 = mvnpdf(vec, mu, Sigma);


Sigma(1,1) = 10.^10;
P1_1 = mvnpdf(vec, mu, Sigma);
for i = 1:20
    Sigma(i,i) = 10.^10;
end

NUM_VAR2 = 45;
vec2 = ones(NUM_VAR2,1);
mu2 = zeros(NUM_VAR2,1);
Sigma2 = zeros(NUM_VAR2, NUM_VAR2); % Covariance matrix (not standard deviation)
for i = 1:NUM_VAR2
    Sigma2(i,i) = 1.^1;
end
rng('default')
P2 = mvnpdf(vec2, mu2, Sigma2);

