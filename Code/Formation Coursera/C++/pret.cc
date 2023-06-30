
#include <iostream>
#include <cmath>
using namespace std;

int main () {
	cout << "Entrez à la chaîne la valeur initiale du pret, le montant "
	<< "rembouré par mois ainsi que la coefficient mensuel des intérêts : "<<endl ;
	double S; double r; double ir;
			cout << endl;
	do { cin >> S;
		if (S<0) cout << "Entrez une valeure convenable" << endl;
		} while (S<0);
				cout << endl;
    do { cin >> r;
		if (r<0) cout << "Entrez une valeure convenable"<<endl;
		} while (r<0);
		cout << endl;
	do { cin >> ir;
		if (ir<0) cout << "Entrez une valeure convenable"<<endl<<endl;
		} while (ir<0);
		cout << S << endl;
		double banque(0);
	while (S>0) {
		banque+= 0.01*S;
		S=S-r;
	};
		cout << banque<<endl;
		
}
