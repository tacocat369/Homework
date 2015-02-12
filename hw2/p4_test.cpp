#include "alistint.h"
#include <iostream>

using namespace std;

int main() {
  
  AListInt Alist;
 
  int s;
  cout << "Capacity:";
  cin >> s;

  if(s < 1d0){
  	cout << "Minimum capacity is 10. Capacity is set to 10.";     	
  }

  else {
  	Alist(s);
  	cout << "Capacity set to " << s << endl;
  }

  

  cout << "Checking if it is empty.\n";
  
  Alist.empty();
  Alist.insert(0,0);








	return 0;
}