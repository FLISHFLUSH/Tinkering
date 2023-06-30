#include <iostream>
#include <iomanip> 
using namespace std;

int demander_nombre(int, int);

int main()
{
demander_nombre(2,5);
return 0;
}

int demander_nombre(int a, int b) {
	
	int ent(0);
	do {cout << "Donnez un entier entre "<<a<<" et "<<b<< endl;
	cin >> ent;
} while (not((ent>=a)and((ent<=b)or(b<=a))));
// =  ent <a or ( ent>b and b>a)
	 return ent;
	 
}
