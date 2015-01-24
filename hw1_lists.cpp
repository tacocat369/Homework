#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <string>

using namespace std;

struct Item {
  Item(int v, Item* n) { val = v; next = n; }
  int val;
  Item* next;
};

Item* concatenate(Item* head1, Item* head2);  // returns head pointer to new list
void removeEvens(Item*& head);
double findAverage(Item* head);


int main(int argc, char* argv[]){


  if(argc < 3){
      cerr << "Please provide a proper arguments. ex) ./hw1_lists input.txt output.txt" << endl;
      return 1;
    }

  ifstream in_file;
  in_file.open(argv[1]);

  if(in_file.fail()){

    cout << "reading input failed." << endl;
    return 0;
  }

  
  string f, s;
  getline (in_file, f); 
  getline (in_file, s); 
  
  istringstream iss(f);

  int temp = 0;
  char buf[0];

  int total = 0;
  while(iss >> buf){
  cout << buf << " ";
  }

  cout << endl;

  return 0;
}





















