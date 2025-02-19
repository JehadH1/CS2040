#include <iostream>
#include <vector>
#include <cstdlib>
#include "Algorithims/algorithims.h"
#include "VecBuilder/vecBuilder.h"

using namespace std;

int main(){
    srand(time(0));

    // build the three sizes (1k, 10k, 100k) vectors;
    vector<vector<int>> rand1KVec = buildVector(10, 10);
    vector<vector<int>> rand10KVec = buildVector(10, 10000);
    vector<vector<int>> rand100KVec = buildVector(10, 100000);

    //populate the three vectors with random numbers 
    buildRandomVector(rand1KVec);
    buildRandomVector(rand10KVec);
    buildRandomVector(rand100KVec);

    //make copies of three rand vectors for selection sort
    vector<vector<int>> selecRand1k = rand1KVec;
    vector<vector<int>> selecRand10k = rand10KVec;
    vector<vector<int>> selecRand100k = rand100KVec;

    //make copies of three rand vectors for bubble sort
    vector<vector<int>> bubbleRand1k = rand1KVec;
    vector<vector<int>> bubbleRand10k = rand10KVec;
    vector<vector<int>> bubbleRand100k = rand100KVec;

    //make copies of three rand vectors for inserion sort
    vector<vector<int>> insertionRand1k = rand1KVec;
    vector<vector<int>> insertionRand10k = rand10KVec;
    vector<vector<int>> insertionRand10k = rand100KVec;

    //make copies of three rand vectors for merge sort
    vector<vector<int>> mergeRand1k = rand1KVec;
    vector<vector<int>> mergeRand10k = rand10KVec;
    vector<vector<int>> mergeRand100k = rand100KVec;

    //make copies of three rand vectors for quick sort
    vector<vector<int>> quickRand1k = rand1KVec;
    vector<vector<int>> quickRand10k = rand10KVec;
    vector<vector<int>> quickRand100k = rand100KVec;




}