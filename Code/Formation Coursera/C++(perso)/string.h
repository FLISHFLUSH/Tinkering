
#include <iostream>
#include <string>
#include <vector>

using namespace std;

typedef unsigned int uint;
typedef vector<string> traduction;
typedef vector<traduction> dictionnaire;
// pour vecteur de tialle 2, utiliser boost:array ?

string tolower(string s) {
	for (uint i(0);i<s.length(); i++)
	s[i]=tolower(s[i]);
	return s;
	}

int compare_NC(string const& s, string S) {
	return tolower(s).compare(tolower(S));
	}
void Traduction0(string s, traduction);
void Traduction1(string s, dictionnaire d);

