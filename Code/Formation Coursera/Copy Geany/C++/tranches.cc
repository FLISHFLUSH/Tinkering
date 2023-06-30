#include <iostream>
#include <vector>
#include <string>
#include <memory>

using namespace std;

typedef size_t Position;
typedef vector<int> Sequence;

struct SousSequence {
	Position debut;
	Position fin;
	int somme;
	
};
SousSequence tranche_max_1(Sequence const& S) {
	SousSequence sseq={1,1,S[0]};
		for (size_t i(0); i<S.size()-1;i++)
		   for (size_t j(i); j< S.size()-1;j++) {
		   int somme(0);
		   // /!\ i et j délimite le sous ensemble donc on doit avoir t<=j et non t<j;
		     for (Position t(i); t<=j;	t++) {
			 somme+=S[t];
			 if (somme>sseq.somme) sseq={i,j,somme};
			 }
	              	   
		 }  return sseq;
}

SousSequence tranche_max_2(Sequence const& S) {
	
	SousSequence sousseq={1,1,S[0]};
	for (size_t i(0); i<S.size()-1; i++){
	int somme(0);
	   for (size_t j(i); j<S.size()-1;j++) {
		   // si on trouve une somme de sous seq plus grande que l'ancienne, la réecrire;
	   somme+=S[j];
	   if (somme>sousseq.somme)
	    sousseq={i,j,somme};
   }
}
   return sousseq;
}

SousSequence tranche_max_3(Sequence const& S) {
	//exemple du cours: 4 -5 3 => on commence à 3.
	//Idée: [sousensemble]_-X _ Y, on ramène sous ensemble à sa somme, on obtient qqchose d'analogue S_-X _Y
	// si S+X<0 on fait somme =0 et on passe à Y.
	SousSequence sseq={1,1,S[0]};
	size_t i(0);
	int somme(0);
	for (size_t j(0); j<S.size(); j++) {
		cout << somme<<endl;
		somme+= S[j]; 
		if (somme>sseq.somme) sseq={i,j,somme};
			if (somme<=0) {
				i=j+1;
				somme=0; 
	}
}
	return sseq;	
}



int main() {
	Sequence seq({11, 13, -4, 3, -26, 7, -13, 25, -2, 17, 5, -8, 1});
	SousSequence sousseq=tranche_max_3(seq);
	cout << sousseq.debut<<"   "<<sousseq.fin<<"   " <<sousseq.somme<<endl;
	return 0;
	
	
	   
}

