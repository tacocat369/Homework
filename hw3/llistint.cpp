#include "llistint.h"
#include <iostream>
#include <cstdlib>
using namespace std;
LListInt::LListInt()
{
  head_ = NULL;
  tail_ = NULL;
  size_ = 0;
}


LListInt::LListInt(const LListInt& other)
{



}

LListInt& LListInt::operator=(const LListInt& other)
{


}


LListInt::~LListInt()
{
  clear();
}

bool LListInt::empty() const
{
  return size_ == 0;
}

int LListInt::size() const
{
  return size_;
}

/**
 * Complete the following function
 */
void LListInt::insert(int loc, const int& val)
{
  
  if(loc < 0 || loc >size_){
  	cout << "Failed to Insert. Invalid location." << endl;
  }
  

  //creating pointer temp and dynamically allocating new Item
  Item * temp, *l;
  temp = new Item;
  temp->val = val;
  temp->prev = NULL;
  temp->next = NULL;
  



    if(loc == 0) {  //inserting at the beginning
  
    	// when empty
   	 	if(size_ == 0) {
    
      	    head_ = temp;
      		tail_ = temp;
      		size_++;
    
    	 }	
          
    	 //when not empty
    	else {
    
    		temp->next = head_;
 	 		head_->prev = temp;
 	 		head_ = temp;
 			size_++;
 	     
 	     }

     }  
  

  	// inserting somewhere else than location 0
    else{
      

    // inserting in the middle
    if(loc != 0 && loc != size_) {
  
    l = getNodeAt(loc);                          ////////////////////
    l->next->prev = temp;
    temp->next = l->next;
    l->next = temp;
    temp->prev = l;
    size_++;
    }
    
    //inserting at the last
    else {                  
      // inserting at the back of the list
      if(loc == size_) {
        l = getNodeAt(loc-1);
        
        l->next =temp;
        temp->prev = l;
        tail_ = temp;
        size_++;
      }                       
    
      // inserting before last 
      else {   
       
       temp->prev = l->prev;
       l->next = temp;
       temp->next = l;
       l->prev = temp;
       size_++;

     }


    }

  }
  
}
/**
 * Complete the following function
 */
void LListInt::remove(int loc)
{
   
    if( loc < 0 || loc > (size_-1) ) {
  	  cout << "Invalid location. " << endl;
     }

    else {

	  Item *l;
	  l = getNodeAt(loc);

	    // Removing Item at location 0
	    if( loc == 0 ) {
            
            // only one in the list, or size is 1	      
	        if( head_->next == NULL ) {
 	                            
	          delete head_;
	          head_ = NULL;
	          tail_ = NULL;  
	          size_--;
                            
	         }
            
            // there is more than one item in the list
	        else {

	          head_ = head_->next;
	          head_->prev = NULL;
	          size_--;
	          delete l;
	          

	         }
	    

	     }

        // Deleting the last item
	    else if( loc == (size_-1) ) {
	    
	          tail_ = tail_->prev;
	          tail_->next = NULL;
	          size_--;
	          delete l;
	          
	         }
        
        // Deleting something in the middle  
	    else {
	          
	      l->prev->next = l->next;
	      l->next->prev = l->prev;
          size_--;
	      delete l;

	     }
    
     }

}

void LListInt::set(int loc, const int& val)
{
  Item *temp = getNodeAt(loc);
  temp->val = val;
}

int& LListInt::get(int loc)
{
  Item *temp = getNodeAt(loc);
  return temp->val;
}

int const & LListInt::get(int loc) const
{
  Item *temp = getNodeAt(loc);
  return temp->val;
}


void LListInt::push_back(const int& val)
{



}





void LListInt::clear()
{
  while(head_ != NULL){
    Item *temp = head_->next;
    delete head_;
    head_ = temp;
  }
  tail_ = NULL;
  size_ = 0;
}


LListInt::Item* LListInt::getNodeAt(int loc) const
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