#include <iostream>
#include <string>
#include <vector>
using namespace std;


struct QCM {
	string question;
	vector<string> reponses;
	int solution;
};

typedef vector<QCM> Examen;

void affiche(const QCM& a){
	cout <<a.question<<endl;
	for(size_t i(0); i<a.reponses.size(); ++i)
	cout <<"    "<<i+1<<"- "<<a.reponses[i]<<endl;
	
}
//int … la place de size t fonctionne
int demander_nombre(int a, int b) {
	
	int ent(0);
	do {cout << "Donnez votre r‚ponse par un entier entre "<<a<<" et "<<b<<": ";
	cin >> ent;
} while (not((ent>=a)and((ent<=b)or(b<=a))));
cout<<endl;
// =  ent <a or ( ent>b and b>a)
	 return ent;
	 
}

int poser_question(const QCM& q){
	affiche(q);
	return demander_nombre(1,q.reponses.size());
	
	
}

void creer_examen(Examen& E){
	//size_t r(0);
	E.clear();
	//creation de q non obligatoire
	QCM q;
//char cont;
// apparemment, une r‚ponse terminant par "?" fait bugger le code. les " " pt ?

	// bugg‚, on demandera sur forum
	/* 
	cout<<"Votre question ? ";
	cin >> q.question;
	cout <<"combien de r‚ponses ? "<<endl;
	cin >> r;
	q.reponses=vector<string> (r);
	cout <<" ggggggggg";
	for (size_t i(0); i<r; i++) {
	cout <<endl<< "Reponse "<<i+1;
	cin >> q.reponses[i];
     }
	cout <<endl<< "la solution ? ";
	cin >> q.solution;
    cout << endl<<"Avez-vous d'autres questions ? 'o' pour oui, n'importe quoi pour non "<<endl;
    E.push_back(q);
    cin >> cont;
} while (cont=='o');
*/ 
q.reponses.clear();
q.question="Combien de dents possŠde un ‚l‚phant adulte";
q.reponses.push_back("32");
q.reponses.push_back("de 6 a 10");
q.reponses.push_back("beaucoup");
q.reponses.push_back("24");
q.reponses.push_back("2");
q.solution=2;
E.push_back(q);

q.reponses.clear();
q.question="Laquelle des instructions suivantes est un prototype de fonction";
q.reponses.push_back("int f(0);" );
q.reponses.push_back("int f(int 0);" );
q.reponses.push_back("int f(int i);") ;
q.reponses.push_back( "int f(i);"); 
q.solution=3;
E.push_back(q);

q.reponses.clear();
q.question="Qui pose des questions stupides";
q.reponses.push_back("le prof de math");
q.reponses.push_back("mon copain / ma copine");
q.reponses.push_back("le prof de physique");
q.reponses.push_back("moi");
q.reponses.push_back("le prof d'info");
q.reponses.push_back("personne, il n y a pas de questions stupides");
q.solution=6;
E.push_back(q);

}

int examen(const Examen E) {
	int BonnesReponses(0);
	cout<<"zdadazd";
	for (size_t i(0); i<E.size();i++)
	if (E[i].solution==poser_question(E[i])) ++BonnesReponses;
	return BonnesReponses;

}

int main () {
	// yes, premier try pour init
	QCM  Premier({"Combien de dents possŠde un ‚l‚phant adulte ?", {"32","de 6 … 10", "beaucoup", "24","2"},3});
	Examen E;
	creer_examen(E);
	/* for (auto qcm: E)
	 poser_question(qcm); */
	cout <<"Vous avez "<< examen(E)<< " bonnes r‚ponses sur 3";
}
