#include<iostream>
#include <typeinfo>
using namespace std;
typedef double db;
using it = int;
int main(){
// difference between  auto and decltype

  db x =2.5;
  const db kx = 2.5;

  auto a1 = x;
  decltype(x) d1; d1 =x;
  a1++; d1++; // ok

  // consts

  auto a2 = kx;
  decltype(kx) d2 = kx; // d2 and kx have differnet address
  a2++;// d2++;//  auto pass by value, const is dropped,  decltype inherit the const

  // references with consts
  const db &r_kx =kx;
        db &r_x =x;
  auto a3 = r_kx; //pass by value
  decltype(r_kx) d3 = kx; // d3 and kx have same address
  a3++;// d3++; // for auto, const is dropped, a3=3.5 r_kx=2.5 , for decltype, d3 is const
  decltype(r_x) d3_1 = r_x;
  auto a3_1 = r_x;
  a3_1--; // a3_1 = 1.5  x=2.5
  d3_1++; // x = d3_1 = 3.5


// pointers
const double* pt_kx = &kx;
decltype(pt_kx) pt_d;
 pt_d = &kx; // pointer to a const double
const double kx2 =5;
pt_d = &kx2; // ok ,pointer itself is not consts
//(*pt_d)++; //error
decltype(pt_kx) const pt_d2 = &kx;
//pt_d2 = &kx2; // error

//decltype(*pt_kx) pt_d3 ; // error, *pt_kx here is not double but &double, a reference has to be  assigned
decltype(*pt_kx) pt_d3 =7;
auto *pt_a1 = &kx2; // pt_a1 is same as pt_d  they are all pointers to a const double
//(*pt_a1)++; //error
//cout<<pt_a1<<pt_d; // store same address

cout<<typeid(pt_d3).name();



/*
  const db k_d1 = 2.5;
  auto a = k_d1;
  const auto k_a = k_d1;
  a=a+1; // a=3.5
  auto k_b = k_d1;
  k_b++;
  //k_a++; // error
  auto &r = k_d1;
  //r++; // error
  auto *pt = &k_d1;
  //(*pt)++; //error
  auto *pt1 = &a;
  (*pt1)++; //ok   a=k_d1 is passed by value const is dropped

  //decltype(k_d1) d2; //error,  inherit the const, so the variable value has to be assigned
  decltype(k_d1) d2=3.5;
  //d2++; error for obvious reason

  double d0 =2.5;
  const decltype(k_d1) d3 = d0;
  //d3++ //error, same reason

    cout<<typeid(d3).name();
    */
  return 0;
}
