#include <iostream>
#include <cmath>
using namespace std;

int main () 
{
	
	// log = log nepérien;
cout <<"Entrez la valeur de la variable x" << endl;
double x;
cin >> x;
if (x!=0) 
// ou if (exp(x)==1)
	cout <<"F1(x) vaut :" <<endl << x/(1-exp(x)) <<endl;
	else cout <<"X n'est pas défini dans F1." <<endl;
	
	if ((x>0)and(x!=1))
	cout <<"F2(x) vaut: " <<endl << x*log(x)*exp(2/(x-1)) << endl;
	else cout <<"X n'est pas défini dans F2." <<endl;
	
	if((x<=0)or(x>=8))
	cout <<"F3(x) vaut: " <<endl <<(-x-sqrt(x*x-8*x))/(2-x) <<endl;
	else cout <<"X n'est pas défini dans F3." <<endl;
	double calcpart(0);
 //NB le else peut servir de not()
   
     // quand x!=1 et x >0 , alors x^2 -1/X<0 <=> x^3 -1 <0 <=> x>1
     //quand x <0, alors ... x^3 -1 >0  donc toujours positif pour x<1
     // donc positif quand x>=1
	if ((x<1)and(x>0))
	cout << "X n'est pas défini dans F4." << endl;
	else { calcpart=log(x*x-1/x);
		calcpart=(sin(x)-x/20)*calcpart;
		if (calcpart<0) 
		cout <<"X n'est pas défini dans F4." <<endl;
		else cout << "F4(x) vaut : "<<endl <<sqrt(calcpart);
	}
}
