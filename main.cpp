#include <iostream>
#include <vector>
#include "Algorithims/algorithims.h"

using namespace std;

int main(){
    vector<int> a = {9,8,7,6,5,4,3,2,1};

    vector<int> a1 = a;
    selectionSort(a1);
    for(int i: a1){
        cout<< i <<"  ";
    }


    cout<<"\n";
}