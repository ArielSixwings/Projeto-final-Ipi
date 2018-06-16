#include "Edges.hpp"

cv::Mat TakeEdges(cv::Mat& image){

	cv::Mat grayImage,edge,dst;
	cv::cvtColor(image, grayImage, CV_BGR2GRAY);
	cv::medianBlur( grayImage, dst, 7 );
	cv::Canny( dst, edge, 50, 150, 3);
	edge.convertTo(edge, CV_8U);
	cv::namedWindow("image", CV_WINDOW_AUTOSIZE);
	cv::imshow("image", edge);
	cv::waitKey(0);
	return edge;
}