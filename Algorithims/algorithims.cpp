#include "algorithims.h"

// algorithims.cpp
// Jehad M Hamad
// tuesday feb 18
// Algorithim: Selection Sort
// Sorts a given array by selection sort
// Input: An array A[0..n − 1] of orderable elements
// Output: Array A[0..n − 1] sorted in nondecreasing order
// time complexity: O(n^2)
// space complexity: O(1)
// stability: Selection Sort is not stable
void Algorithims::selectionSort(vector<int> &vec)
{
    int n = vec.size();
    for (int i = 0; i < n - 1; i++)
    {
        int min = i;
        for (int j = i + 1; j < n; j++)
        {
            // find smallest element and keep that index
            if (vec[j] < vec[min])
                min = j;
        }
        // swap
        int tmp = vec[i];
        vec[i] = vec[min];
        vec[min] = tmp;
    }
}

// algorithims.cpp
// Jehad M Hamad
// tuesday feb 18
// Algorithim: Bubble Sort
// Sorts a given array by bubble sort
// Input: An array A[0..n − 1] of orderable elements
// Output: Array A[0..n − 1] sorted in nondecreasing order
// time complexity: O(n^2)
// space complexity: O(1)
// stability: Bubble Sort is stable
void Algorithims::bubbleSort(vector<int> &vec)
{
    int n = vec.size();
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (vec[j + 1] < vec[j])
            {
                // swap
                int tmp = vec[j];
                vec[j] = vec[j + 1];
                vec[j + 1] = tmp;
            }
        }
    }
}

// algorithims.cpp
// Jehad M Hamad
// tuesday feb 18
// Algorithim: Insertion Sort
// Sorts a given array by Insertion sort
// Input: An array A[0..n − 1] of orderable elements
// Output: Array A[0..n − 1] sorted in nondecreasing order
// time complexity: O(n^2)
// space complexity: O(1)
// stability: Insertion Sort is stable
void Algorithims::insertionSort(vector<int> &vec)
{
    int n = vec.size();
    for (int i = 1; i < n; i++)
    {
        int v = vec[i];
        int j = i - 1;

        while ((j >= 0) && (vec[j] > v))
        {
            vec[j + 1] = vec[j];
            j = j - 1;
        }
        vec[j + 1] = v;
    }
}

// algorithims.cpp
// Jehad M Hamad
// tuesday feb 18
// Algorithim: Merge Sort
// Sorts array A[0..n − 1] by recursive mergesort
// Input: An array A[0..n − 1] of orderable elements
// Output: Array A[0..n − 1] sorted in nondecreasing order
// time complexity: O(nlogn)
// space complexity: O(n)
// stability: Merge Sort is stable

void Algorithims::mergeSort(vector<int> &vec)
{
    int n = vec.size();
    if (n <= 1) // Base case: stop recursion if the array has 1 or fewer elements
        return;

    vector<int> left;
    vector<int> right;
    // Copy
    for (int i = 0; i < n; i++)
    {
        if (i < (n / 2))
            left.push_back(vec[i]);
        else
            right.push_back(vec[i]);
    }
    mergeSort(left);
    mergeSort(right);
    merge(left, right, vec);
}

// algorithims.cpp
// Jehad M Hamad
// tuesday feb 18
// Algorithim: Merge
// Merges two sorted arrays into one sorted array
// Input: Arrays B[0..p − 1] and C[0..q − 1] both sorted
// Output: Sorted array A[0..p + q − 1] of the elements of B and C
// Needed for Merge Sort
void Algorithims::merge(vector<int> &left, vector<int> &right, vector<int> &vec)
{
    int i = 0, j = 0, k = 0;
    int p = left.size();
    int q = right.size();

    while ((i < p) && (j < q))
    {
        if (left[i] <= right[j])
        {
            vec[k] = left[i];
            i++;
        }
        else
        {
            vec[k] = right[j];
            j++;
        }
        k++;
    }
    // Copy the remaining elements of Left
    while (i < p)
    {
        vec[k] = left[i];
        i++;
        k++;
    }
    // Copy the remaining elements of Right
    while (j < q)
    {
        vec[k] = right[j];
        j++;
        k++;
    }
}

// algorithims.cpp
// Jehad M Hamad
// tuesday feb 18
// Algorithim: Quick Sort
// Sorts a subarray by quicksort
// Input: Subarray of array A[0..n − 1], defined by its left and right
// indices l and r
// Output: Subarray A[l..r] sorted in nondecreasing order
// time complexity: O(nlogn)
// space complexity: O(logn)
// stability: Merge Sort is not stable

void Algorithims::quickSort(vector<int> &vec, int left, int right)
{
    if (left < right)
    {
        int s = partition(vec, left, right);
        quickSort(vec, left, s - 1);
        quickSort(vec, s + 1, right);
    }
}

// algorithims.cpp
// Jehad M Hamad
// tuesday feb 18
//  Partitions a subarray by Hoare’s algorithm, using the first element
//  as a pivot
//  Input: Subarray of array A[0..n − 1], defined by its left and right
//  indices l and r (l < r)
//  Output: Partition of A[l..r], with the split position returned as
//  this function’s value
int Algorithims::partition(vector<int> &vec, int left, int right)
{
    int pivot = vec[left];

    int i = left;
    int j = right;

    while (true)
    {
        while (vec[i] <= pivot && i < right)
            i++;
        while (vec[j] >= pivot && j > left)
            j--;
        if (i >= j)
            break; // breaking out early prevents undoing last swap

        int tmp = vec[i]; // swap vec[i] and vec[j]
        vec[i] = vec[j];
        vec[j] = tmp;
    }

    int tmp = vec[left]; // swap vec[left] and vec[j]
    vec[left] = vec[j];
    vec[j] = tmp;

    return j;
}