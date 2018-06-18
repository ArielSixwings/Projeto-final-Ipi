#ifndef RECOMBINE_H
#define RECOMBINE_H

#include <opencv2/opencv.hpp>

namespace recombine {

cv::Mat Recombine(cv::Mat& color, cv::Mat& edges,double factor);

}// namespace recombine

#endif