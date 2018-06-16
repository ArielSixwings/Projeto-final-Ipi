#include "Edges.hpp"

void TakeEdges(cv::Mat& Image, cv::Mat& Edges){

	cv::Mat grayImage,auxedge,dst;
	cv::cvtColor(Image, grayImage, CV_BGR2GRAY);
	cv::medianBlur( grayImage, dst, 7 );
	cv::Canny( dst, auxedge, 50, 150, 3);
	auxedge.convertTo(Edges, CV_8U);
	cv::namedWindow("image", CV_WINDOW_AUTOSIZE);
	cv::imshow("image", Edges);
	cv::waitKey(0);
}