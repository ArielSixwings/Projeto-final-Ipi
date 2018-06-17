#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "color.hpp"

TEST_CASE ("All") {
  SECTION ("Lena") {
    cv::Mat img = cv::imread("imagens/lena.jpg", CV_LOAD_IMAGE_COLOR);
    cv::imshow("Lena", img);
    img = color::blockColorRegions(img);
    cv::imshow("Color blocked Lena", img);
  }
  SECTION ("CR7") {
    cv::Mat img = cv::imread("imagens/CR7.png", CV_LOAD_IMAGE_COLOR);
    cv::imshow("CR7", img);
    img = color::blockColorRegions(img);
    cv::imshow("Color blocked CR7", img);
  }
  SECTION ("Cat") {
    cv::Mat img = cv::imread("imagens/Cat.jpg", CV_LOAD_IMAGE_COLOR);
    cv::imshow("Cat", img);
    img = color::blockColorRegions(img);
    cv::imshow("Color blocked Cat", img);
  }
  cv::waitKey();
} // TEST_CASE
