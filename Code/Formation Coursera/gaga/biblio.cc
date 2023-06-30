#include <iostream>
#include <vector>
#include <string>
using namespace std;

/*******************************************
 * Completez le programme a partir d'ici.
 *******************************************/
// Chaines de caractères à utiliser pour les affichages:
/*

été jeté

d'un

n'est

L'oeuvre

bibliothèque

détruit

*/
class Auteur {
 string nom;
 bool primay;
 
 public:
 Auteur(string nom, bool primay=false)
 : nom(nom), primay(primay)   {}
 
 string getNom() const {return nom;}
 bool getPrix() const{return primay;}
	};
class Oeuvre {
	Auteur& auteur;
	string titre;
	string langue;
	
	public:
	Oeuvre(string titre, Auteur& auteur, string langue) 
	//auteur devient une référence de la référence ??
	//un objet a est il une reference vers lui meme ?
	:titre(titre), auteur(auteur), langue(langue) {}
	
	
	string getTitre() {return titre; }
	Auteur& getAuteur() {return auteur;}
	string getLangue() {return langue;}
	void affiche() {
		//tester *auteur.nom
		cout<<titre<<", "<<auteur.getNom()<<", en "<<langue;	
	}
	
	~Oeuvre() {cout<<"L'oeuvre \""; affiche(); cout<<"\" n'est plus disponible."<<endl; }
		
	
	};
	
class Exemplaire {
	// passable en public si déclaré comme constant. 'v'
	Oeuvre& oeuvre;
	
	public:
	Exemplaire(Oeuvre& o)
	:oeuvre(o) {cout<<"Nouvel exemplaire de : "; oeuvre.affiche();cout<<endl;}	
	Exemplaire(Exemplaire const& E)
	:oeuvre(E.oeuvre) {cout<<"Copie d’un exemplaire de : "; oeuvre.affiche();cout<<endl; }	
	~Exemplaire() {cout<<"Un exemplaire de \""; oeuvre.affiche();cout<<"\" a été jeté !"<<endl;}
	
	Oeuvre& getOeuvre() const {return oeuvre;}
	
	void affiche() {
		cout<<"Exemplaire de : "; oeuvre.affiche(); cout<<endl;
		}
	};
		
class Bibliotheque {
	vector<Exemplaire*> biblio;
	string nom;
		
		public:
		Bibliotheque(	string nom)
		:nom(nom) {cout<<"La bibliothèque "<<nom<<" est ouverte !"<<endl;}
		~Bibliotheque() {cout <<"La bibliothèque "<<nom<<" ferme ses portes,"<<endl<<"et détruit ses exemplaires :"<<endl ;
			 for (auto ex:biblio) 	
				delete ex; }
		
		string getNom() {return nom;}
		
		void stocker(Oeuvre&  o, unsigned int n=1) {
			for (size_t i(0); i<n; i++){
				//avec un new, pas de variable donc pas d'effacement automatique en fin de block, et donc
				//la valeur est conservée.
				// c'est ça l'allocation dynamique.
				Exemplaire* ptr = new Exemplaire(o);
			biblio.push_back(ptr);

		}
	}
		
		 void lister_exemplaires(string langue="") {
			//if (langue.size()>0) cout<<"Les exemplaires "<<"en "<<langue; cout<<" sont :"<<endl;
			for(auto ex:biblio) {
			//-> ?
			if ((ex->getOeuvre().getLangue()==langue)or(langue.size()==0))
			ex->affiche();
			//cout<<"tudududu";
		    }
	    }
	    // travailler par référence, sinon copie + destructeur
	    unsigned int compter_exemplaires(Oeuvre& o) {
			unsigned int n(0);
		for(auto ex:biblio){
			//comme oeuvre1==oeuvre2 n'a pas de sens, on teste les adresses (car on travialle sur référence).
			if (&ex->getOeuvre()==&o) n++; 
			}	
			return n;
		}
		
		void afficher_auteurs(bool primay=false) {
			
			//(not primay and auteur.primay)
		for(auto ex:biblio){
		Auteur A(ex->getOeuvre().getAuteur());
		// si primay est faux alors not primay vrai donc toujours (A.getPrix())or(not primay) vrai
		// si primay est vrai alors not primay faux et affiche seulement pour a.getprix vrai
		if ((A.getPrix())or(not primay)) cout <<A.getNom()<<endl;
	}
			
		}
		
			
		
		};
/*******************************************
 * Ne rien modifier apres cette ligne.
 *******************************************/

int main()
{
  Auteur a1("Victor Hugo"),
         a2("Alexandre Dumas"),
         a3("Raymond Queneau", true);

  Oeuvre o1("Les Misérables"           , a1, "français" ),
         o2("L'Homme qui rit"          , a1, "français" ),
         o3("Le Comte de Monte-Cristo" , a2, "français" ),
         o4("Zazie dans le métro"      , a3, "français" ),
         o5("The Count of Monte-Cristo", a2, "anglais" );

  Bibliotheque biblio("municipale");
  biblio.stocker(o1, 2);
  biblio.stocker(o2);
  biblio.stocker(o3, 3);
  biblio.stocker(o4);
  biblio.stocker(o5);

  cout << "La bibliothèque " << biblio.getNom()
       << " offre les exemplaires suivants :" << endl;
  biblio.lister_exemplaires();

  const string langue("anglais");
  cout << " Les exemplaires en "<< langue << " sont :" << endl;
  biblio.lister_exemplaires(langue);

  cout << " Les auteurs à succès sont :" << endl;
  biblio.afficher_auteurs(true);

  cout << " Il y a " << biblio.compter_exemplaires(o3) << " exemplaires de "
       << o3.getTitre() << endl;

  return 0;
}
