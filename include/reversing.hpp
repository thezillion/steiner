#include "opencv2/opencv.hpp"
#include <string>

class ReversingModule {
    uchar rev(uchar);

    public:
    cv::Mat reverse(cv::Mat&, std::string&);
};