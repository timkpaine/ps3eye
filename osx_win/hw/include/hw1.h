#ifndef __HW1__
#define __HW1__

#include <vector>

void populate_vector(std::vector<int> &v);

void print_vector(std::vector<int> &v, int x, int y);
void average_vector(std::vector<int> &v);
void invert_vector(std::vector<int> &v);

int *index_vector(std::vector<int> &v, int x_dim, int y_dim, int x_val, int y_val);
void replace_in_vector(std::vector<int> &v, int x_dim, int y_dim, int *start, char color, int value);
void flip_vector(std::vector<int> &v, int x, int y);

#endif