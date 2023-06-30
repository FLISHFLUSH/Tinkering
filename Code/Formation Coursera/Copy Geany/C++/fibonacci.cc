#include <iostream>
#include <cmath>
using namespace std;

int fibonacci(int);

int main () {
	cout <<"entrez un nombre supérieur à 1"<<endl;
	int n;
	cin >> n;
	cout << fibonacci (n);
	
	return 0;
}

int fibonacci(int n) {
	if (n==0) return 0;
	if (n==1) return 1;
	else return fibonacci(n-1) + fibonacci(n-2);
	
}
