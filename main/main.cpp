#include <iostream>

extern int app1;
namespace xx {
extern int app1;
}
int main() {
  std::cout << xx::app1;
  return 0;
}