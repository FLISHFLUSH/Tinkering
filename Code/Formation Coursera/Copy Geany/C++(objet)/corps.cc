#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include <math.h>

using namespace std;

//=====================================================================	
class EnsembleFini {
	protected:
	int p;
	EnsembleFini(int p) 
	:p(p) {}
	};
	
class Groupe: public EnsembleFini {
	public:
	Groupe( double p)
	:EnsembleFini(p){}
	unsigned int add(unsigned int, unsigned int);
	};
	
class Anneau: public Groupe{
    public:
    Anneau(double p)
    :Groupe(p) {}
	unsigned int mult(unsigned int, unsigned int);
	};
	
class Corps: public Anneau {
	protected:
	unsigned int Euclide(unsigned int );
	
	public:
	Corps(double p)
	:Anneau(p) {}
	unsigned int inv(unsigned int);
	unsigned int div(unsigned int, unsigned int);
	};
	
//=====================================================================	
//Definitions	
//=====================================================================		
unsigned int Groupe::add(unsigned int a, unsigned int b) {
	return (a+b)%p;
	}	

unsigned int Anneau::mult(unsigned int a, unsigned int b){
	return (a*b)%p;
	}
unsigned int Corps::inv(unsigned int a){
	return Euclide(a);
	}	
	unsigned int Corps::div(unsigned int a, unsigned int b){
		return a*inv(b);
		}
	
unsigned int Corps::Euclide(unsigned int a){
	
int y(p),new_u,prev_u(1),u(0);//,v(0),v1(1);
int q,r,temp(0);
//cout << "x         y         u         v"<<endl;
//fait super rapidement.
//y!=1 et non y!=0 car u et v ne sont aps censés être calculés après qu'on ait trouvé y==0. On sait qu''un y=0 
//aura été y=1 avant donc autant donner cette valeur de u.
while (y!=1) {
q=a/y; r=a%y;

new_u=prev_u-q*u;
prev_u=u; u=new_u;
/*
temp=v1;
v1=v-v1*q; v=temp;  */


a=y; y=r;
cout << a<<"         "<<y<<"         "<<new_u<<endl;//<<"         "<<v1<<endl;
}
//cout <<u1;
return u+p;
//cout  <<endl<<"PGCD("<<a<<","<<b<<")="<<x;
}

//=====================================================================			
int main()
{
  Corps k(5); // c'est le corps Z/5Z
  cout << "0 + 1 = " << k.add(0, 1)  << endl;
  cout << "3 + 3 = " << k.add(3, 3)  << endl;
  cout << "3 * 2 = " << k.mult(3, 2) << endl;
  cout << "1/2 = "   << k.inv(2)     << endl;
  cout << "3 * 4 = " << k.mult(3, 4) << endl;
  return 0;
}
	

	
	
