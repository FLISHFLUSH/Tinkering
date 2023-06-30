#include <iostream>
#include <vector>
#include <string>
#include <memory>

using namespace std;

bool nextToken(string const& str, int& from, int&len){
	//ligne superflue ?
	
	//pas de str.size()-1 car 0-1 en size t c'est moche;
	if (from+1>str.size()) {  return false;}//cout <<"tudu"<<str.size()-1<<endl;
	//cout<<str[from]<<"*";
	string s=str.substr(from,str.size()-from+1); //cout <<"*u*"<<s;
//	cout <<s<<"*  *  *"<<(0==s.find(" "))<<endl;
// il faut 1 --from car on rajoute " " et ensuite on ++ une fois en trop;
//cette méthode de rajout de " " permet de tester correctement string vide;
//ainsi que de coder + facilement en incluant le ++ dans le 
// 'v' ligne obligfatoire si do {} while; 'v'
	//s=' '+s; cout <<"*"<<s<<"*"<<endl;--from; cout <<from<<"   " <<(from<str.size())<<endl;
	//objective: trouver le from du prochain mot, pour cela on rajoute " " au mot et on detecte le moment ou s.find
	// ne vaut plus 0, ce qui marquera le debut du prochain mot;
	// -1 -1 = -2 (-1 standard, et on veut au moins 2 éléments);
	while ((0==s.find(" "))and(from<str.size()-1)) { 
		//cout<<((0==s.find(" "))and(from<str.size()))<<"  true/f ";
		from++; 
	s=s.substr(1,str.size()-from+1);
//	cout<<endl<<"s.find==0?  "<<(s.find(" ")==0)<<"   "<<(from<str.size())<<endl;
	//cout <<"*"<<s<<"*"<<endl;
	//cout<<((0==s.find(" "))and(from<str.size()))<<"  true/f "; cout<<"*"<<s<<"*";
	}  
	//si on a parcouru le reste de la chaine et que ce dernier bout de chaine vaut " " ; false;
	
	
	
	// tant que le " " le plus à gauche vaut 0 et que on a pas fini la chaine, alors
	// _from ++             }
	//_ retirer 1er élément } on est censés finir avec un string de taille 1;
	// si à la fin, on a parcouru le tableau et que le dernier élément vaut " ", alors false.
	// sinon c'est que soit S.find !=0 'OK' ou qu'on a pas fini le string et que le while s'est arreté pour un non " ".
	
	
	//cout<<"rrrr"<<(s.find(" ")==0);
	if ((from>=str.size()-1)and(s.find(" ")==0)) return false; 
	else  
	{//cout <<"tamere"<<s; 
		 len=0; //cout<<len;//cout << str.size()<<from;
		 //len<=str... car c'est une longueur
		while ((len<=str.size()-from-1)and(s.find(" ")!=0)) {
		++len; s=s.substr(1,str.size()-from+1-len);}} 
	
//	 cout<<"**   " <<from<<endl; return true;
	return true;	
} 

void affiche(string const& s, int const& from, int const& len) {
	cout<<"*";
	for(size_t i(0); i<=len;i++) {
	cout<<s[from+i];  }
	cout<<endl;
}

void application(string const& s, int& from, int& len) {
	if (nextToken(s,from,len)) {  affiche(s,from,len); from+=len; application(s,from,len); }
	else { return; }
}

int main() {
	// /!\ î compte comme 2 charactères
	string s=" heuu bonjour, voici ma chaîne !"; int from(1), len(4); //cout<<s.size();
	//cout << s[from]<<"*   *";
	//cout<<s.substr(from,s.size()-from+1);
	// s=s.substr(0,s.size()); cout <<s;
	//cout<<"**"<<nextToken(s,from,len); //cout << s[from]<<"   "<<from<<"   " <<len;
	application(s,from,len);
//	from=from+len; nextToken(s,from,len);
	// cout << from<<"  "<< len<<"  "<<s;
	cout << s[from]<<"   "<<from<<"   " <<len;
	affiche(s,from,len);
}
