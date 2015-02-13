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
Item* temp = new Item();
temp->val=val;
Item* tempptr;

if(head_ != NULL){//we dont have a empty list
if(loc == 0) //inserting at the beginning
{
temp->next = head_;
head_->prev = temp;
head_ = temp;
}
else{//not inserting at the beginning
tempptr = getNodeAt(loc);
temp = tempptr;
(tempptr->prev)->next = temp;
}
}
size_++;
}

/**
* Complete the following function
*/
void LListDbl::remove(int loc)
{
Item* tempptr;
if(head_ == NULL){
cout << "ERROR: EMPTY LIST" << endl;

}
else{
tempptr = getNodeAt(loc);
if(loc == 0){//there's only one elemenet in the list
delete head_;
head_ = NULL;
}
else{//more than 1 element in the list
if(tempptr->next == NULL)//Deleting the last element
{
tempptr = tempptr->prev;
delete tempptr->next;
tempptr->next = NULL;
}
else{//not deleting the last element
(tempptr->next)->prev = tempptr->prev;
(tempptr->prev)->next = tempptr->next;
delete tempptr;
}
}
}
size_--;
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
