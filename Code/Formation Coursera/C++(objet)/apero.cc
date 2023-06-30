#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include <math.h>

using namespace std;
class Apero {
		
		
	public :
	Apero() { cout << "L'heure de l'apéro a sonné!" <<endl;} 
	~Apero() {cout <<"A table !"<<endl;}
   void bis() {cout <<"encore une!"<<endl; }
	};

int main() {
  Apero bic;
  cout << "Super !" << endl;
  bic.bis();
  cout << "Non merci." << endl;
  return 0;
}
