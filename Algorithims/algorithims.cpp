#include "algorithims.h"

// Jehad M Hamad
// Algorithim: Selection Sort
// Sorts a given array by selection sort
// Input: An array A[0..n − 1] of orderable elements
// Output: Array A[0..n − 1] sorted in nondecreasing order
// time complexity: O(n^2)
// space complexity: O(1)
// stability: Selection Sort is stable

void selectionSort(vector<int> &vec){
    int n = vec.size();
    for (int i = 0; i < n - 1; i++){
        int min = i;
        for (int j = i + 1; j < n; j++){
            //find smallest element and keep that index
            if(vec[j] < vec[min]){
                min = j;
            }
        }
        //swap
       int tmp = vec[i];
       vec[i] = vec[min];
       vec[min] = tmp; 
    }
}

// Algorithim: Bubble Sort
// Sorts a given array by bubble sort
// Input: An array A[0..n − 1] of orderable elements
// Output: Array A[0..n − 1] sorted in nondecreasing order
// time complexity: O(n^2)
// space complexity: O(1)
// stability: Bubble Sort is stable

void bubbleSort(vector<int> &vec){
    int n = vec.size();
    for (int i = 0; i < n - 1; i++){
        for(int j = 0; j < n - 1 - i; j++){
            if(vec[j+1] < vec[j]){
                //swap
                int tmp = vec[j];
                vec[j] = vec[j + 1];
                vec[j + 1] = tmp;
            }
        }
    }
}

// Algorithim: Insertion Sort
// Sorts a given array by Insertion sort
// Input: An array A[0..n − 1] of orderable elements
// Output: Array A[0..n − 1] sorted in nondecreasing order
// time complexity: O(n^2)
// space complexity: O(1)
// stability: Insertion Sort is stable

void insertionSort(vector<int> &vec){
    int n = vec.size();
    for(int i = 1; i < n; i++){
        int v = vec[i];
        int j = i - 1;

        while((j >= 0) && (vec[j] > v)){
            vec[j + 1] = vec[j];
            j = j - 1;
        }
        vec[j + 1] = v;
    }
}

// Algorithim: Merge Sort
// Sorts array A[0..n − 1] by recursive mergesort
// Input: An array A[0..n − 1] of orderable elements
// Output: Array A[0..n − 1] sorted in nondecreasing order
// time complexity: O(nlogn)
// space complexity: O(n)
// stability: Merge Sort is stable

void mergeSort(vector<int> &vec){
    int n = vec.size();
    if(n > 1){
        vector<int> left;
        vector<int> right;
        //copy
        for(int i = 0; i < n; i++){
            if(i < (n/2))
                left.push_back(vec[i]);
            else
                right.push_back(vec[i]);
        }
        mergeSort(left);
        mergeSort(right);
        merge(left, right, vec);
    }
}

// Algorithim: Merge 
// Merges two sorted arrays into one sorted array
// Input: Arrays B[0..p − 1] and C[0..q − 1] both sorted
// Output: Sorted array A[0..p + q − 1] of the elements of B and C
// Needed for Merge Sort

void merge(vector<int> &left, vector<int> &right, vector<int> &vec){
    int i = 0, j = 0, k = 0;
    int p = left.size();
    int q = right.size();

    while((i < p) && (j < q)){
        if(left[i]<=right[j]){
            vec[k] = left[i];
            i++;
        } else {
            vec[k] = right[j];
            j++;
        }
        k++;
    }
    // Copy the remaining elements of Left 
    while(i < p){
        vec[k] = left[i];
        i++;
        k++;
    }
    // Copy the remaining elements of Right 
    while(j < q){
        vec[k] = right[q];
        j++;
        k++;
    }
}

void quickSort(vector<int> &vec, int left, int right){
    
}