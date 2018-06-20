#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "Edges.hpp"

#define lowThreshold  55
#define range  5

TEST_CASE ("All") {
	SECTION ("Lena") {
		cv::Mat image = cv::imread("Images/lena.jpg", CV_LOAD_IMAGE_COLOR);
		cv::Mat edges;
		edges = edges::TakeEdges(image,lowThreshold,range);
		edges = edges::Dilate(edges);
		cv::imshow("not filtered", edges);
		//-----------
		edges = edges::EdgeFilter(edges);
		//-------------
		cv::imshow("filtered", edges);
		cv::waitKey();
		edges::TakeNegative(edges);
	}

} // TEST_CASE
