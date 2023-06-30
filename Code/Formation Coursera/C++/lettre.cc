#include <iostream>
#include <string>
using namespace std;

void generelettre(bool homme, string prenom, string sujet, int jour, int mois, string politesse, string auteur){
	string s("chäre");
	if (homme) s=("cher");
	cout << "Bonjour "<< s<<" " <<prenom<< endl << "Je vous Çcris Ö propos de "<<sujet << endl<<"Il faudrait que nous nous voyons le "<<jour<<"/"<<mois<<" pour en discuter."<< endl
	<< "Donnez-moi vite de vos nouvelles !"<< endl << politesse <<", "<< auteur;
}
 int main () {
	 generelettre(true, "Mamadou","votre demande de rendez-vous", 16, 12, "Sincärement", "Mirelle");
 }
