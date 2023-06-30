
#include <iostream>
#include <string>
namespace saucisson{
    int lulu= 3;
}

 int main (int argc, char *argv[]){
//////////
     {using namespace saucisson;
std::cout<<lulu<<std::endl;
}
int lulu=10;
std::cout<<lulu<<std::endl;

/////////
std::string s="saucisse";
std::cout<<s.capacity()<<std::endl;


//////////
return 0;
}
/*
namespace saucisson{
    int lulu=2;
}

using namespace saucisson; 
{
print(lulu);
}
print(lulu);
}
*/