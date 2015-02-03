#include "../llistdbl.h"
#include <iostream>

using namespace std;

int main() {
  LListDbl * list = new LListDbl();

  // Check if the list is initially empty.
  cout << "Is the list empty?\n";
  
  if (list->empty()) {
    cout << "Yes: List is empty in the beginning." << endl;
  } else {
    cout << "No: List is not empty in the beginning." << endl;
  }

  // Insert an item at the head.
  list->insert(0, 7);

  // Check if the list is still empty.
  if (!list->empty()) {
    cout << "Yes: Number 7 was inserted." << endl;
    Item * print_helper = new Item;
    

  } else {
    cout << "No: Failed to insert." << endl;
  }

  if (list->size() == 1) {
    cout << "SUCCESS: List has size 1 after one insertion." << endl;
  } else {
    cout << "FAIL: List has size " << list->size() << " after one insertion.";
    cout << endl;
  }

  // Check if the value is correct.
  if (list->get(0) == 3.3) {
    cout << "SUCCESS: 3.3 is at the 0th index of the list." << endl;
  } else {
    cout << "FAIL: 3.3 is not at the 0th index of the list, " << list->get(0);
    cout << " is instead." << endl;
  }

  // Clean up memory.
  delete list;
}