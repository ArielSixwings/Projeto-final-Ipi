#include "Edges.hpp"
#include "color.hpp"


void Recombine(cv::Mat& color, cv::Mat& edges){
	cv::Vec3b colorpixel;
	for (int r = 0; r < color.rows; ++r)
	{
		for (int c = 0; c < color.cols; ++c)
		{
			if (edges.at<uchar>(r,c)){
				continue;
			}
			colorpixel = color.at<cv::Vec3b>(r,c);

			colorpixel[0] = (colorpixel[0]*edges.at<uchar>(r,c));
			colorpixel[1] = (colorpixel[1]*edges.at<uchar>(r,c));
			colorpixel[2] = (colorpixel[2]*edges.at<uchar>(r,c));
			
			color.at<cv::Vec3b>(r,c) = colorpixel;
		}
	}
}
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
	
	Recombine(image,edges);
	cv::imshow("final", image);
	cv::waitKey();
	//std::cout<<edges<<std::endl;
	return 0;
}