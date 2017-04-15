#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/core/core.hpp>

using namespace cv;


int main()
{
    VideoCapture cap(0);
    if(!cap.isOpened())
    {
        return -1;
    }
    Mat frame;
    Mat edges;

    bool stop = false;
    while(!stop)
    {
        cap>>frame;
        imshow("video",frame);
        if(waitKey(10) >=0)
            stop = true;
    }
    return 0;
}