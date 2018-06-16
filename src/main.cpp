#include "Edges.hpp"

int main(int argc, char const *argv[])
{
	Mat Image = imread("lena.jpg", CV_LOAD_IMAGE_COLOR);
	Mat Edges;
	TakeEdges(Image,Edges);
	return 0;
}