#include<iostream>
#include<vector>
using namespace std;
// 一串数字中，震荡幅值在正负step之间的最长序列及位置

class findlongest {
public:
  vector<int> find(const vector<int> &input, const int step){
    int length = input.size();


    if (input.empty()) {
      return vector<int> (3,0);
    }
    if (input.size()==1) {
      return vector<int> (3,1);
    }
    int index_s=0;
    int index_f=0;
    int upp,low;
    int max_old=1;
    int reverse_length=1;
    upp = input[0]+step;
    low = input[0]-step;

    for (size_t i = 1; i < length; i++) {
      if (input[i]>upp||input[i]<low) { //outsider
        reverse_length=1;
        upp = input[i]+step;
        low = input[i]-step;
      }else{
        reverse_length++;
        upp=(input[i]+step<upp)?input[i]+step:upp;
        low=(input[i]-step>low)?input[i]-step:low;
      }
      if (reverse_length>=max_old) {
        max_old = reverse_length;
        index_f = i;
        index_s = i - reverse_length +1;
      }
      }
    std::vector<int> result(3,0);
    result[0]=max_old;
    result[1]=index_s+1;
    result[2]=index_f+1;
    return result;
  }
};

int main(void){
  findlongest A;
  int myints[] = {3,1,4,1,5,9,2,6,5,3,5,8,9,7,9};
  vector<int> input2 ={3,5,6};
  input2.pop_back();
 vector<int> input (myints, myints + sizeof(myints) / sizeof(int) );
 auto res = A.find(input,3);
 for(auto j:input2)
  cout<<j<<" ";
}
