#include <iostream>
#include <fstream>

using namespace std;

int main() {

int ia=2;
int ib=10;
const int &ref_ia =ia;
ia=3;  //ok
 int* const pt1 = &ia; //top level pointer, obj value can be changed but pointer can not be re-assigned
const int* pt2 =&ia;  //low level pointer, pointer itself can be re-assigned but the obj can not
(*pt1)++; //ok   but (*pt2)++  is error
pt2 = &ib;  //ok  but pt1 = &ib is error
int *pt3 =pt1; // ok  top level const is ignored  but int *pt3 =pt2 is error
const int *pt4 =pt2; //ok  assign const to const
  return 0;
  //
}
