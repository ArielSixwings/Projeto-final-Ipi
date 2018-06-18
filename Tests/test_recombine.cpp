#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "color.hpp"
#include "Edges.hpp"
#include "Recombine.hpp"

#define lowThreshold  55
#define range  5

TEST_CASE ("All") {
	SECTION ("Lena") {
		cv::Mat image = cv::imread("Images/lena.jpg", CV_LOAD_IMAGE_COLOR);
		cv::Mat edges;
		cv::Mat color_image;
		edges = edges::TakeEdges(image,lowThreshold,range);
		edges = edges::Dilate(edges);
		edges::TakeNegative(edges);
		cv::medianBlur( edges, edges, 3 );
		color_image = color::blockColorRegions(image);
		image = recombine::Recombine(color_image,edges,0.0);
		cv::imshow("final", image);
		//cv::waitKey(500);
		//cv::imwrite("lenafinal.jpg,",image);
	}
	SECTION ("CR7") {
		cv::Mat image = cv::imread("Images/CR7.png", CV_LOAD_IMAGE_COLOR);
		cv::Mat edges;
		cv::Mat color_image;
		edges = edges::TakeEdges(image,lowThreshold,range);
		edges = edges::Dilate(edges);
		cv::medianBlur( edges, edges, 3 );
		edges::TakeNegative(edges);
		color_image = color::blockColorRegions(image);
		image = recombine::Recombine(color_image,edges,(0.0));
		cv::imshow("final", image);
		//cv::imwrite("CR7final0.jpg,",image);
		//cv::waitKey(500);
		
	}
	SECTION ("Cat") {
		cv::Mat image = cv::imread("Images/Cat.jpg", CV_LOAD_IMAGE_COLOR);
		cv::Mat edges;
		cv::Mat color_image;
		edges = edges::TakeEdges(image,lowThreshold,range);
		edges = edges::Dilate(edges);
		edges::TakeNegative(edges);
		color_image = color::blockColorRegions(image);
		image = recombine::Recombine(color_image,edges,(0.0));
		cv::imshow("final", image);
		//cv::waitKey(500);
	}

	SECTION ("elephant") {
		cv::Mat image = cv::imread("Images/elephant.jpg", CV_LOAD_IMAGE_COLOR);
		cv::Mat edges;
		cv::Mat color_image;
		edges = edges::TakeEdges(image,lowThreshold,range);
		edges = edges::Dilate(edges);
		edges::TakeNegative(edges);
		color_image = color::blockColorRegions(image);				
		image = recombine::Recombine(color_image,edges,(0.0));
		cv::imshow("final", image);
	}
	cv::waitKey();
} // TEST_CASE
