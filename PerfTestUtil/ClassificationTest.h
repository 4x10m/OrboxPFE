//
// Created by age2pierre on 07/02/17.
//

#ifndef PROJECT_CLASSIFICATIONTEST_H
#define PROJECT_CLASSIFICATIONTEST_H

#include <vector>
#include <opencv2/core.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/ml.hpp>
#include "../Common/Rois.h"

#define KNN_KFOLD 100
#define SVM_KFOLD 20

class ClassificationTest {
private:
    void calcMeanAndStDev(std::vector<float> &in, double &mean, double &stdev);

    std::array<std::vector<Rois>, 8> data;

    cv::Ptr<cv::ml::TrainData> fullDataSet;

    std::array<cv::Ptr<cv::ml::TrainData>, KNN_KFOLD> knnTrainData;
    std::array<cv::Ptr<cv::ml::TrainData>, SVM_KFOLD> svmTrainData;
    std::array<cv::Ptr<cv::ml::TrainData>, KNN_KFOLD> knnTestData;
    std::array<cv::Ptr<cv::ml::TrainData>, SVM_KFOLD> svmTestData;

    std::vector<float> vecP, vecA, vecH, vecW;

    double meanA, meanP, meanH, meanW, stDevA, stDevP, stDevH, stDevW;

    std::pair<std::vector<float>::iterator, std::vector<float>::iterator> minMaxA, minMaxP, minMaxH, minMaxW;

    float normValue(float val, float lowerBound, float upperBound);

public:
    ClassificationTest();

    void createDataSet(
            bool enPerimeter, bool enArea, bool enMinH, bool enMinW,
            int totalHistBeam, int truncHistBeam, bool normalize
    );

    void runSimpleKnn(int K);

    void runSimpleSVM(cv::ml::SVM::Types val, cv::ml::SVM::KernelTypes kernelType);

};


#endif //PROJECT_CLASSIFICATIONTEST_H
