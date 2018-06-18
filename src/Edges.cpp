#include "Edges.hpp"

//using namespace cv;
//using namespace std;

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
	return edge;
}

cv::Mat Dilate(cv::Mat& source){
	cv::Mat dst_1;
	cv::Mat element = cv::getStructuringElement(cv::MORPH_RECT, cv::Size(2, 2), cv::Point(1, 1) );
	cv::dilate(source, dst_1, element);
	return dst_1;
}
 
void TakeNegative(cv::Mat& source)
{
	for (int r = 0; r < source.rows; r++)
	{
		for (int c = 0; c < source.cols; c++)
		{
			source.at<uchar>(r, c) = (255 - source.at<uchar>(r, c));
		}
	}
}

} // namespace edges