#include "Edges.hpp"

void TakeEdges(Mat& Image, Mat& Edges){

	Mat grayImage,auxedge,dst;
	cvtColor(Image, grayImage, CV_BGR2GRAY);
	medianBlur( grayImage, dst, 7 );
	Canny( dst, auxedge, 50, 150, 3);
	auxedge.convertTo(Edges, CV_8U);
	namedWindow("image", CV_WINDOW_AUTOSIZE);
	imshow("image", Edges);
	waitKey(0);
}