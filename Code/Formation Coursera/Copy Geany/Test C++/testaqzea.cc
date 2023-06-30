#include <iostream>
#include <vector>
using namespace std;

vector<int> f(int n){
  vector<int> v;
  int j(0);

  while (n != 0) {
    v.push_back(n % 1000);
    n = n / 1000;
    return v;
  }
}
  int main ()  {
  
  vector<int> tab(f(40000));
  cout << tab.size();
  for(auto a:tab)
  cout << a<< endl;
  }
