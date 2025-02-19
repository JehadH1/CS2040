//a header file that includes the vector builder.

#include <vector>
#include <cstdlib>
#include <algorithm>

using namespace std;

//builds any 2D vector you want
vector<vector<int>> buildVector(int row, int col);

//fills any 2D vector with random numbers
void buildRandomVector (vector<vector<int>> &vec);

//will sort the vector you give it 
vector<vector<int>>  buildSortedVector (vector<vector<int>> &vec);

//will sort any vector you give it in reverse
vector<vector<int>>  buildReverseSortedVector(vector<vector<int>> &vec);
