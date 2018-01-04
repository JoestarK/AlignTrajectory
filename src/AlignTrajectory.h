#ifndef ALIGNTRAJECTORY_H
#define ALIGNTRAJECTORY_H

#include <Eigen/Eigen>
#include <iostream>
#include <vector>
#include <mutex>
 

class AlignTrajectory
{
public:
    AlignTrajectory();
   // ~AlignTrajectory();
    Eigen::Matrix4d getAlignment(std::vector<Eigen::Vector3d> gt, std::vector<Eigen::Vector3d>, float& ate);

    bool prepareData(std::vector<Eigen::Vector3d> gt, std::vector<Eigen::Vector3d> es, Eigen::MatrixXd& gtZeroMat, Eigen::MatrixXd& esZeroMat);

    Eigen::MatrixXd getRotation(Eigen::MatrixXd model, Eigen::MatrixXd data);

    double getScale(Eigen::MatrixXd model, Eigen::MatrixXd data, Eigen::MatrixXd rotation);

    Eigen::Vector3d getTranslation(Eigen::MatrixXd model, Eigen::MatrixXd data, double scale, Eigen::MatrixXd rotation, float& error);

};

#endif
