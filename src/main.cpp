#include "Edges.hpp"

int main(int argc, char const *argv[])
{
	cv::Mat image = cv::imread("lena.jpg", CV_LOAD_IMAGE_COLOR);
	cv::Mat edges;
	if(image.empty()){
		std::cout<<"problens to read image"<<std::endl;
		return 0;
	}	
	cv::imshow("teste",image);
	cv::waitKey();

	edges = TakeEdges(image);
	cv::imshow("edges",edges);
	cv::waitKey();	
	return 0;
}