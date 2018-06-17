#include "Edges.hpp"
#include "color.hpp"
#include "Recombine.hpp"
int main(int argc, char const *argv[])
{
	cv::Mat image = cv::imread("Cat.jpg", CV_LOAD_IMAGE_COLOR);
	cv::Mat edges;
	if(image.empty()){
		std::cout<<"problens to read image"<<std::endl;
		return 0;
	}	
	cv::imshow("Original image",image);
	cv::waitKey();

	edges = edges::TakeEdges(image,55,5);
	edges = edges::Dilate(edges);
	edges::TakeNegative(edges);
	

	image = color::blockColorRegions(image);
	cv::imshow("step color", image);
	cv::waitKey();
	
	recombine::Recombine(image,edges);
	cv::imshow("final", image);
	cv::waitKey();
	//std::cout<<edges<<std::endl;
	return 0;
}