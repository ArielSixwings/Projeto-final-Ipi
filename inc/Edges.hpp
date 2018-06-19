#ifndef EDGES_H
#define EDGES_H

#include <opencv2/opencv.hpp>

namespace edges {

cv::Mat TakeEdges(cv::Mat& image,int lowThreshold, int range);

cv::Mat Dilate(cv::Mat& source);

cv::Mat EdgeFilter(cv::Mat& source,int threshold);

void TakeNegative(cv::Mat& source);
  
} // namespace edges

#endif
