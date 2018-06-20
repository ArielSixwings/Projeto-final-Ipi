/** @file color.cpp
 @author
 @date
 @brief
 *
 @copyright GNU Public License.
*/

#include "color.hpp"

#include <vector>
#include <cmath>

namespace color {

namespace {

double imageColourfulness(const cv::Mat& src) {
  std::vector<cv::Mat> channels;
  cv::Mat rg; // |R - G|
  cv::Mat yb; // |0.5 * (R + G) - B|
  cv::split(src, channels);
  cv::absdiff(channels[1], channels[2], rg);
  cv::absdiff(0.5 * (channels[1] + channels[2]), channels[0], yb);
  cv::Scalar _rg_mean, _rg_stddev;
  cv::Scalar _yb_mean, _yb_stddev;
  cv::meanStdDev (rg, _rg_mean, _rg_stddev);
  cv::meanStdDev (yb, _yb_mean, _yb_stddev);
  double rg_mean = _rg_mean[0], rg_stddev = _rg_stddev[0];
  double yb_mean = _yb_mean[0], yb_stddev = _yb_stddev[0];
  double color_mean = std::sqrt(rg_mean * rg_mean + yb_mean + yb_mean);
  double color_stddev = std::sqrt(rg_stddev * rg_stddev + yb_stddev * yb_stddev);
  double colourfuness = color_stddev + 0.3 * color_mean;
  std::cout << "colourfuness = " << colourfuness << '\n';
  return colourfuness;
}

std::tuple<int, int, int, double, double, int, int> defineConstants(
    const cv::Mat& src) {
  double colourfuness = imageColourfulness(src);
  bool to_resize = (std::sqrt(src.rows * src.cols) > 1000)? true : false;
  int interations = 10 + colourfuness/10;
  int neighboorhood = 9;
  double sigma_color = 685/colourfuness;
  double sigma_space = 6;
  int kernel = 7;
  int color_factor = 10 + colourfuness/10;
  return std::forward_as_tuple(
           to_resize, interations, neighboorhood,
           sigma_color, sigma_space,
           kernel = 7,
           color_factor);
} // defineConstants()

}// namespace

cv::Mat blockColorRegions(const cv::Mat& src) {
  bool to_resize;
  int interations, neighboorhood;
  double sigma_color, sigma_space;
  int kernel;
  int color_factor;
  std::tie(to_resize, interations, neighboorhood, sigma_color, sigma_space,
           kernel, color_factor) = defineConstants(src);
  std::cout << "to_resize = " << to_resize << '\n';
  std::cout << "interations = " << interations << '\n';
  std::cout << "neighboorhood = " << neighboorhood << '\n';
  std::cout << "sigma_color = " << sigma_color << '\n';
  std::cout << "sigma_space = " << sigma_space <<'\n';
  std::cout << "kernel = " << kernel << '\n';
  std::cout << "color_factor = " << color_factor << '\n';
  cv::Mat filtered;
  cv::pyrDown(src, filtered, cv::Size(src.cols/2, src.rows/2));
  for (int i = 0; i < interations; ++i) {
    cv::Mat aux; // The funtion bilateralFilter doesn't work inplace, that is
                 //why I need to create and destroy this aux varible.
    cv::bilateralFilter(filtered, aux, neighboorhood, sigma_color, sigma_space);
    filtered = aux.clone();
  } // for (i)
  cv::pyrUp(filtered, filtered, cv::Size(src.cols, src.rows));
  cv::medianBlur(filtered, filtered, kernel);
  for (int r = 0; r < filtered.rows; ++r) {
    for (int c = 0; c < filtered.cols; ++c) {
      auto pixel = filtered.at<cv::Vec3b>(r, c);
      pixel[0] = int(pixel[0]/color_factor) * color_factor;
      pixel[1] = int(pixel[1]/color_factor) * color_factor;
      pixel[2] = int(pixel[2]/color_factor) * color_factor;
      filtered.at<cv::Vec3b>(r, c) = pixel;
    } // for (r)
  }  // for (c)
  return filtered ;
} // blockColorRegions()

} // namespace color
