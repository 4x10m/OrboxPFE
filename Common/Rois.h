//
// Created by age2pierre on 30/01/17.
//

#ifndef PROJECT_ROIS_H
#define PROJECT_ROIS_H

#include <opencv2/opencv.hpp>
#include <opencv2/core.hpp>

class Rois {
private:
    // self and parend attribute
    int selfId;
    int parentId;
    int boundRectHeight;
    int boundRectWidth;

private:
    int boundRectX;
    int boundRectY;
    std::string colorPicPath;
    std::string maskPicPath;
    std::string dataPath;
    cv::Mat colorMat;
    cv::Mat maskMat;
    std::vector<cv::Point> contour;

    // objects class attributes
    int classId;
    std::string className;

    // contour features attributes
    float contourPerimeter = -1;
    float contourArea = -1;
    float contourCircularity = -1;
    float minH = -1;
    float minW = -1;

    std::vector<cv::Point> getContour();

    void MatToVector(const cv::Mat &in, std::vector<float> &out);

public:
    // Constructors
    Rois(std::string path, std::string dataPath);

    Rois(cv::Mat color, cv::Mat mask, int X, int Y, std::vector<cv::Point> contour, int selfId);

    int getSelfId() const { return selfId; }

    int getClassId() const { return classId; }

    int setClassId(int p) { classId = p; }

    int getParentId() const { return parentId; }

    int getBoundRectHeight() const { return boundRectHeight; }

    int getBoundRectWidth() const { return boundRectWidth; }

    int getBoundRectX() const { return boundRectX; }

    int getBoundRectY() const { return boundRectY; }

    void readFromFile(std::string);

    void writeToFile(std::string);

    float getPerimeter();

    float getArea();

    float getCircularity();

    float getMinRectHeight();

    float getMinRectWidth();

    std::vector<float> calcHueHist(int numberOfBar,  double normUpBound);

    cv::Mat getColorMat() const { return colorMat; }
};

#endif //PROJECT_ROIS_H
