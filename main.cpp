#include <iostream>
#include <vector>
#include <cstdlib>
#include "Algorithims/algorithims.h"

using namespace std;

int main(){
    srand(time(0));

    vector<int> a;
    for(int i = 0; i <10; i++){
        a.push_back(rand() % 101);
    }

    cout << "\n selection sort \n";
    vector<int> a1 = a;
    selectionSort(a1);
    for(int i: a1){
        cout<< i <<"  ";
    }

    cout << "\n bubble sort \n";
    vector<int> a2 = a;
    bubbleSort(a2);
    for(int i: a2){
        cout<< i <<"  ";
    }

    cout << "\n insersion sort \n";
    vector<int> a3 = a;
    insertionSort(a3);
    for(int i: a3){
        cout<< i <<"  ";
    }

    cout << "\n merge sort \n";
    vector<int> a4 = a;
    bubbleSort(a4);
    for(int i: a4){
        cout<< i <<"  ";
    }

    cout << "\n quick sort \n";
    vector<int> a5 = a;
    bubbleSort(a5);
    for(int i: a5){
        cout<< i <<"  ";
    }
    cout<<"\n";
}