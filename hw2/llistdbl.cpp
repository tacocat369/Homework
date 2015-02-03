#include "llistdbl.h"
#include <cstdlib>
#include <iostream>
using namespace std;

LListDbl::LListDbl()
{
  head_ = NULL;
  tail_ = NULL;
  size_ = 0;
}

LListDbl::~LListDbl()
{
  clear();
}

bool LListDbl::empty() const
{
  return size_ == 0;
}

int LListDbl::size() const
{
  return size_;
}

/**
 * Complete the following function
 */
void LListDbl::insert(int loc, const double& val)
{
  if(loc < 0 || loc > size_){
    cout << "Location out of range\n";
  }

  Item * n = new Item;
  n->next = NULL;
  n->val=val;
  
  if(empty()){
    head_ = n;
    tail_ = n;
    size_++;
  }

  else if(!empty()) {
    if(loc == 0){
      n->next = head_;
      head_ = n;
      size_++;
    }

    else {
      int counter = 0;
      Item * addPtr = new Item;
      Item * temp = new Item;
      addPtr = head_;
      while(counter!=loc) {
        temp = addPtr;
        addPtr = addPtr->next;
        counter++; 
      }
      n->next = addPtr;
      temp->next = n;
      size_++;    
    }
  }
}

/**
 * Complete the following function
 */
void LListDbl::remove(int loc)
{
  if(empty()){
    cout << "List is already empty\n"; 
  }
  
  Item * deletePtr = new Item;
  deletePtr = head_;

  if(loc == 0) {
    head_ = head_->next;
    delete deletePtr;
    size_--;
  }

  else {
    
    Item * temp = new Item;
    Item * curr = new Item;
    int deletePtr_helper = 0;
    temp = head_;
    curr = head_;

    while(deletePtr_helper != loc+1) {
      temp = curr;
      curr = curr->next;
      deletePtr_helper++;

    }
    curr=curr->next;
    deletePtr = temp->next;
    temp->next = curr;
    delete deletePtr;
    size_--;

  }

}

void LListDbl::set(int loc, const double& val)
{
  Item *temp = getNodeAt(loc);
  temp->val = val;
}

double& LListDbl::get(int loc)
{
  Item *temp = getNodeAt(loc);
  return temp->val;
}

double const & LListDbl::get(int loc) const
{
  Item *temp = getNodeAt(loc);
  return temp->val;
}

void LListDbl::clear()
{
  while(head_ != NULL){
    Item *temp = head_->next;
    delete head_;
    head_ = temp;
  }
  tail_ = NULL;
  size_ = 0;
}

void LListDbl::print() {

  if(empty()){
    cout << "list is empty\n";
  }

  else if(!empty()){
    Item *curr = new Item;
    curr = head_;
    
    if(curr->next==NULL){
      cout << curr->val;
    }
    
    else{
      while(curr->next!=NULL){
      cout << curr->val << " ";
      curr = curr->next;
      }
      cout << curr->val;
    }
    cout << endl;
  }
  


}


LListDbl::Item* LListDbl::getNodeAt(int loc) const
{
  Item *temp = head_;
  if(loc >= 0 && loc < size_){
    while(temp != NULL && loc > 0){
      temp = temp->next;
      loc--;
    }
    return temp;
  }
  else {
    //throw std::invalid_argument("bad location");
    return NULL;
  }
}
