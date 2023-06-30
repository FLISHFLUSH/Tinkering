#include <iostream>
#include <cmath>
using namespace std;

int main () {

   double un(1); double un1;
   double vn(0);
   //choix à faire: soit 1 calcul en trop, soit un cout en plus pour introduire U0
   for (int i(0); i<=10;++i){
	   un1=un/(i+1);
	   vn+=un;
	  cout << "U" <<i<<"= "<<un<< endl; 
	  cout << "V" <<i<<"= "<<vn<<endl;
	   un=un1;
  }

}
