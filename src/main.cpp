/** @file main.cpp
 * @author
   Luigi Minardi Ferreira Maia (17/0017141)
   Ariel Vieira Lima Serafim (17/0006328)
 * @date 06/17/2017
 * @brief Main file to the final IPI project to toonify images.
 * @copyright GNU Public License.
*/

#include <iostream>
#include <string>

#include <opencv2/opencv.hpp>

#include "color.hpp"
#include "Edges.hpp"
#include "Recombine.hpp"

namespace {

/** Show usage mensage to the user.
*/
void usageMensage(char* argv[]) {
	std::cout
		<< "\033[1;33m" << "Usage:\n" << "\033[0m"
		<< '\t' << argv[0] << " path/to/images path/to/save/result/images" << '\n'
	  << '\t' << "In this way, the software gonna take all the images in the"
	  << " directory and save in the path/to/save/result/images file." << '\n'
		<< '\n'
  	<< '\t' << argv[0] << " path/to/image" << '\n'
		<< '\t' << "In this way, the software gonna take one image and show on the"
		<< " screen." << '\n'
		<< '\n'
		<< '\t' << "User can must use '/' as the current directory." << '\n'
		<< '\t' << "Exemple: "  << argv[0] << " /" << '\n'
		<< '\t' <<"or: " << argv[0] << " path/to/images /" << '\n';
} // usageMensage()

/** Display cv::Mat object to the user in a resizeble window.
*/
void displayImage(const cv::Mat img, const std::string window_name,
                  size_t n_rows = 0, size_t n_cols = 0,
					        size_t pos_x = 0, size_t pos_y = 0) {
  if (n_rows == 0) // if n_rows wasn't set
    n_rows = img.rows;
  if (n_cols == 0) // if n_cols was't set.
    n_cols = img.cols;
	cv::namedWindow(window_name, CV_WINDOW_FREERATIO);
	cv::imshow(window_name, img);
	cv::resizeWindow(window_name, n_cols, n_rows);
	cv::moveWindow(window_name, pos_x, pos_y);
}  // displayImage()

} // namespace

int main(int argc, char* argv[]) {
	for (int i = 0; i < argc; ++i) {
    if (std::string(argv[i]) == "/") // if the current directory was selected
		  argv[i] = "";
	} // for (i)
	if (argc == 2) { // Process a single image and display;
    cv::Mat src = cv::imread(argv[1], CV_LOAD_IMAGE_COLOR);
		if (src.empty()) {
			std::cout << "The software couldn't find any image with the name:"
			  << argv[1] << '\n';
			usageMensage(argv);
			return 0;
		} // if (img.empty())
		/*
		cv::Mat img = toonify(img);
		*/
		displayImage(src /*img*/, std::string("Toonifyed") + argv[1]);
		cv::waitKey();
	} else if (argc == 3) { // Process some image in argc[1] and save in argc[2]
		std::vector<cv::String> images_file;  //cv::vector< String > Files
		cv::glob(argv[1], images_file);
		if (images_file.size() == 0) {
		  std::cout << "The software couldn't find any image in " << argv[1] <<'\n';
			usageMensage(argv);
			return 0;
		} // if images_file.size() == 0)
		for (unsigned i = 0; i < images_file.size(); ++i) {
			std::cout << " Reading " << images_file[i] << '\n';
			cv::Mat src = 
			if (image)
		} // for (i)
	} else {
		usageMensage(argv);
	} // if (argc == 2) // else if (argc == 3) // else
} // main()
