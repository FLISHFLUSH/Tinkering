#include <iostream>
#include <iomanip> 
using namespace std;

bool non_et(bool, bool);
int main () {
	
	return 0;
	
}

bool non_et(bool A, bool B)
{
  return not(A and B);
}

bool non(bool A) {
	return non_et(A,A);
}

bool et(bool A, bool B) {
	
	return non(non_et(A,B));
	
}
bool ou(bool A, bool N) {
	return non_et(non(A),non(B));
}
