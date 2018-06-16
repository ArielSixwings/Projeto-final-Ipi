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
const int NEIGHBORHOOD = 4;
const double SIGMA_COLOR = 32;
const double SIGMA_SPACE = 4;
} // namespace bilateralFilter
namespace median {
  const int KERNEL = 7;
} // namespace median
const int REDUCTION_FACTOR = 16;

cv::Mat blockColorRegions(const cv::Mat& src) {
  cv::Mat filtered;
  for (int i = 0; i < 14; ++i) {
    cv::bilateralFilter(src, filtered, bilateral_filter::NEIGHBORHOOD,
                        bilateral_filter::SIGMA_COLOR,
                        bilateral_filter::SIGMA_SPACE);
  } // for (i)
  cv::medianBlur(filtered, filtered, median::KERNEL);
  // Requantize the color palette
  for (int r = 0; r < filtered.rows; ++r) {
    for (int c = 0; c < filtered.cols; ++c) {
      auto pixel = filtered.at<cv::Vec3b>(r, c);
      pixel[0] = int(pixel[0] / REDUCTION_FACTOR) * REDUCTION_FACTOR;
      pixel[1] = int(pixel[1] / REDUCTION_FACTOR) * REDUCTION_FACTOR;
      pixel[2] = int(pixel[2] / REDUCTION_FACTOR) * REDUCTION_FACTOR;
      filtered.at<cv::Vec3b>(r, c) = pixel;
    }
  }
  return filtered ;
} // blockColorRegions()
} // namespace color
