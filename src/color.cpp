/** @file color.cpp
 @author
 @date
 @brief
 *
 @copyright GNU Public License.
*/

#include "color.hpp"

namespace color {

namespace bilateral_filter {
const int ITERATIONS = 20;
const int NEIGHBORHOOD = 12;
const double SIGMA_COLOR = 16;
const double SIGMA_SPACE = 5;
} // namespace bilateralFilter

namespace median {
const int KERNEL = 7;
} // namespace median

const int COLOR_FACTOR = 10 ; /// COLOR_FACTOR = 256/num_colors;

cv::Mat blockColorRegions(const cv::Mat& src) {
  cv::Mat filtered;
  cv::pyrDown(src, filtered, cv::Size(src.cols/2, src.rows/2));
  for (int i = 0; i < bilateral_filter::ITERATIONS; ++i) {
    cv::Mat aux; // The funtion bilateralFilter doesn't work inplace, that is
                 //why I need to create and destroy this aux varible.
    cv::bilateralFilter(filtered, aux, bilateral_filter::NEIGHBORHOOD,
                        bilateral_filter::SIGMA_COLOR,
                        bilateral_filter::SIGMA_SPACE);
    filtered = aux.clone();
  } // for (i)
  cv::pyrUp(filtered, filtered, cv::Size(src.cols, src.rows));
  cv::medianBlur(filtered, filtered, median::KERNEL);
  for (int r = 0; r < filtered.rows; ++r) {
    for (int c = 0; c < filtered.cols; ++c) {
      auto pixel = filtered.at<cv::Vec3b>(r, c);
      pixel[0] = int(pixel[0] / COLOR_FACTOR) * COLOR_FACTOR + COLOR_FACTOR / 2;
      pixel[1] = int(pixel[1] / COLOR_FACTOR) * COLOR_FACTOR + COLOR_FACTOR / 2;
      pixel[2] = int(pixel[2] / COLOR_FACTOR) * COLOR_FACTOR + COLOR_FACTOR / 2;
      filtered.at<cv::Vec3b>(r, c) = pixel;
    } // for (r)
  }  // for (c)
  // Requantize the color palette
  return filtered ;
} // blockColorRegions()

} // namespace color
