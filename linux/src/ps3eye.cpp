#include "opencv2/opencv.hpp"
#include "context.h"
#include "frame_function.h"
#include <iostream>

using namespace cv;
using namespace std;

int run_camera(Context& context)
{
    VideoCapture cap(0); // open the default camera
    if(!cap.isOpened()){  // check if we succeeded
        std::cout << "No Camera detected." << std::endl;
        return -1;
    }
    // Mat edges;
    namedWindow("Input",1);
    namedWindow("Output",1);

    Mat frame(480, 640, CV_8UC3);

    for(;;)
    {
        cap >> frame; // get a new frame from camera

        imshow("Input", frame);
        
        int size = context.height*context.width*3;

        vector<uint8_t> destimg((uint8_t*) frame.data, (uint8_t*)frame.data+size);
        frame_function(context, destimg);

        Mat m(480, 640, CV_8UC3, (uint8_t*) &destimg[0]); 
        imshow("Output", m);
        waitKey(1);
    }
    // the camera will be deinitialized automatically in VideoCapture destructor
    return 0;
}
