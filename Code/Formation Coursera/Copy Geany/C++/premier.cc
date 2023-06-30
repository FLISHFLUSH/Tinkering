
#include <iostream>
#include <cmath>
using namespace std;

int main () {
	cout << " Entrez un nombre entier :" << endl;
	//flemme de faire vérificateur
	int n;
    cin >> n;
    bool premier(false);
    double root=sqrt(n);
    int i(3);
    		cout << n%i << endl;
    if (n%2==0) { i=2; premier=true; }
 
    else while(!(premier)and(i<root)){
		cout << n%i << endl;
		if (n%i==0)  premier= true;
		else i+=2; }
		if (premier) cout << "N n'est pas premier et est divisible par " << i;
		else cout <<
		"N est premier";
    
	
}
