#include <iostream>

#include <opencv2\highgui.hpp>

int main(int argc, char* argv[])
{
    if (argc < 2)
    {
        std::cerr << "Usage: " << argv[0] << " <image file name>\n";
        return EXIT_SUCCESS;
    }

    cv::Mat img = cv::imread(argv[1]);
    cv::imshow("image", img);
    
    while (3 == cv::waitKey()); // don't close on Ctrl-C

    return EXIT_SUCCESS;
}