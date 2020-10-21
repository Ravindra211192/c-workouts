#include <iostream>
#include <string>
#define DEBUG
#include <assert.h>
#include <sstream>
using namespace std;

template <typename T>
class MyClass
{
    private:
     T Val;

    public:
     static int S;
     void SetVal(const T& x) { Val = x;}
     const T& GetVal() const { return(Val); }
};

template <typename T>
T Square(const T& y)
{
    T ySquared = y * y;
    return(ySquared);
}

//Static data member has to be defined outside the class
template<typename T> int MyClass <T>::S;

int main()
{
#ifdef DEBUG
   cout << "I'm doing debug test now!" << endl;
#endif

int x = 1;
assert(x);

int p =2 ;
int psquared = Square(p);
cout << p << " squared = " << psquared << endl;

double q = 0.5;
double qSquared = Square(q);
cout << q << " squared =" << qSquared << endl;

MyClass <int> I;
I.SetVal(42);
cout << " The set value is: " << I.GetVal() << endl;

MyClass <double> Y;
Y.SetVal(3.145);
cout << " The Set value is: " << Y.GetVal() << endl;

MyClass <int> IntClass;
MyClass <int> IntClass2;
MyClass <int> IntClass3;
IntClass.S = 5;

MyClass <double> DoubleClass;
DoubleClass.S = 99;

IntClass3.S = 4 ;

cout << "IntClass static value: " << IntClass.S << endl;
cout << "IntClass static value: " << IntClass2.S << endl;
cout << "IntClass static value: " << IntClass3.S << endl;
cout << "DoubleClass static value: " << DoubleClass.S << endl;
}