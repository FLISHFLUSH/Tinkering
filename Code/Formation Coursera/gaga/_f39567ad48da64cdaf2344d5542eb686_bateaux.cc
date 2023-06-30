#include <iostream>
#include <cmath>
using namespace std;

enum Pavillon { JollyRogers, CompagnieDuSenegal, CompagnieDOstende };

enum Etat { Intact, Endommage, Coule };

int sq(int x)
{
  return x*x;
}

class Coordonnees
{
public:
  Coordonnees(int un_x, int un_y) : x_(un_x), y_(un_y) {}
  int x() const {
    return x_;
  }
  int y() const {
    return y_;
  }
  void operator+=(Coordonnees const& autre); // à définir plus bas
private:
  int x_;
  int y_;
};

class Navire
{
  /*****************************************************
   * Compléter le code à partir d'ici
   *****************************************************/
  // ----------------classe Navire------------------------- 
    protected:
    Coordonnees coord;
	Pavillon pavillon;
	Etat etat;
	const int rayon_rencontre=10;
	
	virtual string nomGenerique() const {return "Navire"; }
	bool flotte() {if (etat==Coule) return false; return true; }
	
	public:
	Navire(int x, int y, Pavillon p)
	: coord(Coordonnees(x,y)), pavillon(p), etat(Intact) {}
	virtual ~Navire() {}
	
	Coordonnees position() const {
		return coord;
	}
	void avancer(int de_x, int de_y) {
		if (flotte()) coord+=(Coordonnees(de_x, de_y));
	}
	void renflouer() { etat=Intact;}
	ostream& afficher(ostream& ) const ; 
	
};

void Coordonnees::operator+=(Coordonnees const& autre)
{
  x_+=autre.x_;
  y_+=autre.y_;

}

double distance (Navire const& a, Navire const& b) {
	 return sqrt(sq(a.position().x()-b.position().x())+sq(a.position().y()-b.position().y()));
	}
ostream& operator<<(ostream& s, Coordonnees const& a) {
	return s<<"("<<a.x()<<", "<<a.y()<<")";
	}
ostream& operator<<(ostream& se, Pavillon p) {
	string s; if (p==JollyRogers) s="pirate";
	else if (p==CompagnieDuSenegal) s="français";
	else if (p==CompagnieDOstende) s="autrichien";
	else s="pavillon inconnu";
	return se<<s;
	}		
ostream& operator<<(ostream& se, Etat e)  {
    string s; if (e==Intact) s="intact";
	else if (e==Endommage) s="ayant subi des dommages";
	else if (e==Coule) s="coulé";
	else s="état inconnu";	
	return se<<s;
}

ostream& Navire::afficher(ostream& s) const {
return s<<nomGenerique()<<" en "<<coord<<" battant pavillon "<<pavillon<<", " <<etat;
}

ostream& operator<<(ostream& s, Navire n) { return n.afficher(s);}

//----------------sous-classes Navire-------------------------
class Pirate: public virtual Navire {
	public:
	Pirate(int x, int y, Pavillon p)
	:Navire(x,y,p) {}
	
	string nomGenerique() const { return "bateau pirate";}
	 };
class Marchand: public virtual Navire {
	public:
	Marchand(int x, int y, Pavillon p)
	:Navire(x,y,p) {}
	
	string nomGenerique() const { return "navire marchand";}
	};
class Felon: public Pirate, public Marchand {
	public:
	Felon(int x, int y, Pavillon p)
	:Navire(x,y,p), Pirate (x,y,p), Marchand(x,y,p) {}
	
	string nomGenerique() const { return "navire félon";}
	};
/*******************************************
 * Ne rien modifier après cette ligne.
 *******************************************/

void rencontre(Navire& ship1, Navire& ship2)
{
  cout << "Avant la rencontre :" << endl;
  cout << ship1 << endl;
  cout << ship2 << endl;
  cout << "Distance : " << distance(ship1, ship2) << endl;
//  ship1.rencontrer(ship2);
  cout << "Apres la rencontre :" << endl;
  cout << ship1 << endl;
  cout << ship2 << endl;
}

int main()
{
  // Test de la partie 1
  cout << "===== Test de la partie 1 =====" << endl << endl;

  // Un bateau pirate 0,0
  Pirate ship1(0, 0, JollyRogers);
  cout << ship1 << endl;

  // Un bateau marchand en 25,0
  Marchand ship2(25, 0, CompagnieDuSenegal);
  cout << ship2 << endl;

  cout << "Distance : " << distance(ship1, ship2) << endl;

  cout << "Quelques déplacements..." << endl;
  cout << "  en haut à droite :" << endl;
  // Se déplace de 75 unités à droite et 10 en haut
  ship1.avancer(75, 10);
  cout << ship1 << endl;

  cout << "  vers le bas :" << endl;
  ship1.avancer(0, -5);
  cout << ship1 << endl;

  /*cout << endl << "===== Test de la partie 2 =====" << endl << endl;

  cout << "Bateau pirate et marchand ennemis (trop loins) :" << endl;
  rencontre(ship1, ship2);

  cout << endl << "Bateau pirate et marchand ennemis (proches) :" << endl;
  ship1.avancer(-40, -2);
  ship2.avancer(10, 2);
  rencontre(ship1, ship2);

  cout << endl << "Deux bateaux pirates ennemis intacts (proches) :" << endl;
  Pirate ship3(33, 8, CompagnieDOstende);
  rencontre(ship1, ship3);

  cout << endl << "Bateaux pirates avec dommages, ennemis :" << endl;
  rencontre(ship1, ship3);

  cout << endl << "Bateaux marchands ennemis :" << endl;
  Marchand ship4(21, 7, CompagnieDuSenegal);
  Marchand ship5(27, 2, CompagnieDOstende);
  rencontre(ship4, ship5);

  cout << endl << "Pirate vs Felon :" << endl;
  ship3.renflouer();
  Felon ship6(32, 10, CompagnieDuSenegal);
  rencontre(ship3, ship6);

  cout << endl << "Felon vs Pirate :" << endl;
  rencontre(ship6, ship3);*/

  return 0;
}
