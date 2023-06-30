#include <iostream>
using namespace std;

int main () {
	
	const double BASE(4);
	double fromage(800.);
	double eau(2.);
	double ail(2.);
	double pain(400.);
	int nbconvives;
	double rp;
	// errueur, il fallait réaffecter les variables
	//ex=fromage *=rp
	cout << "Combien de convives ?"<< endl;
	cin >> nbconvives;
	rp=nbconvives/BASE;
	cout << "Il vous faut:"<< endl<< fromage*rp<< "g. de fromage"<<endl<<
	eau*rp << "L d'eau"<<endl <<ail*rp<< " gousses d'ail" << endl <<"et "<<pain*rp<<
	"g. de pain" << endl;
	
	
}
