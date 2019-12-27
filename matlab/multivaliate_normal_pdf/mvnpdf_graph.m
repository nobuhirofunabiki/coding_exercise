%% Test code for 'mvnpdf' function
% Multivariate normal probability density function
% ref: https://www.mathworks.com/help/stats/mvnpdf.html

clc
clear
close all;
restoredefaultpath

mu = [1 -1];
sigma = [0.9 0.4; 0.4 0.3];
rng('default')  % For reproducibility
X = mvnrnd(mu,sigma,1000);
y = mvnpdf(X,mu,sigma);
figure
scatter3(X(:,1),X(:,2),y)
xlabel('X1')
ylabel('X2')
zlabel('Probability Density')