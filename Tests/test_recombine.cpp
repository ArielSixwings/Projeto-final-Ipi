#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "color.hpp"
#include "Edges.hpp"
#include "Recombine.hpp"

TEST_CASE ("All") {
	SECTION ("Lena") {
		cv::Mat image = cv::imread("Images/lena.jpg", CV_LOAD_IMAGE_COLOR);
		cv::Mat edges;
		cv::Mat color_image;
		edges = edges::TakeEdges(image,55,5);
		edges = edges::Dilate(edges);
		edges::TakeNegative(edges);
		color_image = color::blockColorRegions(image);
		for (int i = 0; i < 11; ++i)
		{

			image = recombine::Recombine(color_image,edges,(i/10.0));
			cv::imshow("final", image);
			cv::waitKey(500);
			//cv::imwrite("final0.jpg",image);
		}
	}
	SECTION ("CR7") {
		cv::Mat image = cv::imread("Image/CR7.png", CV_LOAD_IMAGE_COLOR);
		cv::Mat edges;
		cv::Mat color_image;
		edges = edges::TakeEdges(image,55,5);
		edges = edges::Dilate(edges);
		edges::TakeNegative(edges);
		color_image = color::blockColorRegions(image);
		for (int i = 0; i < 11; ++i)
		{
			image = recombine::Recombine(color_image,edges,(i/10.0));
			cv::imshow("final", image);
			cv::waitKey(500);
			//cv::imwrite("final0.jpg",image);
		}
	}
	SECTION ("Cat") {
		cv::Mat image = cv::imread("Images/Cat.jpg", CV_LOAD_IMAGE_COLOR);
		cv::Mat edges;
		cv::Mat color_image;
		edges = edges::TakeEdges(image,55,5);
		edges = edges::Dilate(edges);
		edges::TakeNegative(edges);
		color_image = color::blockColorRegions(image);
		for (int i = 0; i < 11; ++i)
		{
			image = recombine::Recombine(color_image,edges,(i/10.0));
			cv::imshow("final", image);
			cv::waitKey(500);
			//cv::imwrite("final0.jpg",image);
		}
	}

} // TEST_CASE
