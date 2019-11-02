#include <iostream>
#include <string>
#include <iomanip>
#include<map>
using namespace std;
struct unit_info
{
	int dist;
	std::string original_unit;
	std::string certain;
	std::string changed_unit;
	//char original_unit[10];
	//char certain[10];
	//char changed_unit[10];
};

map<string,string> map_name={
	{"thou","th"},{"th","th"},{"inch","in"},{"in","in"},{"foot","ft"},{"ft","ft"},
	{"yard","yd"},{"yd","yd"},{"chain","ch"},{"furlong","fur"},{"fur","fur"},
{"mile","mi"},{"mi","mi"},{"league","lea"},{"lea","lea"}
};
map<string,double>map_value={
	{"th",1},{"in",1000},{"ft",12*1000},{"yd",3*12*1000},{"ch",22*3*12*1000},
	{"fur",10*22*3*12*1000},{"mi",8*10*22*3*12*1000},{"lea",3*8*10*22*3*12*1000}
};

int main()
{
	unit_info distance;
	std::cin >> distance.dist;
	std::cin >> distance.original_unit;
	std::cin >> distance.certain;
	std::cin >> distance.changed_unit;
	//scanf_s("%d %s %s %s", &distance.dist, &distance.original_unit[0], &distance.certain[0], &distance.changed_unit[0]);
	string left,right;
	double mult,output;
	left = map_name[distance.original_unit];
	right = map_name[distance.changed_unit];
	mult = map_value[left]/map_value[right];
	output = (double)distance.dist*mult;


  std::cout<<setprecision(12)<<output<< std::endl;

  return 0;
  }
