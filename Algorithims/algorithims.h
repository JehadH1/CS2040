//a header file that includes the soring algorithims.

#include <vector>
using namespace std;

//selection sort
void selectionSort(vector<int> &vec);

//bubble sort
void bubbleSort(vector<int> &vec);

//insertion sort
void insertionSort(vector<int> &vec);

//merge sort
void mergeSort(vector<int> &vec);
void merge(vector<int> &left, vector<int> &right, vector<int> &vec);

//quick sort
void quickSort(vector<int> &vec, int left, int right);
int partion(vector<int> &vec, int left, int right);