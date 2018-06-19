/** @file main.cpp
 * @author
   Luigi Minardi Ferreira Maia (17/0017141)
   Ariel Vieira Lima Serafim (17/0006328)
 * @date 06/17/2017
 * @brief Main file to the final IPI project to toonify images.
 * @copyright GNU Public License.
*/

#include <cstdlib>
#include <iostream>
#include <string>
#include <thread>

#include <opencv2/opencv.hpp>

#include "color.hpp"
#include "Edges.hpp"
#include "Recombine.hpp"

namespace {

/** Return the toonifyed image.
*/
cv::Mat toonify(cv::Mat& src) {
	cv::Mat toon_color;
	std::thread do_colors([&]() { // Do in parallel;
	  toon_color = color::blockColorRegions(src);
  });
	cv::Mat toon_edges = edges::TakeEdges(src, 55, 5);
	toon_edges = edges::Dilate(toon_edges);
	edges::TakeNegative(toon_edges);
  do_colors.join();
	cv::Mat img = recombine::Recombine(toon_color, toon_edges, 0.5);
	return img;
}

/** Show usage mensage to the user.
*/
void usageMensage(char* argv[]) {
	std::cout
		<< "\033[1;33m" << "Usage:\n" << "\033[0m"
		<< '\n'
  	<< '\t' << argv[0] << " path/to/image" << '\n'
		<< '\t' << "In this way, the software gonna take one image and show on the"
		<< " screen." << '\n'
		<< '\n'
		<< '\t' << argv[0] << " path/to/multiple images" << '\n'
		<< '\t' << "In this way, the software gonna take one image save the"
		<< " processed images in a new directory called TOONS in the current"
		<< " directory." << '\n'
		<< '\n'
		<< '\t' << "User can must use '/' as the current directory." << '\n'
		<< '\t' << "Exemple: "  << argv[0] << " /" << '\n';
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

/** Make the output files name.
*/
std::vector<cv::String> generateOutputFilesName(
	  const std::vector<cv::String>& src) {
	std::system("mkdir TOON");
	std::vector<cv::String> output_files(src.size());
	for (int i = 0; i < src.size(); ++i) {
		output_files[i] = "TOON/";
    for (int c = 0; c < src[i].size(); ++c) {
			if (src[i][c] == '/')
			  output_files[i] = "TOON/";
		  else
			  output_files[i] += src[i][c];
		} // for (c)
	} // for (i)
	return output_files;
} // generateOutputFilesName()


int main(int argc, char* argv[]) {
	if (argc != 2) {
		usageMensage(argv);
		return 0;
	} // if (argc != 2)
	std::string input_file = argv[1];
	if (input_file == "/")  // current directory was selected
		input_file = "";
	bool did_something = false;
  cv::Mat src = cv::imread(input_file, CV_LOAD_IMAGE_COLOR);
	if (!src.empty()) {
		did_something = true;
	  std::cout << "Processing image" << input_file <<'\n';
		cv::Mat img = toonify(src);
		displayImage(src, input_file);
		displayImage(img, "Toonifyed " + input_file);
		cv::waitKey();
	} else { // Process some image in input_file
		std::vector<cv::String> images_file;  //cv::vector< String > Files
		cv::glob(input_file, images_file);
		auto images_output = generateOutputFilesName(images_file);
		if (images_file.size() == 0) {
		  std::cout << "The software couldn't find any image"
			  << " or directory with this name: " << input_file <<'\n';
			usageMensage(argv);
			return 0;
		} // if images_file.size() == 0)
		for (unsigned i = 0; i < images_file.size(); ++i) {
			src = cv::imread(images_file[i], CV_LOAD_IMAGE_COLOR);
			if (src.empty())
			  continue;
			std::cout << "Processing image: " << images_file[i] << '\n';

			did_something = true;
			cv::Mat img = toonify(src);
			cv::imwrite(images_output[i], img);
			std::cout << '\t' << "Saving in file: " << images_output[i] << '\n';
		} // for (i)
	} // if (!src.empty()) // else
	if (did_something == false) {
		std::cout << "The software couldn't find any image " << input_file
			<< " or in a directory with this name." << '\n';
		usageMensage(argv);
		return 0;
	} // if (did_something == false)
} // main()
