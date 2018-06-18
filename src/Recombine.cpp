#include "Recombine.hpp"

//#define factor 0.0
namespace recombine {

cv::Mat Recombine(cv::Mat& color, cv::Mat& edges,double factor){
	cv::Vec3b colorpixel;
	cv::Mat final_image;
	color.copyTo(final_image);
	for (int r = 0; r < color.rows; ++r)
	{
		for (int c = 0; c < color.cols; ++c)
		{
			if (edges.at<uchar>(r,c)){
				continue;
			}
			colorpixel = color.at<cv::Vec3b>(r,c);

			colorpixel[0] = (colorpixel[0]*factor); //edges.at<uchar>(r,c));
			colorpixel[1] = (colorpixel[1]*factor); //edges.at<uchar>(r,c));
			colorpixel[2] = (colorpixel[2]*factor); //edges.at<uchar>(r,c));
			
			final_image.at<cv::Vec3b>(r,c) = colorpixel;
			//std::cout<<color.at<cv::Vec3b>(r,c)<<std::endl;
		}
	}
	// cv::imshow("final", final_image);
	// cv::waitKey();	
	return final_image;
}

}