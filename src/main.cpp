#include "Edges.hpp"

int main(int argc, char const *argv[])
{
	cv::Mat img = cv::imread("lena.jpg", CV_LOAD_IMAGE_COLOR);
	if(img.empty()){
		cout<<"a imagem não foi lida corretamente"<<endl;
		return 0;
	}	
	imshow("teste",img);
	waitKey();
	return 0;
}