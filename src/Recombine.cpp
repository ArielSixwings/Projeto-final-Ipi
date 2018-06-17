#include "Recombine.hpp"

namespace recombine {

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

}