#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include <math.h>

using namespace std;

class Fleur {
	private:
	string fleur;
	string couleur;
	
	public:
	Fleur(string fleur, string couleur) 
	:fleur(fleur), couleur(couleur) { cout <<fleur<<" fraichement cueillie"<<endl; }
	
	Fleur(Fleur const& f) 
    :fleur (f.fleur), couleur(f.couleur) {cout<<"Fragile corolle taill‚e"<<endl; }
    
    ~Fleur() {cout << "qu'un simple souffle"<<endl; }
    
    void eclore() { cout <<"veine de "<<couleur<<endl; }
    
	
	};
	
	int main ()
{
  Fleur f1("Violette", "bleu");
  Fleur f2(f1);
  cout << "dans un cristal ";
  f2.eclore();
  cout << "Donne un poŠme un peu fleur bleue" << endl
       << "ne laissant plus ";
  return 0;
}
