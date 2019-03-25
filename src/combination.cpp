#include <string>
#include "opencv2/opencv.hpp"
#include "../include/combination.hpp"

using namespace cv;

uchar CombinationModule::comb(uchar x, uchar y) {
    int rzeros = 240; // 11110000
    return (x & rzeros) + (y>>4);
}

void CombinationModule::combine(Mat& img1, Mat& img2, std::string& outpath) {
    Vec3b intensity1, intensity2;

    Mat result(img1.rows, img1.cols, CV_8UC3, Scalar(255, 255, 255));

    for (int i = 0; i<img1.rows; i++) {
        for (int j = 0; j<img1.cols; j++) {
            intensity1 = img1.at<Vec3b>(Point(j, i));
            intensity2 = img2.at<Vec3b>(Point(j, i));

            result.at<Vec3b>(i, j)[0] = comb(intensity1.val[0], intensity2.val[0]);
            result.at<Vec3b>(i, j)[1] = comb(intensity1.val[1], intensity2.val[1]);
            result.at<Vec3b>(i, j)[2] = comb(intensity1.val[2], intensity2.val[2]);
        }
    }

    imwrite(outpath, result);
}