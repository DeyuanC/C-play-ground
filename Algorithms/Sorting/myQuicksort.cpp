#include <iostream>
#include <vector>

using namespace std;

// template<typename T>
// void quickSort(vector<T> &array, int left, int right)
// {

//     int l=left, r=right;
//     T pv = array[left],temp; //pivotalvalue

//   if (l<r) {
//     while (l<r) {
//       while (l<r&&array[r]>pv)
//         r--;
//       while (l<r&&array[l]<=pv){
//         l++;
//       }
//       if (l<r) {
//         temp=array[l];
//         array[l]=array[r];
//         array[r]=temp;
//       }
//     }
//     array[left]=array[l];
//     array[l]=pv;
//     quickSort(array,left,l-1);
//     quickSort(array,l+1,right);
//   }
// }

void quickSortSmallk(vector<double>& array, int left_index, int right_index,
                     int k) {
  if (left_index > k - 1) {
    return;
  }
  int l = left_index;
  int r = right_index;
  // x x x x x x x
  // l<           r >=
  if (l < r) {
    double base_val = array[l];
    while (l < r) {
      while (l < r && array[r] > base_val) {
        r--;
      }

      while (l < r && array[l] <= base_val) {
        l++;
      }
      if (l <= r) {
        double temp = array[l];
        array[l] = array[r];
        array[r] = temp;
      }
    }
    array[left_index] = array[l];
    array[l] = base_val;
    quickSortSmallk(array, left_index, l - 1, k);
    quickSortSmallk(array, l + 1, right_index, k);
  }
}
int main() {
  vector<double> array = {7, 8, 5, 11, 2, 2, 1};

  quickSortSmallk(array, 0, array.size() - 1, 111);
  for (auto& p : array) cout << p << " ";
  cout << endl;
  return 0;
}
