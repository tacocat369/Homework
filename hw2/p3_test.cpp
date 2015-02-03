#include "llistdbl.h"
#include <iostream>

using namespace std;

int main() {
  LListDbl * list = new LListDbl();

  // Check if the list is initially empty.
  cout << endl <<"1. Let's check if it is empty in the first place.\n";
  if (list->empty()) {
    cout << "SUCCESS: List is empty initially." << endl << endl;
  } else {
    cout << "FAIL: List is not empty initially when it should be." << endl << endl;
  }
  
  cout << endl <<"2. Let's insert '0' at 0th item and lets print and check size.\n";

   // Insert an item at the head.
  list->insert(0, 0);
  list->print(); 
  
   // Check if the list is still empty.
  if (!list->empty()) {
    cout << "SUCCESS: List is not empty after one insertion. ";
    cout << "Current size:" << list->size() << endl << endl;
  } else {
    cout << "FAIL: List is empty after one insertion." << endl;
  }
 
  cout << "3. Inserting i in 'i'th place until 4 and print" << endl;
  list->insert(1, 1);
  list->insert(2, 2);
  list->insert(3, 3);
  list->insert(4, 4);
  
  list->print();




  cout << endl << endl;
  
  // Check if the value is correct.
  if (list->get(0) == 0) {
    cout << "SUCCESS: 0 is at the 0th index of the list." << endl;
  } else {
    cout << "FAIL: 3.3 is not at the 0th index of the list, " << list->get(0);
    cout << " is instead." << endl;
  }

  list->print();
  cout << endl;




  // Clean up memory.
  delete list;
}