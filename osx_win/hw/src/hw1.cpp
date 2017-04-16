#include <stdlib.h>
#include <time.h>
#include <iostream>
#include "hw1.h"

void populate_vector(std::vector<int> &v){
    for(std::vector<int>::iterator i = v.begin(); i<v.end(); ++i){
        *i = rand() % 256;
    }
}

void print_vector(std::vector<int> &v, int x, int y){
    int x_index = 0;
    for(int i: v){
        if(x_index == x*3){
            x_index = 0;
            std::cout << std::endl;
        }

        std::cout << i << " ";
        x_index++;

        if(x_index%3 ==0){
            std::cout << "\t";
        }
    }
    std::cout << std::endl;
    std::cout << std::endl;
}

void average_vector(std::vector<int> &v){
    int x_index = 0;
    int average = 0;

    for(std::vector<int>::iterator i = v.begin(); i<v.end(); ++i){
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

void invert_vector(std::vector<int> &v){
    for(std::vector<int>::iterator i = v.begin(); i<v.end(); ++i){
        *i = 255 - *i;
    }
}

int *index_vector(std::vector<int> &v, int x_dim, int y_dim, int x_val, int y_val){
    return &(v[y_val*x_dim*3 + x_val*3]);
}

void replace_in_vector(std::vector<int> &v, int x_dim, int y_dim, int *start, char color, int value){
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

void flip_vector(std::vector<int> &v, int x, int y){
    int *pixel;
    int *flip_pixel;
    int tmp = 0;

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
