// using ofstream constructors
using namespace std;
#include <iostream>
#include <fstream>  

int main() {
ofstream outfile ("test.txt");

outfile << "my text here!" << std::endl;

outfile.close();

}
