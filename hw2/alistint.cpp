#include "alistint.h"
#include <cstdlib>
#include <iostream>
using namespace std;

AListInt::AListInt()
{
  data = new int[10];
  size_ = 0;
  capacity_= 10;
}

AListInt::AListInt(int cap)
{
  data = new int[cap];
  size_ = 0;
  capacity_= cap;
  
}
  
AListInt::~AListInt()
{

}
  
  /**
   * Standard List interface
   */

  /**
   * Returns the current number of items in the list 
   */
int AListInt::size() const
{
  return size_;
}
  
  /**
   * Returns true if the list is empty, false otherwise
   */
bool AListInt::empty() const
{
  return (size_ == 0);
}

  /**
   * Inserts val so it appears at index, pos
   */
void AListInt::insert (int pos, const int& val)
{

}

  /**
   * Removes the value at index, pos
   */
void AListInt::remove (int pos)
{

}

  /**
   * Overwrites the old value at index, pos, with val
   */
void AListInt::set (int position, const int& val)
{

}

  /**
   * Returns the value at index, pos
   */
int& AListInt::get (int position)
{

}

  /**
   * Returns the value at index, pos
   */
int const & AListInt::get (int position) const
{

}
  
  /**
   * add a value in the end
   */
//void AListInt::push_back(const T& new_val)
//{

//}

