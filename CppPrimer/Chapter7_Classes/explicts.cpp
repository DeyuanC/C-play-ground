
#include <iostream>
using namespace  std;

class A
{
public:

     explicit A(int a)
    {
        cout<<"创建类成功了!"<<endl;


    }
  };

    class B
    {
    public:

         B(int a)
        {
            cout<<"创建类成功了!"<<endl;


        }


};
int main()
{

    A a(10);
    A aa=10; // explicit function can not be called
    B b =10;
    return 0;
}
