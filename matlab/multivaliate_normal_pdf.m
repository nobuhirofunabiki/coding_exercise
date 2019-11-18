%% Test code for 'mvnpdf' function
% Multivariate normal probability density function
% ref: https://www.mathworks.com/help/stats/mvnpdf.html

clc
clear
close all;
restoredefaultpath

vec = [1,1];
mu = zeros(1,2);
Sigma = eye(2); % Covariance matrix (not standard deviation)
rng('default')
P = mvnpdf(vec, mu, Sigma);
P_ = multivariate_normal_pdf(vec, mu, Sigma);

function output = multivariate_normal_pdf(x, mu, Sigma)
    output = 1./sqrt((2.*pi)^2*det(Sigma))*exp(...
        -0.5*(x-mu)*inv(Sigma)*(x-mu).');
end