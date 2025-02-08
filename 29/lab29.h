#ifndef LAB29_H
#define LAB29_H

#include <iostream>
#include <vector>

using namespace std;

template<typename T>
bool nextPermutation(vector<T>& v);

template<typename T>
ostream& operator<<(ostream& os, const vector<T>& v);

#include "lab29.cpp"

#endif
