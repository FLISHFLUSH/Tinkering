#include <iostream>
#include <cmath>
using namespace std;

void etoiles(int );
void espaces(int );
void triangle(int, int);
void sapin(int); 
void base(int);

int main () {
	int n;
	cin >>n;
sapin (n);
}

void etoiles(int nb_etoiles)
{
  for(int i(0); i < nb_etoiles; ++i) {
    cout << '*';
  }
}
void espaces(int nb_espaces)
{
  for(int i(0); i < nb_espaces; ++i) {
    cout << ' ';
  }
}

void triangle(int n, int a) {
	//etrange, avec un for le cout>>endl; se faisait au début...
	 int i;
 for (i=n-2;i<=n;i++) {
	 //(n-1) auquel on rajoute a-n (ligne final - ligne actuel)
	 espaces (a-i); etoiles (2*i-1);
		cout << endl;
	}
}
 
 void sapin(int n) {
	 for (int i(3);i<=n;++i)
	 triangle(i,n); 
	 base (n);
 
}
void base (int n) {
	espaces(n-2); 
	cout << "|||";
}
