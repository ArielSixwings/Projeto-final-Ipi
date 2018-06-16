#include "Edges.hpp"

namespace edges {

cv::Mat TakeEdges(cv::Mat& image,int lowThreshold, int range){
	cv::Mat grayImage,edge,dst;
	
	/*convert to gray scale*/
	cv::cvtColor(image, grayImage, CV_BGR2GRAY);
	
	/*apply median blur with a 7x7 kernel*/
	cv::medianBlur( grayImage, dst, 7 );
	
	/*apply Canny edge detector*/	
	cv::Canny( dst, edge, lowThreshold, (lowThreshold+range), 3);
	edge.convertTo(edge, CV_8U);
	cv::namedWindow("image", CV_WINDOW_AUTOSIZE);
	cv::imshow("image", edge);
	cv::waitKey();
	return edge;
}

} // namespace edges