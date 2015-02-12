#include "llistdbl.h"
#include <iostream>
#include <cstdlib>
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
  
  if(loc < 0 || loc >size_){
  	cout << "Failed to Insert. Invalid location." << endl;
  }
  

  //creating pointer temp and dynamically allocating new Item
  Item * temp, *l;
  temp = new(struct Item);
  temp->val = val;
  temp->prev = NULL;
  temp->next = NULL;
  size_++;
  
  if(loc == 0) {  //inserting at the beginning
  
    // when empty
    if(head_ == NULL) {
    
      head_ = temp;
      tail_ = temp;
    
    }

    //when not empty
    else {
    
    temp->next = head_;
    head_->prev = temp;
    head_ = temp;

    }

  }  
  

  // inserting somewhere else than location 0
  else{
    
     
    l = getNodeAt(loc);

    // inserting in the middle
    if(l->next != NULL) {
        
    temp->next = l->next;
    temp->prev = l;
    l->next->prev = temp;
    l->next = temp;

    }
    
    //inserting at the last
    else {                  
                            
    l->next = temp;
    temp->prev = l;
    tail_ = temp;

    }

  }
  
}
/**
 * Complete the following function
 */
void LListDbl::remove(int loc)
{
   
    if( loc < 0 || loc > (size_-1) ) {
  	  cout << "Invalid location. " << endl;
     }

    

    else {
      cout << "!@#!@#$!@$@#$@!" << endl << endl;
	  size_--;
      Item *l;
	  l = getNodeAt(loc);

	    // Removing Item at location 0
	    if( loc == 0 ) {
	      
	        if( size_ == 1 ) {
	      
	          delete head_;

	         }

	        else {

	          head_ = head_->next;
	          delete head_->prev;
	          head_->prev = NULL;

	         }
	    

	     }

        // Deleting the last item
	    else if( loc == (size_-1) ) {
	    
	          tail_ = l->prev;
	          delete l;
	          l->next = NULL;
	         }
        
        // Deleting something in the middle  
	    else {
	          
	      l->prev->next = l->next;
	      l->next->prev = l->prev;

	      delete l;

	     }
    
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