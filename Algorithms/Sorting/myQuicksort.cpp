#include<iostream>
#include<vector>

using namespace std;

template<typename T>
void quickSort(vector<T> &array, int left, int right)
{

    int l=left, r=right;
    T pv = array[left],temp; //pivotalvalue

  if (l<r) {
    while (l<r) {
      while (l<r&&array[r]>pv)
        r--;
      while (l<r&&array[l]<=pv){
        l++;
      }
      if (l<r) {
        temp=array[l];
        array[l]=array[r];
        array[r]=temp;
      }
    }
    array[left]=array[l];
    array[l]=pv;
    quickSort(array,left,l-1);
    quickSort(array,l+1,right);
  }
}

int main()
{
	vector<double> array = {2,3,3,4,2,1,3,2,1};

	quickSort(array,0,array.size()-1);
  for(auto &p:array)
    cout<<p<<" ";
    cout<<endl;
	return 0;
}
