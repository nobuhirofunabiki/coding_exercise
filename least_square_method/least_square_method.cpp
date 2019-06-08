#include <iostream>
#include <map>
#include <random>

#include <Eigen/Core>
#include <Eigen/Dense>
#include <Eigen/Geometry>

int main(){

    std::map<unsigned int, Eigen::Vector3d> node;
    std::map<unsigned int, Eigen::Vector3d> target_est;
    std::map<unsigned int, Eigen::Vector3d> target_true;

    node[0] << 18.4224, -0.562895, 3.521;
    node[1] << 9.28725, -0.0562896, 1.71189;
    node[2] << 17.4298, -0.552626, 3.35312;
    node[3] << 18.7063, -0.589602, 3.57433;
    // node[4] << -15.0, 5.0, 8.0;
    // node[5] << 15.0, -2.0, 5.0;

    target_est[0] << 0.2, 0.1, 0.3;

    target_true[0] << 0.0, 0.0, 0.0;

    std::map<unsigned int, double> range_obs;
    std::map<unsigned int, double> range_est;

    // noise of range measurement
    std::random_device seed;
    std::mt19937 engine(seed());
    double mu = 0.0, sigma = 0.01;
    std::normal_distribution<> dist(mu, sigma);

    // Generate range measurement data
    Eigen::Vector3d diff_position;
    for (int i=0; i<node.size(); i++){
        diff_position = target_true[0]-node[i];
        range_obs[i] = diff_position.norm()+dist(engine);
    }

    range_obs[0] = 2.69;
    range_obs[1] = 8.02;
    range_obs[2] = 2.71;
    range_obs[3] = 2.57;

    Eigen::Matrix3d A_ini;
    Eigen::Vector3d b_ini;
    for (int i=0; i<3; i++){
        A_ini(i,0) = 2*(node[i+1].x()-node[0].x());
        A_ini(i,1) = 2*(node[i+1].y()-node[0].y());
        A_ini(i,2) = 2*(node[i+1].z()-node[0].z());
        b_ini(i) = pow(node[i+1].norm(), 2)-pow(node[0].norm(), 2)-pow(range_obs[i+1], 2)+pow(range_obs[0], 2);
    }
    target_est[0] = A_ini.inverse()*b_ini;
    std::cout << "initial estimaite is " << target_est[0] << std::endl;

    double epsilon = 1.0;
    const double epsilon_threshold = 0.00001;
    int count = 0;
    const int count_threshold = 20;
    Eigen::VectorXd delta_range(node.size());
    Eigen::MatrixXd A(node.size(),3);
    Eigen::VectorXd delta_Xu(node.size());
    
    while (epsilon > epsilon_threshold && count < count_threshold){
        for (int i=0; i<node.size(); i++){
            range_est[i] = (target_est[0]-node[i]).norm();
            delta_range(i) = range_obs[i]-range_est[i];
            A(i,0) = (target_est[0].x()-node[i].x())/range_est[i];
            A(i,1) = (target_est[0].y()-node[i].y())/range_est[i];
            A(i,2) = (target_est[0].z()-node[i].z())/range_est[i];
        }
        delta_Xu = (A.transpose()*A).inverse()*A.transpose()*delta_range;
        target_est[0] << target_est[0]+delta_Xu;
        epsilon = delta_Xu.norm();
        count++;
        std::cout << "count=" << count << " : epsilon=" << epsilon << std::endl;

        if (count >= count_threshold){
            std::cout << "Least-squared optimization is not converged within the maximum iteration number." << std::endl;
        }
    }
    std::cout << "Least-squared optimization has finished." << std::endl;
    std::cout << "Final estimate is " << target_est[0] << std::endl; 
    return 0;
}

