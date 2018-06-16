#include "Edges.hpp"

<<<<<<< HEAD
namespace edges {

void TakeEdges(Mat& Image, Mat& Edges){
=======
<<<<<<< HEAD
namespace edges {

void TakeEdges(Mat& Image, Mat& Edges){
=======
void TakeEdges(cv::Mat& Image, cv::Mat& Edges){
>>>>>>> e67b9ab8c2ac55ec038cc559c269b60e39f38489
>>>>>>> 9572e06b9ce89718333cb13cb306c0e160fbcab2

	cv::Mat grayImage,auxedge,dst;
	cv::cvtColor(Image, grayImage, CV_BGR2GRAY);
	cv::medianBlur( grayImage, dst, 7 );
	cv::Canny( dst, auxedge, 50, 150, 3);
	auxedge.convertTo(Edges, CV_8U);
<<<<<<< HEAD
=======
<<<<<<< HEAD
	namedWindow("image", CV_WINDOW_AUTOSIZE);
	imshow("image", Edges);
	waitKey(0);
}

} // namespace edges
=======
>>>>>>> 9572e06b9ce89718333cb13cb306c0e160fbcab2
	cv::namedWindow("image", CV_WINDOW_AUTOSIZE);
	cv::imshow("image", Edges);
	cv::waitKey(0);
}
<<<<<<< HEAD
=======
>>>>>>> e67b9ab8c2ac55ec038cc559c269b60e39f38489
>>>>>>> 9572e06b9ce89718333cb13cb306c0e160fbcab2
