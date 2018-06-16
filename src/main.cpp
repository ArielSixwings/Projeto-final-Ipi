#include "Edges.hpp"

int main(int argc, char const *argv[])
{
	Mat img = imread("lena.jpg", CV_LOAD_IMAGE_COLOR);
	imshow("teste",img);
	waitKey();
	return 0;
}