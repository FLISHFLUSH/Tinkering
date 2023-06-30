#include <iostream>
#include <vector>
#include <string>
#include <memory>

using namespace std;

struct Fraction {
	
	int num;
	int denom;
};

unsigned int pgcd(unsigned int a, unsigned int b) 
{
  unsigned int m;
  if (a < b) {
    m = a;
  } else {
    m = b;
  }
  while ((a % m != 0) or (b % m != 0)) {
    --m;
  }
  return m;
}



Fraction init_frac(int num, int den)
{
  const unsigned int div( pgcd( abs(num), abs(den) ) );
  if (num < 0 and den < 0) {
    num = -num;
    den = -den;
  }//pgcd donc pas de soucis avec diviszion entière
  return { num / div , den / div };
}

void afficher_frac(Fraction f) {
	cout <<f.num<<"/"<<f.denom<<endl;
}


Fraction add_frac(Fraction f1, Fraction f2) {
	//on peut faire agir fin_PGCD déjà à l'intéreiur sur F1 et F2 pour éviter que les ints ne grossissent trop.
	
	//une fraction contient 2 int, on pourrait bidouiller init_frac de telle sorte qu'ell renvoie une fraction booleenne 
	// 1/0 ou 0/1. Peut etre utile pour savoir si un denom est multiple de l'autre.
	//FLEMME
	return init_frac(f1.num*f2.denom+f2.num*f1.denom, f2.denom*f1.denom);
	}

int main () {
	Fraction f({48,72});
	init_frac(f.num,f.denom);
	f=(add_frac(f,f));
	afficher_frac(f);
}
