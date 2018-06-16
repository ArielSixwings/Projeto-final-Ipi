#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "color.hpp"

TEST_CASE ("All") {
  SECTION ("Lena") {
    cv::Mat img = cv::imread("../lena.jpg");
    img = color::blockColorRegions(img);
    cv::imshow("Lena", img);
  }
  SECTION ("CR7") {
    cv::Mat img = cv::imread("../CR7.png");
    img = color::blockColorRegions(img);
    cv::imshow("CR7", img);
    cv::waitKey();
  }
} // TEST_CASE
