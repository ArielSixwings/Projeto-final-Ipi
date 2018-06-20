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
}//TakeEdges()

cv::Mat Dilate(cv::Mat& source){
	cv::Mat destination;
	cv::Mat element = cv::getStructuringElement(cv::MORPH_RECT, cv::Size(2, 2), cv::Point(1, 1) );
	cv::dilate(source, destination, element);
	return destination;
}//Dilate()

cv::Mat EdgeFilter(cv::Mat& source,int threshold){
	
	/*Take the connected componentes*/
	cv::Mat labelImage(source.size(), CV_32S);
	cv::Mat filtered(source.size(), CV_8U);
	source.copyTo(filtered);
	cv::Mat stats, centroids;
	connectedComponentsWithStats(source, labelImage, stats, centroids, 8, CV_32S);
	
	/*take off the connected components with area below the thershold*/
	for (int r = 0; r < source.rows; ++r){
		for (int c = 0; c < source.cols; ++c){
			int aux_label = labelImage.at<int>(r,c);
			if ((stats.at<int>(aux_label, cv::CC_STAT_AREA)) < threshold){
				filtered.at<uchar>(r,c) = 0;
			}
		}//for c
	}//for r
	return filtered;
}//EdgeFilter()
 
void TakeNegative(cv::Mat& source)
{
	for (int r = 0; r < source.rows; r++)
	{
		for (int c = 0; c < source.cols; c++)
		{
			source.at<uchar>(r, c) = (255 - source.at<uchar>(r, c));
		}
	}
}//TakeNegative()


} // namespace edges
