#include <iostream>
using namespace std;

class A{
private:
    int a;
public:
    A(int a1) : a(a1) { }
    int getA() const { return a; }
};

class B : public A{
private:
    int b;
public:
    B(int a1, int b1) : A(a1), b(b1) { }
    int getB() const { return b; }
};

void operate1(A in) { cout << in.getA(); }
void operate2(B in) { cout << in.getB(); }


int main () { 
A a(1); 
B b(2, 42); 
A c(b);

operate1(b);operate2(a);operate2(c);operate1(a);
	return 0;}
