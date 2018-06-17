#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "color.hpp"

TEST_CASE ("All") {
  SECTION ("Lena") {
    cv::Mat img = cv::imread("../lena.jpg");
    cv::imshow("Lena", img);
    img = color::blockColorRegions(img);
    cv::imshow("Color blocked Lena", img);
  }
  SECTION ("CR7") {
    cv::Mat img = cv::imread("../CR7.png");
    cv::imshow("CR7", img);
    img = color::blockColorRegions(img);
    cv::imshow("Color blocked CR7", img);
  }
  SECTION ("Cat") {
    cv::Mat img = cv::imread("../Cat.jpg");
    cv::imshow("Cat", img);
    img = color::blockColorRegions(img);
    cv::imshow("Color blocked Cat", img);
  }
  cv::waitKey();
} // TEST_CASE
