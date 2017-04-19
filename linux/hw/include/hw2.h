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
    virtual ~Image(){}

    virtual void populate_image() = 0;
    virtual void print_image() = 0;
    virtual void average_image() = 0;
    virtual void invert_image() = 0;
    virtual int *index_image(int x_val, int y_val) = 0;
    virtual void replace_in_image(int *start, char color, int value) = 0;
    virtual void flip_image() = 0;
    virtual void copy_from(vector<int> &copy_from) = 0;

};


class CameraImage: public Image{
public:
    CameraImage() : Image(){}
    CameraImage(int x, int y) : Image(x,y){}
    CameraImage(vector<int> &copy_from, int x, int y) : Image(copy_from, x,y){}
    virtual ~CameraImage(){}

    virtual void populate_image(){
        hw::populate_vector(this->local_buffer);
    }

    virtual void print_image(){
        hw::print_vector(this->local_buffer, this->width, this->height);
    }

    virtual void average_image(){
        hw::average_vector(this->local_buffer);
    }

    virtual void invert_image(){
        hw::invert_vector(this->local_buffer);
    }

    virtual int *index_image(int x_val, int y_val){
        return hw::index_vector(this->local_buffer, this->width, this->height, x_val, y_val);
    }

    virtual void replace_in_image(int *start, char color, int value){
        hw::replace_in_vector(this->local_buffer, this->width, this->height, start, color, value);
    }

    virtual void flip_image(){
        hw::flip_vector(this->local_buffer, this->width, this->height);
    }

    //TODO copy from!
};

#endif
