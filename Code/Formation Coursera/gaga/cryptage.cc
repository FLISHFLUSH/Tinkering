#include <iostream>
#include <string>
#include <vector>
using namespace std;



char decale(char c, char debut, int decalage){
	while (decalage <=0) decalage+=26;
	return debut + (((c - debut) + decalage) %26);
}


char code(char c, int d){
	if ((c>='a')and(c<='z')) return decale(c,'a',d);
	else if ((c>='A')and(c<='z')) return decale(c,'A',d);
	else return c;
}

string code(string phrase, int d){
	 for(size_t i(0); i<phrase.size();i++){
		 string p; p+=code(phrase[i],d);
	phrase.replace(i,1,p);
}
	return phrase;
}
string decode(string Phrase, int d){
	//-d marche
return code(Phrase, 26-d);
}


int main () {
	return 0;
}
