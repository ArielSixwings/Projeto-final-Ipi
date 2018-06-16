#include "Edges.hpp"

int main(int argc, char const *argv[])
{
	cv::Mat Image = cv::imread("lena.jpg", CV_LOAD_IMAGE_COLOR);
	if(Image.empty()){
		std::cout<<"problens to read image"<<std::endl;
		return 0;
	}	
	cv::imshow("teste",Image);
	cv::waitKey();
	return 0;
}