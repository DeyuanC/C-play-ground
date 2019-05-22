#include <iostream>
#include<vector>
using namespace std;

int main(){
  int a_a[5]={1,2,3,4,5};
  int* pt_a = a_a;  //a_a is a pointer
  int a_a2[]= {2,3,4};
  cout<<a_a<<endl<<&a_a<<endl;  // &a_a and a_a have same value but &a_a refer to a pointer pointing at the whole array
  cout<<a_a+1<<endl<<&a_a+1<<endl; //a_a+1 points at a_a[1]  &a_a+1 points at the end of a_a
  cout<<a_a[0]+1<<" "<<&a_a[0]+1<<endl; // a_a[0] return the stored value of array, &a[0]+1 still the value of pointer
  cout<<sizeof(a_a)<<" "<<sizeof(&a_a)<<" "<<sizeof(pt_a)<<endl; //  sizeof(a_a) return the number of bits of the whole array
  cout<<pt_a<<endl<<&pt_a;     // pointer and &pointer have different value of course
//find it hard to reference a array

  const int a_b[3]={1,2,3};
  const int* rf_a_b = a_b;
    //int* rf_a_b2 =a_b; this is error  a_b is const
  const vector<double> v_a={2,3,4};
  const vector<double> &rf_v = v_a;
  const vector<double> v_b = v_a;  // both v_b and rf_v have same value but differnt address
  cout<<rf_v[1]<<v_b[1];
	return 0;
}
