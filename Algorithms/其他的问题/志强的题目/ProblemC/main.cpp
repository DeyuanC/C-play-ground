#include<iostream>
#include<vector>
#include <fstream>
#include<string>
#include<map>
#include<math.h>

using namespace std;
int main() {
  remove("output.txt");
  ifstream fin("data.in",ios::in);
  ofstream fout("output.txt",ios::app); //append

  //declare
  int N;
  vector<string> i2n; //index to name
  map<string,int> n2i; //name to index
  vector<int> index; // units descending index  example: input is  [km cm mm m] index is 0 3 1 2
  vector<vector<double> > mat;  // N x N matrix, x and y follow the sequence of i2n
  string str_l,str_r; //left and right
  int i_mult; // left = right * i_mult
  int i_first=-1; //index of first unit, default value -1, example: input is  [km cm mm m] i_first is 0
  int num; // used for output

  fin>>N; // read N

  while(N!=0){
  //clear
  i2n.clear();
  n2i.clear();
  index.clear();
  for(auto p:mat)
    p.clear();
  mat.clear();

  //init
  i_first=-1;
  i2n.resize(N);
  mat.resize(N,vector<double>(N,0));
  for (size_t i = 0; i < N; i++) { // read all units
    fin>>i2n[i];
    n2i[i2n[i]] = i;
    cout<<"name is "<<i2n[i]<<endl;
  }
  for (size_t i = 0; i < N; i++) {
    mat[i][i]=1;
  }
  for (size_t i = 0; i < N-1; i++) { // read multiplier
    fin>>str_l; // unit name on the left
    fin>>str_r; // read =
    fin>>i_mult; // multiplier
    fin>>str_r; // unit name on the right
    mat[n2i[str_l]][n2i[str_r]]=i_mult; //mat[x,y] = i2n[x]/i2n[y] for example:  km/m =1000
    mat[n2i[str_r]][n2i[str_l]]=1.0/i_mult;

  }

// go through the mat, fill the rest 0s in the mat, I can not prove this method always succeed
  for (size_t i = 0; i < N; i++) {
    for (size_t j = 0; j < N; j++) {

      if (mat[i][j]==0&&mat[j][i]==0) { // try to complete the blank
        for (size_t a = 0; a < N; a++) { //mat[x][y]=mat[x][a]*mat[a,y]
          if (mat[i][a]!=0&&mat[a][j]!=0) {
            mat[i][j]=mat[i][a]*mat[a][j];
            mat[j][i] = 1/mat[i][j];
          }
        }
      }
    }
  }
/*  compute the mat reversely to increase the chance
  for (size_t i = N-1; i > 0; i--) {
    for (size_t j = N-1; j > 0; j--) {

      if (mat[i][j]==0&&mat[j][i]==0) { // try to complete the blank
        for (size_t a = 0; a < N; a++) { //mat[x][y]=mat[x][a]*mat[a,y]
          if (mat[i][a]!=0&&mat[a][j]!=0) {
            mat[i][j]=mat[i][a]*mat[a][j];
            mat[j][i] = 1/mat[i][j];
          }
        }
      }
    }
  }
  */

  //print the mat
  cout<<"    ";
for (size_t i = 0; i < N; i++) {
  cout<<i2n[i]<<" ";
}
  cout<<endl;
  for (size_t i = 0; i < N; i++) {
    cout<<i2n[i]<<" ";
    for (size_t j = 0; j < N; j++) {
      cout<<mat[i][j]<<" ";
}
cout<<endl;
}


for (size_t i = 0; i < N; i++) {
  for (size_t j = 0; j < N; j++) {
    if (mat[i][j]<1.0)
      break;
    if (j==N-1){
      i_first = i;
    }
  }
    if (i_first>=0)
      break; // i_first found, break
  }

index.push_back(i_first);
cout<< "index first is "<<i_first<<endl;
for (size_t i = 0; i < N; i++) {
  if (i==i_first) // skip mat[x,y] when x=y
    continue;
    for (size_t j = 0; j < index.size(); j++) { //travel the index
      if (mat[i_first][i]>mat[i_first][index[j]]&&j==index.size()-1) { //if j at the end of the index
        index.push_back(i);// last element
        continue;
      }
      if (mat[i_first][i]>mat[i_first][index[j]]&&mat[i_first][i]<mat[i_first][index[j+1]]) { //if j in between indexs
        index.insert(index.begin()+j+1,1,i);
        continue;
      }
    }
}

for (auto p:index) {
  cout<<p<<" ";
}
cout<<endl;


// output
fout<<1<<i2n[index[0]]<<" ";

for (size_t i = 1; i < N; i++) {
  num = round(mat[i_first][index[i]]);
  fout<<"= "<<num<<i2n[index[i]]<<" ";
}
  fout<<endl;
  fin>>N;
  }
  return 0;
}
