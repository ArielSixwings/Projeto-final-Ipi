#include "Edges.hpp"

<<<<<<< HEAD
namespace edges {

void TakeEdges(Mat& Image, Mat& Edges){
=======
void TakeEdges(cv::Mat& Image, cv::Mat& Edges){
>>>>>>> e67b9ab8c2ac55ec038cc559c269b60e39f38489

	cv::Mat grayImage,auxedge,dst;
	cv::cvtColor(Image, grayImage, CV_BGR2GRAY);
	cv::medianBlur( grayImage, dst, 7 );
	cv::Canny( dst, auxedge, 50, 150, 3);
	auxedge.convertTo(Edges, CV_8U);
<<<<<<< HEAD
	namedWindow("image", CV_WINDOW_AUTOSIZE);
	imshow("image", Edges);
	waitKey(0);
}

} // namespace edges
=======
	cv::namedWindow("image", CV_WINDOW_AUTOSIZE);
	cv::imshow("image", Edges);
	cv::waitKey(0);
}
>>>>>>> e67b9ab8c2ac55ec038cc559c269b60e39f38489
