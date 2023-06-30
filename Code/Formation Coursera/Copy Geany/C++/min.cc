#include <iostream>
#include <iomanip> 
using namespace std;

int min(int, int);

int main (){
	int a,b,c;
	cout <<"Donnez 3 int à la suite"<<endl;
	cin >>a;
	cin>>b;
	cin>>c;
	
	cout <<endl<< min(min(a,b),c);
	return 0;
	
}

int min(int a, int b) {
	if (a>b) return b;
	else return a;
	
	
}
