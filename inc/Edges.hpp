#ifndef EDGES_H
#define EDGES_H

#include <opencv2/opencv.hpp>

namespace edges {

cv::Mat TakeEdges(cv::Mat& image,int lowThreshold, int range);
  
} // namespace edges

#endif
