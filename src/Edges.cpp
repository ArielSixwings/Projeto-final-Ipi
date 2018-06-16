#include "Edges.hpp"

namespace edges {

cv::Mat TakeEdges(cv::Mat& image,int lowThreshold, int range){
	//lowThreshold, lowThreshold*ratio
	cv::Mat grayImage,edge,dst;
	cv::cvtColor(image, grayImage, CV_BGR2GRAY);
	cv::medianBlur( grayImage, dst, 7 );
	cv::Canny( dst, edge, lowThreshold, (lowThreshold+range), 3);
	edge.convertTo(edge, CV_8U);
	cv::namedWindow("image", CV_WINDOW_AUTOSIZE);
	cv::imshow("image", edge);
	cv::waitKey();
	return edge;
}

} // namespace edges