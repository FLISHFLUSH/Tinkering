#include <iostream>
#include <cmath>
using namespace std;

int demander_annee(){
	int n(0);
	while ((n<1583)or(n>4000)) {
	cout << "Entrez une annee (1583-4000) : ";
	cin >>n;
	}
	return n;
}

void affiche_date(int a, int b){
cout << "Date de Paques en "<< a<< " : " ;
if (b>=32) { b=b-31;
	cout <<b<< " Avril"<<endl; }
	else cout <<b<<"Mars"<<endl;
	
}	
int date_Paques(int a) {
	int siecle(a/100);
	int p((8*siecle+13)/25);
	int q(siecle/4);
	int M((15-p+siecle-q)%30);
	int N((4+siecle-q)%7);
	int d((M+19*(a%19))%30);
	int e((2*(a % 4) + 4*(a % 7) + 6*d + N) % 7);
	int jour(e+d+22);
if ((e==6)and((d==29)or((d==28)and((11*(M+1))%30<19)))) jour-=7;
return jour;
}

int main ()  {
int annee(demander_annee());
affiche_date(annee, date_Paques(annee));

return 0;
}
