#include <iostream>
#include <vector>
#include <string>
using namespace std;
int l(0);


class momo {
	int val;
	//const obligatoire car sinon crée copie, donc boucle infinie
	momo(momo const& l)
	{}
	};
int& popo() {
	//int l(0);
return l;
}

int main () {

int j=popo();
cout<<j;
return 0;
}
