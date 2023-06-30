#include <iostream>
#include <string>
#include <vector>
using namespace std;

class popo {
public:
double x;
popo(double x=3)
:x(x) {}

};

class momo {
double t;
momo(popo const& p)
: t(p.x) {}

public:
void afficher(){
cout <<t<<"  t "<<endl; }
};

momo tududu(unsigned int n, momo const& a)
{momo b(a);
	
}

int main () {
	tududu(2,2);
	return 0;
}
