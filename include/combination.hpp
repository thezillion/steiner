#include "opencv2/opencv.hpp"
#include <string>

class CombinationModule {
    uchar comb(uchar, uchar);

    public:
    void combine(cv::Mat&, cv::Mat&, std::string&);
};