#include <iostream>
#include <Eigen/Dense>
#include <Eigen/Geometry>
using namespace Eigen;

int main()
{
    Vector3d v1(0,1,0);
    Vector3d v2(0,0,1);

    Quaterniond q = Quaterniond::FromTwoVectors(v1, v2);

    Eigen::Matrix3d R = q.normalized().toRotationMatrix();
    std::cout << "R=" << std::endl << R << std::endl;

    Vector3d v3;
    v3 = R*v1; // v3 should be the same with v2
    std::cout << "v3 = \n" << v3 << std::endl;
}