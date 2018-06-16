#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "color.hpp"

TEST_CASE("BinLateral filter") {
  cv::Mat img = cv::imread("../CR7.png");
  img = color::blockColorRegions(img);
  cv::imshow("window", img);
  cv::waitKey();
} // TEST_CASE
