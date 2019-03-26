#include <iostream>
#include <string>

#include <opencv2/opencv.hpp>
#include <gif_lib.h>
#include "lib/timer.hpp"

#include "include/combination.hpp"
#include "include/reversing.hpp"

using namespace cv;

int main() {
    Mat img1 = imread("./1.webp"), img2 = imread("./2.webp"), res, rev;

    std::string outpath = "./result.webp", revpath = "./reverse.webp";

    CombinationModule cm;
    res = cm.combine(img1, img2, outpath);

    Mat img3 = imread(outpath);

    ReversingModule rm;
    rev = rm.reverse(img3, revpath);

    imshow("Result", res);
    imshow("Reverse", rev);

    waitKey(0);

}