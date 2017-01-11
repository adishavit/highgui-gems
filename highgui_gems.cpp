#include <iostream>

#include <opencv2\highgui.hpp>
#include <opencv2\opencv.hpp>

int main(int argc, char* argv[])
{
    if (argc < 2)
    {
        std::cerr << "Usage: " << argv[0] << " <image file name>\n";
        return EXIT_SUCCESS;
    }

    cv::Mat img = cv::imread(argv[1]);
    cv::imshow("image", img);

    cv::setMouseCallback("image", [](int event, int x, int y, int flags, void* userdata) 
    {
        cv::Mat& image = *reinterpret_cast<cv::Mat*>(userdata); // get source image
        static cv::Mat tmp;
        image.copyTo(tmp);

        static int radius = 21; // default value
        if (cv::EVENT_MOUSEWHEEL == event)
            radius = std::max(11, radius + cv::getMouseWheelDelta(flags) / 120);

        cv::circle(tmp, { x,y }, radius, { 255.,255.,255. }); // draw a circle around mouse position
        cv::imshow("image", tmp);
    }, &img);

    const auto CTRL_C = 3;
    while (CTRL_C == cv::waitKey()); // don't close on Ctrl-C

    return EXIT_SUCCESS;
}