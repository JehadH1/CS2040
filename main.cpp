#include <iostream>
#include <iomanip>
#include <vector>
#include <cstdlib>
#include "Algorithims/algorithims.h"
#include "VecBuilder/vecBuilder.h"

using namespace std;

int main()
{
    srand(time(0));

    clock_t start, end;
    // build the three sizes (1k, 10k, 100k) vectors;
    vector<vector<int>> rand1KVec = buildVector(10, 1000);
    vector<vector<int>> rand10KVec = buildVector(10, 10000);
    vector<vector<int>> rand100KVec = buildVector(10, 100000);

    // populate the three vectors with random numbers
    buildRandomVector(rand1KVec);
    buildRandomVector(rand10KVec);
    buildRandomVector(rand100KVec);

    // build the three vectors of (1k 10k 100k) with sorted numbers
    vector<vector<int>> sort1kVec = buildSortedVector(rand1KVec);
    vector<vector<int>> sort10kVec = buildSortedVector(rand10KVec);
    vector<vector<int>> sort100kVec = buildSortedVector(rand100KVec);

    // build the three vectors of (1k 10k 100k) with rev sorted numbers
    vector<vector<int>> revSort1kVec = buildReverseSortedVector(rand1KVec);
    vector<vector<int>> revSort10kVec = buildReverseSortedVector(rand10KVec);
    vector<vector<int>> revSort100kVec = buildReverseSortedVector(rand100KVec);

    // selection Sort
    vector<vector<int>> selectRand1k = rand1KVec;
    vector<vector<int>> selectSort1k = sort1kVec;
    vector<vector<int>> selectRevSort1k = revSort1kVec;

    cout << "The Algorithim is Selection Sort \n";
    cout << "The size is 1K \n";
    cout << "Random   ";
    for (auto row : selectRand1k)
    {
        start = clock();
        selectionSort(row);
        end = clock();
        double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
        cout << "| " << setw(6) << fixed << setprecision(5) << time_taken << " |";
    }
    cout << endl;
    cout << "Sorted   ";
    for (auto row : selectSort1k)
    {
        start = clock();
        selectionSort(row);
        end = clock();
        double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
        cout << "| " << setw(6) << fixed << setprecision(5) << time_taken << " |";
    }
    cout << endl;
    cout << "Rev Sort ";
    for (auto row : selectRevSort1k)
    {
        start = clock();
        selectionSort(row);
        end = clock();
        double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
        cout << "| " << setw(6) << fixed << setprecision(5) << time_taken << " |";
    }
    cout << endl;
    cout << endl;
    vector<vector<int>> selectRand10k = rand10KVec;
    vector<vector<int>> selectSort10k = sort10kVec;
    vector<vector<int>> selectRevSort10k = revSort10kVec;

    cout << "The size is 10k \n";
    cout << "Random   ";
    for (auto row : selectRand10k)
    {
        start = clock();
        selectionSort(row);
        end = clock();
        double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
        cout << "| " << setw(6) << fixed << setprecision(5) << time_taken << " |";
    }
    cout << endl;
    cout << "Sorted   ";
    for (auto row : selectSort10k)
    {
        start = clock();
        selectionSort(row);
        end = clock();
        double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
        cout << "| " << setw(6) << fixed << setprecision(5) << time_taken << " |";
    }
    cout << endl;
    cout << "Rev Sort ";
    for (auto row : selectRevSort10k)
    {
        start = clock();
        selectionSort(row);
        end = clock();
        double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
        cout << "| " << setw(6) << fixed << setprecision(5) << time_taken << " |";
    }
    cout << endl;
    cout << endl;

    vector<vector<int>> selectRand100k = rand100KVec;
    vector<vector<int>> selectSort100k = sort100kVec;
    vector<vector<int>> selectRevSort100k = revSort100kVec;
    cout << "The size is 100k \n";
    cout << "Random   ";
    for (auto row : selectRand100k)
    {
        start = clock();
        selectionSort(row);
        end = clock();
        double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
        cout << "| " << setw(6) << fixed << setprecision(5) << time_taken << " |";
    }
    cout << endl;
    cout << "Sorted   ";
    for (auto row : selectSort100k)
    {
        start = clock();
        selectionSort(row);
        end = clock();
        double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
        cout << "| " << setw(6) << fixed << setprecision(5) << time_taken << " |";
    }
    cout << endl;
    cout << "Rev Sort ";
    for (auto row : selectRevSort100k)
    {
        start = clock();
        selectionSort(row);
        end = clock();
        double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
        cout << "| " << setw(6) << fixed << setprecision(5) << time_taken << " |";
    }
    cout << endl;
    cout << endl;
    // Bubble sort
    vector<vector<int>> bubbleRand1k = rand1KVec;
    vector<vector<int>> bubbleSort1k = sort1kVec;
    vector<vector<int>> bubbleRevSort1k = revSort1kVec;

    vector<vector<int>> bubbleRand10k = rand10KVec;
    vector<vector<int>> bubbleSort10k = sort10kVec;
    vector<vector<int>> bubbleRevSort10k = revSort10kVec;

    vector<vector<int>> bubbleRand100k = rand100KVec;
    vector<vector<int>> bubbleSort100k = sort100kVec;
    vector<vector<int>> bubbleRevSort100k = revSort100kVec;

    // Insertion sort
    vector<vector<int>> insertionRand1k = rand1KVec;
    vector<vector<int>> insertionSort1k = sort1kVec;
    vector<vector<int>> insertionRevSort1k = revSort1kVec;

    vector<vector<int>> insertionRand10k = rand10KVec;
    vector<vector<int>> insertionSort10k = sort10kVec;
    vector<vector<int>> insertionRevSort10k = revSort10kVec;

    vector<vector<int>> insertionRand100k = rand100KVec;
    vector<vector<int>> insertionSort100k = sort100kVec;
    vector<vector<int>> insertionRevSort100k = revSort100kVec;

    // Merge sort
    vector<vector<int>> mergeRand1k = rand1KVec;
    vector<vector<int>> mergeSort1k = sort1kVec;
    vector<vector<int>> mergeRevSort1k = revSort1kVec;

    vector<vector<int>> mergeRand10k = rand10KVec;
    vector<vector<int>> mergeSort10k = sort10kVec;
    vector<vector<int>> mergeRevSort10k = revSort10kVec;

    vector<vector<int>> mergeRand100k = rand100KVec;
    vector<vector<int>> mergeSort100k = sort100kVec;
    vector<vector<int>> mergeRevSort100k = revSort100kVec;

    // Quick sort
    vector<vector<int>> quickRand1k = rand1KVec;
    vector<vector<int>> quickSort1k = sort1kVec;
    vector<vector<int>> quickRevSort1k = revSort1kVec;

    vector<vector<int>> quickRand10k = rand10KVec;
    vector<vector<int>> quickSort10k = sort10kVec;
    vector<vector<int>> quickRevSort10k = revSort10kVec;

    vector<vector<int>> quickRand100k = rand100KVec;
    vector<vector<int>> quickSort100k = sort100kVec;
    vector<vector<int>> quickRevSort100k = revSort100kVec;
}