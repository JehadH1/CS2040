#include <iostream>
#include <iomanip>
#include <vector>
#include <cstdlib>
#include <string>
#include "Algorithims/algorithims.h"
#include "VecBuilder/vecBuilder.h"

using namespace std;

int main()
{
    Algorithims sorter;
    VecBuilder vecBuild;
    srand(time(0));
    double best1kRand = 1000000, best10kRand = 1000000, best100kRand = 1000000;
    double best1kSort = 1000000, best10kSort = 1000000, best100kSort = 1000000;
    double best1kRevSort = 1000000, best10kRevSort = 1000000, best100kRevSort = 1000000;

    string Rand1K, Rand10K, Rand100K;
    string Sort1K, Sort10K, Sort100K;
    string RevSort1K, RevSort10K, RevSort100K;

    clock_t start, end;
    // build the three sizes (1k, 10k, 100k) vectors;
    vector<vector<int>> rand1KVec = vecBuild.buildVector(10, 1000);
    vector<vector<int>> rand10KVec = vecBuild.buildVector(10, 10000);
    vector<vector<int>> rand100KVec = vecBuild.buildVector(10, 100000);

    // populate the three vectors with random numbers
    vecBuild.buildRandomVector(rand1KVec);
    vecBuild.buildRandomVector(rand10KVec);
    vecBuild.buildRandomVector(rand100KVec);

    // build the three vectors of (1k 10k 100k) with sorted numbers
    vector<vector<int>> sort1kVec = vecBuild.buildSortedVector(rand1KVec);
    vector<vector<int>> sort10kVec = vecBuild.buildSortedVector(rand10KVec);
    vector<vector<int>> sort100kVec = vecBuild.buildSortedVector(rand100KVec);

    // build the three vectors of (1k 10k 100k) with rev sorted numbers
    vector<vector<int>> revSort1kVec = vecBuild.buildReverseSortedVector(rand1KVec);
    vector<vector<int>> revSort10kVec = vecBuild.buildReverseSortedVector(rand10KVec);
    vector<vector<int>> revSort100kVec = vecBuild.buildReverseSortedVector(rand100KVec);

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
        sorter.selectionSort(row);
        end = clock();
        double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
        if (time_taken < best1kRand)
        {
            best1kRand = time_taken;
            Rand1K = "Selection Sort";
        }
        cout << "| " << setw(6) << fixed << setprecision(5) << time_taken << " |";
    }
    cout << "Best times and the algorithms:\n";
    cout << "sizes are smaller due to taking to long on my computer\n\n";

    cout << "                 N = 1000    \n";
    cout << "Random  :  " << Rand1K << " " << best1kRand << "\n";
    cout << "Sorted  :  " << Sort1K << " " << best1kSort << "\n";
    cout << "Reverse :  " << RevSort1K << " " << best1kRevSort << "\n";
    cout << "\n\n";

    cout << "                 N = 10000    \n";

    cout << "Random  :  " << Rand10K << " " << best10kRand << "\n";
    cout << "Sorted  :  " << Sort10K << " " << best10kSort << "\n";
    cout << "Reverse :  " << RevSort10K << " " << best10kRevSort << "\n";
    cout << "\n\n";
}