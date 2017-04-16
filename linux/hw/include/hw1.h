#ifndef __HW1__
#define __HW1__
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <vector>
#include "hw1.h"

using namespace std;

namespace hw{

template <typename T> void populate_vector(vector<T> &v){
    for(typename vector<T>::iterator i = v.begin(); i<v.end(); ++i){
        *i = rand() % 256;
    }
}

template <typename T> void print_vector(vector<T> &v, int x, int y){
    int x_index = 0;
    for(T i: v){
        if(x_index == x*3){
            x_index = 0;
            cout << endl;
        }

        cout << i << " ";
        x_index++;

        if(x_index%3 ==0){
            cout << "\t";
        }
    }
    cout << endl;
    cout << endl;
}

template <typename T> void average_vector(vector<T> &v){
    T x_index = 0;
    T average = 0;

    for(typename vector<T>::iterator i = v.begin(); i<v.end(); ++i){
        x_index++;

        if(x_index==3){
            average = (*(i-2) + *(i-1) + *i)/3;
            *(i-2) = average;
            *(i-1) = average;
            *i = average;
            x_index = 0;
        }
    }
}

template <typename T> void invert_vector(vector<T> &v){
    for(typename vector<T>::iterator i = v.begin(); i<v.end(); ++i){
        *i = 255 - *i;
    }
}

template <typename T> T *index_vector(vector<T> &v, int x_dim, int y_dim, int x_val, int y_val){
    return &(v[y_val*x_dim*3 + x_val*3]);
}

template <typename T> void replace_in_vector(vector<T> &v, int x_dim, int y_dim, T *start, char color, int value){
    switch(color){
        case 'b': 
            *start = value;
            break;
        case 'g':
            *(start + 1) = value;
            break;
        case 'r':
            *(start + 2) = value;
            break;
    }
}

template <typename T> void flip_vector(vector<T> &v, int x, int y){
    T *pixel;
    T *flip_pixel;
    T tmp = 0;

    for(int j = 0; j < y; ++j){
        for(int i = 0; i < x/2; ++i){
            pixel = index_vector(v, x, y, i, j);
            flip_pixel = index_vector(v, x, y, x-i-1, j);
            for(int k=0; k<3; ++k){
                tmp = *(pixel + k);
                *(pixel + k) = *(flip_pixel + k);
                *(flip_pixel + k) = tmp;
            }
        }
    }
}

}

#endif