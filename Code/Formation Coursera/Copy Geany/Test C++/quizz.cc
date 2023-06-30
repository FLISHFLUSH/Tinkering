#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include <math.h>
 using namespace std;
class Vehicle {
public:
    virtual void honk() = 0;
};

class Car : public Vehicle {
public:
    virtual void honk() { cout << "Beeeeeeeeep!"; }
};

class Boat : public Vehicle {
protected:
    void honk() { cout << "Toot!"; }
};

class Hovercraft : public Car, public Boat {
public:
   
  using Boat::honk;
    };
    
    int main(){
		Hovercraft h;
		Car* c(new Hovercraft());
		c->honk(); delete c;
		return 0;}
