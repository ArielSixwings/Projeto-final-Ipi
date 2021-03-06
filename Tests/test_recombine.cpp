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
		edges = edges::EdgeFilter(edges,12);
		edges::TakeNegative(edges);
		color_image = color::blockColorRegions(image);
		image = recombine::Recombine(color_image,edges,0.0);
		cv::imshow("final", image);
	}
	SECTION ("CR7") {
		cv::Mat image = cv::imread("Images/CR7.png", CV_LOAD_IMAGE_COLOR);
		cv::Mat edges;
		cv::Mat color_image;
		edges = edges::TakeEdges(image,lowThreshold,range);
		edges = edges::Dilate(edges);
		cv::medianBlur( edges, edges, 3 );
		edges = edges::EdgeFilter(edges,12);
		edges::TakeNegative(edges);
		color_image = color::blockColorRegions(image);
		image = recombine::Recombine(color_image,edges,(0.0));
		cv::imshow("final", image);		
	}
	SECTION ("Cat") {
		cv::Mat image = cv::imread("Images/Cat.jpg", CV_LOAD_IMAGE_COLOR);
		cv::Mat edges;
		cv::Mat color_image;
		edges = edges::TakeEdges(image,lowThreshold,range);
		edges = edges::Dilate(edges);
		edges = edges::EdgeFilter(edges,30);
		edges::TakeNegative(edges);
		color_image = color::blockColorRegions(image);
		image = recombine::Recombine(color_image,edges,(0.0));
		cv::imshow("final", image);
	}

	SECTION ("elephant") {
		cv::Mat image = cv::imread("Images/elephant.jpg", CV_LOAD_IMAGE_COLOR);
		cv::Mat edges;
		cv::Mat color_image;
		edges = edges::TakeEdges(image,lowThreshold,range);
		edges = edges::Dilate(edges);
		edges = edges::EdgeFilter(edges,12);
		edges::TakeNegative(edges);
		color_image = color::blockColorRegions(image);				
		image = recombine::Recombine(color_image,edges,(0.0));
		cv::imshow("final", image);
	}
	SECTION ("rocky") {
		cv::Mat image = cv::imread("Images/rocky.jpg", CV_LOAD_IMAGE_COLOR);
		cv::Mat edges;
		cv::Mat color_image;
		edges = edges::TakeEdges(image,lowThreshold,range);
		edges = edges::Dilate(edges);
		edges = edges::EdgeFilter(edges,12);
		edges::TakeNegative(edges);
		color_image = color::blockColorRegions(image);				
		image = recombine::Recombine(color_image,edges,(0.0));
		cv::imshow("final", image);
	}	
	cv::waitKey();
} // TEST_CASE
