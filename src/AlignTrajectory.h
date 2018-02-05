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
    Eigen::Matrix4d calculateATE(std::vector<Eigen::Matrix4d> gt, std::vector<Eigen::Matrix4d>, float& ate);

    std::vector<Eigen::Matrix4d> calculateRPE(std::vector<Eigen::Matrix4d> gt, std::vector<Eigen::Matrix4d> es, int iDelta, double& rpe_rmse);

private:
    Eigen::MatrixXd ATERotation(Eigen::MatrixXd model, Eigen::MatrixXd data);

    double ATEScale(Eigen::MatrixXd model, Eigen::MatrixXd data, Eigen::MatrixXd rotation);

    Eigen::Vector3d ATETranslation(Eigen::MatrixXd model, Eigen::MatrixXd data, double scale, Eigen::MatrixXd rotation, float& error);

};

#endif
