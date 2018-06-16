/** @file color.hpp
 @author Luigi Minardir Ferreira Maia 17/0017141
 @date 06/26/2018
 @brief File of color image filter.
 @copyright GNU Public License.
*/

#ifndef COLOR_HPP_
#define COLOR_HPP_

#include <opencv2/opencv.hpp>

namespace color {

/** Produce a blockish color reagions using a image as source.
 *
 * The colors are repeatedly smoothed to create homogenous color
 regions. The colors in these regions are then requantized at a
 lower quantization.
 @param src source image.
 @return An image with blockish color regions.
 @pre \var src must be in [0 to 256] BGR color space.
*/
cv::Mat blockColorRegions(const cv::Mat& src);

} // namespace color
#endif // COLOR_HPP_
