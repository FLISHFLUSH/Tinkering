#include <iostream>
#include <iomanip> 
using namespace std;

void echange(int&, int&);

int main()
{
    int i(10);
    int j(55);
    cout << "Avant: i=" << i << " et j=" << j << endl;
    echange(i,j);
    cout << "Après: i=" << i << " et j=" << j << endl;
    return 0;
}

void echange (int& a, int& b){
	int temp=a;
	a=b; b=temp;
}
