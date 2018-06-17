#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "color.hpp"
#include "Edges.hpp"
#include "Recombine.hpp"

TEST_CASE ("All") {
	SECTION ("Lena") {
		cv::Mat image = cv::imread("imagens/lena.jpg", CV_LOAD_IMAGE_COLOR);
		cv::Mat edges;
		edges = edges::TakeEdges(image,55,5);
		edges = edges::Dilate(edges);
		edges::TakeNegative(edges);
		image = color::blockColorRegions(image);
		recombine::Recombine(image,edges);
		cv::imshow("final", image);
		cv::waitKey();		
	}
	SECTION ("CR&") {
		cv::Mat image = cv::imread("imagens/CR7.png", CV_LOAD_IMAGE_COLOR);
		cv::Mat edges;
		edges = edges::TakeEdges(image,55,5);
		edges = edges::Dilate(edges);
		edges::TakeNegative(edges);
		image = color::blockColorRegions(image);
		recombine::Recombine(image,edges);
		cv::imshow("final", image);
		cv::waitKey();		
	}
	SECTION ("Cat") {
		cv::Mat image = cv::imread("imagens/Cat.jpg", CV_LOAD_IMAGE_COLOR);
		cv::Mat edges;
		edges = edges::TakeEdges(image,55,5);
		edges = edges::Dilate(edges);
		edges::TakeNegative(edges);
		image = color::blockColorRegions(image);
		recombine::Recombine(image,edges);
		cv::imshow("final", image);
		cv::waitKey();		
	}	

} // TEST_CASE
