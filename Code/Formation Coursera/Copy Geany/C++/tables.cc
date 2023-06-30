#include <iostream>
using namespace std;

int main (){
	cout << "Tables de multiplication" << endl << endl;
	for (int i(2);i<=10;++i) {
		cout << "Table de " << i << " :" << endl;
		for (int j(1);j<=10;++j)
		cout <<"  " << i << " * " << j << " = " << j*i << endl;  
	cout << endl;
	}
	


	
}
