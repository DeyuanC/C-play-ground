#include<vector>

template <typename T> std::vector<std::vector<T>> ArrayCut(const std::vector<T> &arrayin){
  std::vector<std::vector<T>> arrayout;
  arrayout.resize(1,std::vector<T>(0));
  arrayout[0].push_back(arrayin.front());
  for(size_t i=1; i<arrayin.size();i++){
    if ((arrayin[i]*arrayin[i-1])<0||(arrayin[i]==0&&arrayin[i-1]==0)) {
      arrayout.resize(arrayout.size()+1,std::vector<T>(0));
    }
    arrayout[arrayout.size()-1].push_back(arrayin[i]);
  }
  return arrayout;
};
