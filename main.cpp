#include <iostream>
#include <iomanip>
#include <vector>
#include <cstdlib>
#include <string>
#include "Algorithims/algorithims.h"
#include "VecBuilder/vecBuilder.h"

using namespace std;

void timeAlgorithim(const string &algoName, const string &type, vector<vector<int>> &vec, Algorithims &sorter, void (Algorithims::*sortFunc)(vector<int> &), double &time, string &bestAlgoName)
{
    double avetime;
    double count;
    cout << type;

    for (auto &row : vec)
    {
        clock_t start = clock();
        (sorter.*sortFunc)(row);
        clock_t end = clock();
        double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
        count++;
        avetime += time_taken;
        cout << "| " << setw(6) << fixed << setprecision(5) << time_taken << " |";
    }
    avetime = avetime / count;
    cout << " Ave time " << setw(6) << fixed << avetime;
    if (avetime < time)
    {
        time = avetime;
        bestAlgoName = algoName;
    }
    cout << "\n";
}

int main()
{
    Algorithims sorter;
    VecBuilder vecBuild;
    srand(10);

    // Initialize double variables for random, sorted, and reversed sorted values
    double random_10 = 1000000, random_100 = 1000000, random_1K = 1000000, random_10K = 1000000, random_100K = 1000000, random_1M = 1000000, random_10M = 1000000;
    double sort_10 = 1000000, sort_100 = 1000000, sort_1K = 1000000, sort_10K = 1000000, sort_100K = 1000000, sort_1M = 1000000, sort_10M = 1000000;
    double revSort_10 = 1000000, revSort_100 = 1000000, revSort_1K = 1000000, revSort_10K = 1000000, revSort_100K = 1000000, revSort_1M = 1000000, revSort_10M = 1000000;

    // String variables for describing size categories
    string Rand10, Rand100, Rand1K, Rand10K, Rand100K, Rand1M, Rand10M;
    string Sort10, Sort100, Sort1K, Sort10K, Sort100K, Sort1M, Sort10M;
    string RevSort10, RevSort100, RevSort1K, RevSort10K, RevSort100K, RevSort1M, RevSort10M;

    clock_t start, end;
    // build the three sizes (10, 100, 1k, 10k, 100k, 1M, 10M) vectors;
    vector<vector<int>> rand10Vec = vecBuild.buildVector(10, 1000);
    vector<vector<int>> rand100Vec = vecBuild.buildVector(10, 1000);
    vector<vector<int>> rand1KVec = vecBuild.buildVector(10, 1000);
    vector<vector<int>> rand10KVec = vecBuild.buildVector(10, 10000);
    vector<vector<int>> rand100KVec = vecBuild.buildVector(10, 100000);
    vector<vector<int>> rand1MVec = vecBuild.buildVector(10, 100000);
    vector<vector<int>> rand10MVec = vecBuild.buildVector(10, 100000);

    // populate the three vectors with random numbers
    vecBuild.buildRandomVector(rand10Vec);
    vecBuild.buildRandomVector(rand100Vec);
    vecBuild.buildRandomVector(rand1KVec);
    vecBuild.buildRandomVector(rand10KVec);
    vecBuild.buildRandomVector(rand100KVec);
    vecBuild.buildRandomVector(rand1MVec);
    vecBuild.buildRandomVector(rand10MVec);

    // build the three vectors of (10, 100, 1k, 10k, 100k, 1M, 10M) with sorted numbers
    vector<vector<int>> sort10Vec = vecBuild.buildSortedVector(rand10Vec);
    vector<vector<int>> sort100Vec = vecBuild.buildSortedVector(rand100Vec);
    vector<vector<int>> sort1kVec = vecBuild.buildSortedVector(rand1KVec);
    vector<vector<int>> sort10kVec = vecBuild.buildSortedVector(rand10KVec);
    vector<vector<int>> sort100kVec = vecBuild.buildSortedVector(rand100KVec);
    vector<vector<int>> sort1MVec = vecBuild.buildSortedVector(rand1MVec);
    vector<vector<int>> sort10MVec = vecBuild.buildSortedVector(rand10MVec);

    // build the three vectors of (10, 100, 1k, 10k, 100k, 1M, 10M) with rev sorted numbers
    vector<vector<int>> revSort10Vec = vecBuild.buildReverseSortedVector(rand10Vec);
    vector<vector<int>> revSort100Vec = vecBuild.buildReverseSortedVector(rand100Vec);
    vector<vector<int>> revSort1kVec = vecBuild.buildReverseSortedVector(rand1KVec);
    vector<vector<int>> revSort10kVec = vecBuild.buildReverseSortedVector(rand10KVec);
    vector<vector<int>> revSort100kVec = vecBuild.buildReverseSortedVector(rand100KVec);
    vector<vector<int>> revSort1MVec = vecBuild.buildReverseSortedVector(rand1MVec);
    vector<vector<int>> revSort10MVec = vecBuild.buildReverseSortedVector(rand10MVec);

    // selection Sort
    cout << "The Algorithim is Selection Sort \n\n";

    vector<vector<int>> selectRand10 = rand10Vec;
    vector<vector<int>> selectSort10 = sort10Vec;
    vector<vector<int>> selectRevSort10 = revSort10Vec;
    cout << "The size is n = 10 \n";
    timeAlgorithim("Selection", "Random  ", selectRand10, sorter, &Algorithims::selectionSort, random_10, Rand10);
    timeAlgorithim("Selection", "Sort    ", selectSort10, sorter, &Algorithims::selectionSort, sort_10, Sort10);
    timeAlgorithim("Selection", "Rev Sort", selectRevSort10, sorter, &Algorithims::selectionSort, revSort_10, RevSort10);
    cout << endl;

    vector<vector<int>> selectRand100 = rand100Vec;
    vector<vector<int>> selectSort100 = sort100Vec;
    vector<vector<int>> selectRevSort100 = revSort100Vec;
    cout << "The size is n = 100 \n";
    timeAlgorithim("Selection", "Random  ", selectRand100, sorter, &Algorithims::selectionSort, random_100, Rand100);
    timeAlgorithim("Selection", "Sort    ", selectSort100, sorter, &Algorithims::selectionSort, sort_100, Sort100);
    timeAlgorithim("Selection", "Rev Sort", selectRevSort100, sorter, &Algorithims::selectionSort, revSort_100, RevSort100);
    cout << endl;

    vector<vector<int>> selectRand1k = rand1KVec;
    vector<vector<int>> selectSort1k = sort1kVec;
    vector<vector<int>> selectRevSort1k = revSort1kVec;
    cout << "The size is n = 1000 \n";
    timeAlgorithim("Selection", "Random  ", selectRand1k, sorter, &Algorithims::selectionSort, random_1K, Rand1K);
    timeAlgorithim("Selection", "Sort    ", selectSort1k, sorter, &Algorithims::selectionSort, sort_1K, Sort1K);
    timeAlgorithim("Selection", "Rev Sort", selectRevSort1k, sorter, &Algorithims::selectionSort, revSort_1K, RevSort1K);
    cout << endl;

    vector<vector<int>> selectRand10k = rand10KVec;
    vector<vector<int>> selectSort10k = sort10kVec;
    vector<vector<int>> selectRevSort10k = revSort10kVec;
    cout << "The size is n = 10000 \n";
    timeAlgorithim("Selection", "Random  ", selectRand10k, sorter, &Algorithims::selectionSort, random_10K, Rand10K);
    timeAlgorithim("Selection", "Sort    ", selectSort10k, sorter, &Algorithims::selectionSort, sort_10K, Sort10K);
    timeAlgorithim("Selection", "Rev Sort", selectRevSort10k, sorter, &Algorithims::selectionSort, revSort_10K, RevSort10K);
    cout << endl;

    // vector<vector<int>> selectRand100k = rand100KVec;
    // vector<vector<int>> selectSort100k = sort100kVec;
    // vector<vector<int>> selectRevSort100k = revSort100kVec;
    // cout << "The size is n = 100000 \n";
    // timeAlgorithim("Selection", "Random  ", selectRand100k, sorter, &Algorithims::selectionSort, random_100K, Rand100K);
    // timeAlgorithim("Selection", "Sort    ", selectSort100k, sorter, &Algorithims::selectionSort, sort_100K, Sort100K);
    // timeAlgorithim("Selection", "Rev Sort", selectRevSort100k, sorter, &Algorithims::selectionSort, revSort_100K, RevSort100K);

    cout << "\n\n";

    // Bubble Sort
    cout << "The Algorithim is Bubble Sort \n\n";

    vector<vector<int>> bubbleRand10 = rand10Vec;
    vector<vector<int>> bubbleSort10 = sort10Vec;
    vector<vector<int>> bubbleRevSort10 = revSort10Vec;
    cout << "The size is n = 10 \n";
    timeAlgorithim("Bubble", "Random  ", bubbleRand10, sorter, &Algorithims::bubbleSort, random_10, Rand10);
    timeAlgorithim("Bubble", "Sort    ", bubbleSort10, sorter, &Algorithims::bubbleSort, sort_10, Sort10);
    timeAlgorithim("Bubble", "Rev Sort", bubbleRevSort10, sorter, &Algorithims::bubbleSort, revSort_10, RevSort10);
    cout << endl;

    vector<vector<int>> bubbleRand100 = rand100Vec;
    vector<vector<int>> bubbleSort100 = sort100Vec;
    vector<vector<int>> bubbleRevSort100 = revSort100Vec;
    cout << "The size is n = 100 \n";
    timeAlgorithim("Bubble", "Random  ", bubbleRand100, sorter, &Algorithims::bubbleSort, random_100, Rand100);
    timeAlgorithim("Bubble", "Sort    ", bubbleSort100, sorter, &Algorithims::bubbleSort, sort_100, Sort100);
    timeAlgorithim("Bubble", "Rev Sort", bubbleRevSort100, sorter, &Algorithims::bubbleSort, revSort_100, RevSort100);
    cout << endl;

    vector<vector<int>> bubbleRand1k = rand1KVec;
    vector<vector<int>> bubbleort1k = sort1kVec;
    vector<vector<int>> bubbleRevSort1k = revSort1kVec;
    cout << "The size is n = 1000 \n";
    timeAlgorithim("Bubble", "Random  ", bubbleRand1k, sorter, &Algorithims::bubbleSort, random_1K, Rand1K);
    timeAlgorithim("Bubble", "Sort    ", bubbleort1k, sorter, &Algorithims::bubbleSort, sort_1K, Sort1K);
    timeAlgorithim("Bubble", "Rev Sort", bubbleRevSort1k, sorter, &Algorithims::bubbleSort, revSort_1K, RevSort1K);
    cout << endl;

    vector<vector<int>> bubbleRand10k = rand10KVec;
    vector<vector<int>> bubbleSort10k = sort10kVec;
    vector<vector<int>> bubbleRevSort10k = revSort10kVec;
    cout << "The size is n = 10000 \n";
    timeAlgorithim("Bubble", "Random  ", bubbleRand10k, sorter, &Algorithims::bubbleSort, random_10K, Rand10K);
    timeAlgorithim("Bubble", "Sort    ", bubbleSort10k, sorter, &Algorithims::bubbleSort, sort_10K, Sort10K);
    timeAlgorithim("Bubble", "Rev Sort", bubbleRevSort10k, sorter, &Algorithims::bubbleSort, revSort_10K, RevSort10K);
    cout << endl;

    // vector<vector<int>> bubbleRand100k = rand100KVec;
    // vector<vector<int>> bubbleSort100k = sort100kVec;
    // vector<vector<int>> bubbleRevSort100k = revSort100kVec;
    // cout << "The size is n = 100000 \n";
    // timeAlgorithim("Bubble", "Random  ", bubbleRand100k, sorter, &Algorithims::bubbleSort, random_100K, Rand100K);
    // timeAlgorithim("Bubble", "Sort    ", bubbleSort100k, sorter, &Algorithims::bubbleSort, sort_100K, Sort100K);
    // timeAlgorithim("Bubble", "Rev Sort", bubbleRevSort100k, sorter, &Algorithims::bubbleSort, revSort_100K, RevSort100K);

    cout << "\n\n";

    // Bubble Sort
    cout << "The Algorithim is Insertion Sort \n\n";

    vector<vector<int>> insertionRand10 = rand10Vec;
    vector<vector<int>> insertionSort10 = sort10Vec;
    vector<vector<int>> insertionRevSort10 = revSort10Vec;
    cout << "The size is n = 10 \n";
    timeAlgorithim("Insertion", "Random  ", insertionRand10, sorter, &Algorithims::insertionSort, random_10, Rand10);
    timeAlgorithim("Insertion", "Sort    ", insertionSort10, sorter, &Algorithims::insertionSort, sort_10, Sort10);
    timeAlgorithim("Insertion", "Rev Sort", insertionRevSort10, sorter, &Algorithims::insertionSort, revSort_10, RevSort10);
    cout << endl;

    vector<vector<int>> insertionRand100 = rand100Vec;
    vector<vector<int>> insertionSort100 = sort100Vec;
    vector<vector<int>> insertionRevSort100 = revSort100Vec;
    cout << "The size is n = 100 \n";
    timeAlgorithim("Insertion", "Random  ", insertionRand100, sorter, &Algorithims::insertionSort, random_100, Rand100);
    timeAlgorithim("Insertion", "Sort    ", insertionSort100, sorter, &Algorithims::insertionSort, sort_100, Sort100);
    timeAlgorithim("Insertion", "Rev Sort", insertionRevSort100, sorter, &Algorithims::insertionSort, revSort_100, RevSort100);
    cout << endl;

    vector<vector<int>> insertionRand1k = rand1KVec;
    vector<vector<int>> insertionort1k = sort1kVec;
    vector<vector<int>> insertionRevSort1k = revSort1kVec;
    cout << "The size is n = 1000 \n";
    timeAlgorithim("Insertion", "Random  ", insertionRand1k, sorter, &Algorithims::insertionSort, random_1K, Rand1K);
    timeAlgorithim("Insertion", "Sort    ", insertionort1k, sorter, &Algorithims::insertionSort, sort_1K, Sort1K);
    timeAlgorithim("Insertion", "Rev Sort", insertionRevSort1k, sorter, &Algorithims::insertionSort, revSort_1K, RevSort1K);
    cout << endl;

    vector<vector<int>> insertionRand10k = rand10KVec;
    vector<vector<int>> insertionSort10k = sort10kVec;
    vector<vector<int>> insertionRevSort10k = revSort10kVec;
    cout << "The size is n = 10000 \n";
    timeAlgorithim("Insertion", "Random  ", insertionRand10k, sorter, &Algorithims::insertionSort, random_10K, Rand10K);
    timeAlgorithim("Insertion", "Sort    ", insertionSort10k, sorter, &Algorithims::insertionSort, sort_10K, Sort10K);
    timeAlgorithim("Insertion", "Rev Sort", insertionRevSort10k, sorter, &Algorithims::insertionSort, revSort_10K, RevSort10K);
    cout << endl;

    // vector<vector<int>> insertionRand100k = rand100KVec;
    // vector<vector<int>> insertionSort100k = sort100kVec;
    // vector<vector<int>> insertionRevSort100k = revSort100kVec;
    // cout << "The size is n = 100000 \n";
    // timeAlgorithim("Insertion", "Random  ", insertionRand100k, sorter, &Algorithims::insertionSort, random_100K, Rand100K);
    // timeAlgorithim("Insertion", "Sort    ", insertionSort100k, sorter, &Algorithims::insertionSort, sort_100K, Sort100K);
    // timeAlgorithim("Insertion", "Rev Sort", insertionRevSort100k, sorter, &Algorithims::insertionSort, revSort_100K, RevSort100K);

    cout << "\n\n";

    cout << "                 N = 10    \n";
    cout << "Random    :  " << Rand10 << " The Average time was " << random_10 << "\n";
    cout << "Sort      :  " << Sort10 << " The Average time was " << sort_10 << "\n";
    cout << "Rev Sort  :  " << RevSort10 << " The Average time was " << revSort_10 << "\n";
    cout << endl;

    cout << "                 N = 100    \n";
    cout << "Random    :  " << Rand100 << " The Average time was " << random_100 << "\n";
    cout << "Sort      :  " << Sort100 << " The Average time was " << sort_100 << "\n";
    cout << "Rev Sort  :  " << RevSort100 << " The Average time was " << revSort_100 << "\n";
    cout << endl;

    cout << "                 N = 1000    \n";
    cout << "Random    :  " << Rand1K << " The Average time was " << random_1K << "\n";
    cout << "Sort      :  " << Sort1K << " The Average time was " << sort_1K << "\n";
    cout << "Rev Sort  :  " << RevSort1K << " The Average time was " << revSort_1K << "\n";
    cout << endl;

    cout << "                 N = 10000    \n";
    cout << "Random    :  " << Rand10K << " The Average time was " << random_10K << "\n";
    cout << "Sort      :  " << Sort10K << " The Average time was " << sort_10K << "\n";
    cout << "Rev Sort  :  " << RevSort10K << " The Average time was " << revSort_10K << "\n";
    cout << endl;

    cout << "                 N = 100000   \n";
    cout << "Random    :  " << Rand100K << " The Average time was " << random_100K << "\n";
    cout << "Sort      :  " << Sort100K << " The Average time was " << sort_100K << "\n";
    cout << "Rev Sort  :  " << RevSort100K << " The Average time was " << revSort_100K << "\n";
}