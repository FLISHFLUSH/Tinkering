#include <iostream>
#include <cmath>
using namespace std;
int main () {
	cout <<"Entrez respectivement deux nombres a et b strictement  positifs :" <<endl;
	int a, b;
	do { cin >> a;
		if (a<=0) cout <<"Entrez un a stricement positif!"<< endl;
	}	while (a<=0);
	cout <<endl;
	do {cin >> b;
		if (b<=0) cout <<" Entrez un b stricement positif" << endl;
		}while (b<=0);
		cout <<endl;
	

int x(a), y(b),u(1),u1(0),v(0),v1(1);
int q,r,temp(0);
cout << "x         y         u         v"<<endl;
//fait super rapidement.
while (y!=0) {
q=x/y; r=x%y;

temp=u1;
u1=u-u1*q;u=temp;

temp=v1;
v1=v-v1*q; v=temp;


x=y; y=r;
cout << x<<"         "<<y<<"         "<<u1<<"         "<<v1<<endl;
}


cout <<endl<<"PGCD("<<a<<","<<b<<")="<<x;
}
