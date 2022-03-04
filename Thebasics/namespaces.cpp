#include<iostream>
#include<vector>
using namespace std;
//https://docs.microsoft.com/en-us/cpp/cpp/scope-resolution-operator?view=vs-2017
class ClassG {
public:
    static int get_x() { return x;}
    static int x;
};

namespace NamespaceD{
    namespace NamespaceD1{
        int x;
    }
}

namespace NamespaceE{
    class ClassE{
    public:
        class ClassE1{
        public:
            int x;
        };
    };
}

int ClassG::x = 6;

int main() {

    int gx1 = ClassG::x; //You must use the scope resolution operator to call static members of classes.
    int gx2 = ClassG::get_x();
		ClassG G1,G2;
		G1.x = 4;
		cout<<G2.x<<" "<<G1.x; //G1.x and G2.x have same value, because they share the same memory

		NamespaceD:: NamespaceD1::x = 6;
		NamespaceE::ClassE::ClassE1 e1;
e1.x = 7  ;
}
