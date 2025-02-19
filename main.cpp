#include <iostream>
#include <vector>
#include <cstdlib>
#include "Algorithims/algorithims.h"
#include "VecBuilder/vecBuilder.h"

using namespace std;

int main(){
    srand(time(0));
    vector<vector<int>> randVec;
    for (int i; i < 10; i++){
        vector<int> tmp = buildRandomVector(10);
        randVec.push_back(tmp);
    }

    for (auto i : randVec){
        for (auto j : i){
            cout << j << " ";
        }
        cout << "\n";
    }
}