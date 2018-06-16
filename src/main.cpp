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

	for (int j = 5; j < 10; ++j){
		std::cout<<"range:"<<j<<"\n\n";
		for (int i = 40; i < 60; ++i){
			std::cout<<"	lowTreshold:"<<i<<std::endl;
			edges = edges::TakeEdges(image,i,j);
			
		}
	}
	//cv::imshow("edges",edges);
	//cv::waitKey();	
	return 0;
}