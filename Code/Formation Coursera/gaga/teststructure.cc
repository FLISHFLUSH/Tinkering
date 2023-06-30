#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct poopoo{
int eat; int dapoopoo;
};
double pifpafpoof(int i, char c='c');
double pifpafpoof(int i, int b=0, char c='c')  { return -1;}
double pifpafpoof(int i, char c) {
	cout <<c;
	return i;
} 

int main (){
cout <<pifpafpoof(2,0);
poopoo i({2,3});
cout << i.eat;
cout <<-1%26;
}
