

#include <iostream>
#include <cmath>
using namespace std;

int main () {
int m(0);
int p(3);
bool test1(true);
bool test2(!test1);

while (m <= p) {
  if (test1 or test2) {
    cout << test1 << " " << m << " ";
    test1 = not test1;
  } else {
    cout << test2 << " " << p << " ";

    test2=not test1;
    //trouvé par la reflexion (Il fallait qqchose qui agit sur test 2 et
    //les deux seules réponses étaient test2=not test1 et test 2=test1
    // si on rentre dans le else il faut false et false et test2=test1 ne permet pas d'en sortir
  }
  ++m;
}

if (test1 or (test2 and not test1)) {
  cout << test1 << " ";
}
}
