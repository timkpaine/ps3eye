#include "opencv2/opencv.hpp"
#include "context.h"
#include "frame_function.h"
#include <iostream>

using namespace cv;
using namespace std;

string type2str(int type) {
  string r;

  uchar depth = type & CV_MAT_DEPTH_MASK;
  uchar chans = 1 + (type >> CV_CN_SHIFT);

  switch ( depth ) {
    case CV_8U:  r = "8U"; break;
    case CV_8S:  r = "8S"; break;
    case CV_16U: r = "16U"; break;
    case CV_16S: r = "16S"; break;
    case CV_32S: r = "32S"; break;
    case CV_32F: r = "32F"; break;
    case CV_64F: r = "64F"; break;
    default:     r = "User"; break;
  }

  r += "C";
  r += (chans+'0');

  return r;
}

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
        // cv::cvtColor(frame_raw, frame, CV_BGR2GRAY);
        imshow("Input", frame);
        string ty =  type2str( frame.type() );

        int size = context.height*context.width*3;
        uint8_t* destimg = 0;
        if(destimg==0){
            destimg = new uint8_t[size];
        }

        memcpy(destimg, (uint8_t*) frame.data, size);

        frame_function(context, destimg);

        Mat m(480, 640, CV_8UC3, destimg); 
        imshow("Output", m);
        waitKey(1);
    }
    // the camera will be deinitialized automatically in VideoCapture destructor
    return 0;
}
