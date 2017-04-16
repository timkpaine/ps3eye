#include "opencv2/opencv.hpp"
#include "context.h"
#include "frame_function.h"
#include <iostream>

using namespace cv;
 
int run_camera(Context& context)
{
    VideoCapture cap(0); // open the default camera
    if(!cap.isOpened())  // check if we succeeded
        std::cout << "No Camera detected." << std::endl;
        return -1;
 
    Mat edges;
    namedWindow("Input",1);
    namedWindow("Output",1);

    for(;;)
    {
        Mat frame;
        cap >> frame; // get a new frame from camera

        // cvtColor(frame, edges, CV_BGR2GRAY);
        // GaussianBlur(edges, edges, Size(7,7), 1.5, 1.5);
        // Canny(edges, edges, 0, 30, 3);
        // imshow("edges", edges);
        imshow("Input", frame);

        int size = 640*480*3;
        uint8_t* destimg = 0;
        if(destimg==0){
            destimg = new uint8_t[size];
        }
        for(int row; row<480; row++){
            for(int col; col<640; col++){
                Vec3f pixel = frame.at<Vec3f>(row, col);
                int r = pixel[2];
                int g = pixel[1];
                int b = pixel[0];
                destimg[row*col + col] = r;
                destimg[row*col + col+1] = g; 
                destimg[row*col + col+2] = b; 
            }
        }

        frame_function(context, destimg);

        Mat m = Mat(480, 640, CV_8UC3, destimg); 
        imshow("Output", m);
        waitKey(1);
    }
    // the camera will be deinitialized automatically in VideoCapture destructor
    return 0;
}
