#include <iostream>
#include <iomanip> 
using namespace std;

double factorielle(int);
double somme_partielle(double, int);
int demande(int a=2, int b=85);

int main()
{
	double x(2);
	double rang(demande());
cout <<"cos de "<<x<<"="<< somme_partielle(x,rang)<<" au rang "<< rang<<endl;
 return 0;
 
 }

double factorielle (int n) {
	
	double t(1);
	for (int i(0); i<n;++i)
	t=t*(i+1);

	
	return t;
	
}

double somme_partielle(double x, int N) {
	
	double cosN(1);
	double powx(x*x);
	for (int i(1); i<N; i++){
	cosN-=powx/factorielle(2*i);
	powx*=-x*x;
	
}
	return cosN;
}

int demande(int a, int b) {
		int ent(0);
	do {if (a<b) cout << "Donnez un entier entre "<<a<<" et "<<b<< endl;
	else cout << "Donnez un entier supérieur à " << a << endl;
	cin >> ent;
} while (not((ent>=a)and((ent<=b)or(b<=a))));
// =  ent <a or ( ent>b and b>a)
	 return ent;
	 
}
