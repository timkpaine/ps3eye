#include "hw1.h"
#include "hw2.h"

#include <iostream>
#include <vector>
#include <stdint.h>

using namespace std;

int main(){
    vector<int> vector_from1 = {
        0,0,0, 1,1,1, 0,0,0, 0,0,0,
        0,0,0, 1,1,1, 0,0,0, 1,1,1,
    };

    vector<int> vector_from2 = {
        0,0,0, 1,1,1, 0,0,0, 0,0,0,
        0,0,0, 1,1,1, 0,0,0, 1,1,1,
    };

    // TODO Practice Templates
    // CameraImage<int> img1(vector_from1, 4, 2);
    // CameraImage<int> img2(vector_from2, 4, 2);
    // CameraImage<uint8_t> img3(vector_from2, 4, 2);

    // TODO practice operator overloading
    // cout << img1 << endl;
    // cout << img3 << endl;

    // TODO practice operator overloading
    // if(img1 > img2){ // average of all pixels 
    //     cout << "A" << endl;
    // }
    // if(img1 != img2){ // compare individual pixels
    //     cout << "B" << endl;
    // }
    // if(img2 == img3){ // compare individual pixels
    //     cout << "B" << endl;
    // }
}