#include "opencv2/opencv.hpp"
#include <string>

class ReversingModule {
    uchar rev(uchar);

    public:
    void reverse(cv::Mat&, std::string&);
};