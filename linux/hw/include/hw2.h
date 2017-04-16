#ifndef __HW2__
#define __HW2__

#include "hw1.h"
#include <vector>
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

class Image{
protected:
    int height;
    int width;
    vector<int> local_buffer;

public:
    Image(){}
    Image(int x, int y): height(y), width(x){}
    Image(vector<int> &copy_from, int x, int y)
     : height(y), width(x)
    {

    }


    virtual void populate_image() = 0;
    virtual void print_image() = 0;
    virtual void average_image() = 0;
    virtual void invert_image() = 0;
    virtual int *index_image(int x_val, int y_val) = 0;
    virtual void replace_in_image(int *start, char color, int value) = 0;
    virtual void flip_image() = 0;

};


class CameraImage: public Image{
public:
    CameraImage() : Image(){}
    CameraImage(int x, int y) : Image(x,y){}
    CameraImage(vector<int> &copy_from, int x, int y) : Image(copy_from, x,y){}

    virtual void populate_image(){
        populate_vector(local_buffer);
    }

    virtual void print_image(){
        print_vector(local_buffer, width, height);
    }

    virtual void average_image(){
        average_vector(local_buffer);
    }

    virtual void invert_image(){
        invert_vector(local_buffer);
    }

    virtual int *index_image(int x_val, int y_val){
        return index_vector(local_buffer, width, height, x_val, y_val);
    }

    virtual void replace_in_image(int *start, char color, int value){
        replace_in_vector(local_buffer, width, height, start, color, value);
    }

    virtual void flip_image(){
        flip_vector(local_buffer, width, height);
    }

};

#endif
