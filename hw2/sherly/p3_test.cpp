#include "llistdbl.h"
#include <iostream>

using namespace std;

int main() {

  LListDbl * list = new LListDbl();

  cout << "Is it empty? (1 = yes, 0 = no)   " << list->empty() << endl << endl;
  
  cout << "Lets try inserting value '0' at location '0'" << endl;
  list->insert(0,0);
  cout << "Is it empty? (1 = yes, 0 = no)   " << list->empty() << endl << endl;
  
  

  cout << "Lets check the size" << endl;
  // 
  

  cout << "Current size is " << list->size() << endl << endl;



  cout << "The value at 0 is : " << list->get(0) << endl;

cout << "!!!!!!!!!!!!!!!!!!!!!!!!!" << endl << endl;
 cout << "!!!!!!!!!!!!!!!!!!!!!!!!!" << endl << endl;

  
  cout << "Lets insert in the beginning again and check if it pushes" << endl;
  

  cout << "value at 0 is : " << list->get(0) << endl << "value at 1 is : " << list->get(1) << endl << endl;

  cout << "Lets delete location 0 and check." << endl;
  list->remove(0);
  cout << "It should have value 1 in location 0 is it? value at loc 0 : " << list->get(0) << endl << endl;

  cout << " works til here" << endl;

  
  // Clean up memory.
  delete list;


}