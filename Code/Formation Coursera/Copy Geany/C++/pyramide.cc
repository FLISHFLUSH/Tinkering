#include <iostream>
#include <cmath>
using namespace std;

int main () {
int n(9);
for (int i(1); i<10;i++){
	 for (int a(1);a<=9-i;++a)
     cout <<" ";
     for (int j(1); j<=i;++j)
     cout << j;

 
     cout << endl;
 }
 /*
 for (int i(1); i<10;i++){
 for (int j(1); j<=i;j++)
 cout <<j;
 cout << endl;
 */
 int j(1);
 while (j<=9) {
	 for (int a(1); a<=9-j;a++)
	 cout <<" ";
	 for (int i(1); i<=j; i++)
	 cout << i;
	 cout <<endl;
	 j++;
};

}
