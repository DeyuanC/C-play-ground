#include <iostream>
#include<vector>

using namespace std;
struct emp_i{
    int a;
    double b;
};

int main(){

  vector<double*> vc;
  double* array1 =new double[4];
  array1[0]=2;
  vc.push_back(array1);
  //delete[] array1; // this line makes last cout not printed, strange
  cout<<vc[0][0]<<endl;    // vc store vectors so when array1 is deleted, vc is empty

  vector<double> vc2;
  vector<double*> vc3;
  vector<double*> vc4;
  double *d=new double;
  *d=2.5;
  double dd =2;
  vc2.push_back(*d); //
  vc3.push_back(d);//
  vc4.push_back(&dd);//
  cout<<vc2[0]<<endl;
  cout<<*vc3[0]<<endl;
  cout<<*vc4[0]<<endl; // still pointing to d ,which is already deleted



vector<emp_i> vk1;
vector<emp_i*> vk2;
emp_i st_i;
st_i.a=2; st_i.b=2.3;
vk1.push_back(st_i);   //structure name st_i is not a pointer! same as int, different from int[]
vk2.push_back(&st_i);
cout<<&st_i<<endl<<&vk1[0]<<endl<<vk2[0];     // value of vk2[0] is the address of st_i
cout<<endl<<vk1.begin()->a<<vk1.front().a;  // begin() return address,  front return object
vector<emp_i>::iterator itr_vk1;
itr_vk1=vk1.rbegin(); // iterator= front() is wrong
// .rend return the address before first elment  .rbegin return the last element
// .begin return the address of first element, .end return the address after last element
//vk1 copy the value, vk2 copy the reference
  delete d;
  delete[] array1;
}
