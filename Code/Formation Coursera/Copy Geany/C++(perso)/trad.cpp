
#include <iostream>
#include <string>
#include <vector>

using namespace std;

/* class String: public string {
	public:
	String (string str): string(str) {}
	
	
	 String tolower(){
		 string s(*this);
		 for (unsigned int i(0); i<s.length(); i++)
		 s[i]=std::tolower(s[i]);
		return String(s);
		}
		
	/* int compare_NC(string s) {
		string s1(this->tolower());
		return s1.compare(*this);
		}
*/
	};

int main() {
	const char * s=R"(Désolée ! 'Pas trop attendu ?

47)"; cout << s<<endl;
//for (unsigned int i(0); i>s.length(); i++)
//cout << s[i];
cout<<string("eee");
	String t("MoMoo"); //cout<< t.compare_NC("Momoo")<<endl; 
	char x('a');x-=32;
; cout << x; x=tolower(x); cout<<x<<endl;
cout <<t.tolower() <<"  " <<t<<endl;
	cout<< t.compare("momo"); 
}
