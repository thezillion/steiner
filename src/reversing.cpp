#include <string>
#include "opencv2/opencv.hpp"
#include "../include/reversing.hpp"

using namespace cv;

uchar ReversingModule::rev(uchar x) {
    uchar rzeros = 15; // 00001111
    x &= rzeros;
    return x<<4;
}

void ReversingModule::reverse(Mat& input, std::string& outpath) {
    Mat reverse(input.rows, input.cols, CV_8UC3, Scalar(255, 255, 255));
    Vec3b intensity_result;

    for (int i = 0; i<input.rows; i++) {
        for (int j = 0; j<input.cols; j++) {
            intensity_result = input.at<Vec3b>(Point(j, i));

            reverse.at<Vec3b>(i, j)[0] = rev(intensity_result.val[0]);
            reverse.at<Vec3b>(i, j)[1] = rev(intensity_result.val[1]);
            reverse.at<Vec3b>(i, j)[2] = rev(intensity_result.val[2]);
        }
    }

    imwrite(outpath, reverse);
}