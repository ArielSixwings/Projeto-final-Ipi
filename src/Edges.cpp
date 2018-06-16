void TakeEdges(Mat& Image, Mat& Edges){

	Mat grayImage, edge, draw,dst;
	cvtColor(Image, grayImage, CV_BGR2GRAY);
	medianBlur( grayImage, dst, 7 );
	Canny( dst, edge, 50, 150, 3);
	edge.convertTo(draw, CV_8U);
	namedWindow("image", CV_WINDOW_AUTOSIZE);
	imshow("image", draw);
	waitKey(0);
	//oioioioioi
}