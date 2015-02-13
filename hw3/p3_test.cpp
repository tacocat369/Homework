#include "llistint.h"
#include <iostream>

using namespace std;

int main() {

  LListInt * list = new LListInt();

  cout << endl << "Hello!, We are going to test if the linked list is working fine." << endl;
  cout << "There are lot of cases." << endl << endl << "*******Inserting cases******" << endl;
  cout << "1. Inserting at location at 0" << endl;
  cout << "  1.1 Inserting at location 0, when there is nothing or size is 0" << endl;
  cout << "  1.2 Inserting at locatoin 0 ,when it is not empty" << endl;
  cout << "2. Inserting in the middle" << endl;
  cout << "3. Inserting in the last-1" << endl;
  cout << "4. Inserting in the last "<< endl << endl << endl;

  cout << "Lets check if it is empty in the first place" << endl;
  cout << "Is it empty?  :  " << list->empty() << " <----- If (1 = yes, 0 = no)" << endl << endl;
  cout << "It is empty. How about its size? : " << list->size() << " <--- it shoudl be 0" << endl << endl;

  cout << "Inserting value 1 at loc 0" << endl;
  list->insert(0,1);
 
  for (int i = 0; i < list->size(); i++) {
   
    cout << "value at location " << i << " is : " << list->get(i) << endl << endl;

  }

  cout << "Lets try inserting value (0,0) (2,2) (3,3) (4,4) "<< endl << endl;
  
  list->insert(0,0);
  list->insert(2,2);
  list->insert(3,3);
  list->insert(4,4);

  cout << "(loc,value)  ->  ";

  for (int i = 0; i < list->size(); i++) {
   
   cout << "(" << i << "," << list->get(i) << ") " ; 

  }
  
  cout << endl << "Perfect. how about its size? : " << list->size() << " <---- It should be 5." << endl;

  cout << endl << endl << "*********** lets try removing some stuff **************" << endl << endl;

  cout << "Lets remove at location 3 and see" << endl;
  list->remove(3);

  
  cout << "(loc,value)  ->  ";

  for (int i = 0; i < list->size(); i++) {
   
   cout << "(" << i << "," << list->get(i) << ") " ; 

  }
  
  cout << endl << "Yeay. how about size? : " << list->size() << endl << endl;
  cout << "Good Bye~~~~~~~~~~~~~~~~~~~" << endl << endl;
  
  // Clean up memory.
  delete list;


}