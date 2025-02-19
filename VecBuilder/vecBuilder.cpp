#include "vecBuilder.h"
#include "cstdlib"

vector<int> buildRandomVector(int size){
    vector<int> vec;

    for(int i =0; i< size; i++){
        vec.push_back(rand() % 101);
    }
    return vec;
}
