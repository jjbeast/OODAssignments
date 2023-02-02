#include <utility>
#include <algorithm>

#include "Inventory.h"

// Allow the compiler to define the remaining
// comparison operators
using namespace std::rel_ops;

//------------------------------------------------------------------------------
Inventory::Inventory()
    :Inventory(10)
{
}

//------------------------------------------------------------------------------
Inventory::Inventory(int n)
{
    using namespace std;
    this->slots = n;
    
    // this->allItemStacks.reserve(n); // only works for std::vector
}

//------------------------------------------------------------------------------
Inventory::Inventory(const Inventory& src) :Inventory(src.slots)
{
    // @todo - implement this function
    
    
    

    const_iterator it = src.begin();
    while (it != src.end())
    {
        // do stuff
       
        
        this->addItemStackNoCheck(*it);
        it++;
}
}

//------------------------------------------------------------------------------
Inventory::~Inventory()
{
    // Done! Be able to explain why.
    // no pointers
}

//------------------------------------------------------------------------------
int Inventory::utilizedSlots() const
{
    return allItemStacks.size();
}


//------------------------------------------------------------------------------
int Inventory::emptySlots() const
{
    return slots - utilizedSlots();
}

//------------------------------------------------------------------------------
int Inventory::totalSlots() const
{
    return slots;
}

//------------------------------------------------------------------------------
bool Inventory::isFull() const
{
    // @todo - implement this function
    return emptySlots() == 0; // replace this line
}

//------------------------------------------------------------------------------
Inventory::iterator Inventory::begin()
{
    return allItemStacks.begin();
}

//------------------------------------------------------------------------------
Inventory::iterator Inventory::end()
{
    return allItemStacks.end();
}

//------------------------------------------------------------------------------
Inventory::const_iterator Inventory::begin() const
{
    return allItemStacks.begin();
}

//------------------------------------------------------------------------------
Inventory::const_iterator Inventory::end() const
{
    return allItemStacks.end();
}

//------------------------------------------------------------------------------
void Inventory::display(std::ostream &outs) const
{
    outs << " -Used " << utilizedSlots() << " of " << slots << " slots" << "\n";

    // @todo - implement the rest of function
    //
    // 2 spaces "  " before each ItemStack line
    const_iterator it = allItemStacks.begin();
    while (it != allItemStacks.end())
    {
        // do stuff
       // ItemStack *currentItemStack = it;
      //  outs << "(" << currentItemStack->quantity << ")  " << currentItemStack->item << "\n";
        outs << "  " << *it << "\n";
        it++;
    }
}


//------------------------------------------------------------------------------
Inventory::iterator Inventory::findMatchingItemStackIterator(const ItemStack& itemStack)
{
    // @todo - implement this function
    iterator it = allItemStacks.begin();
    while (it != allItemStacks.end()) {
    // do stuff
    if (*it == itemStack )  return it;
  
       
    
    it++;
}
    return allItemStacks.end();
}

//------------------------------------------------------------------------------
void Inventory::addItemStackNoCheck(ItemStack itemStack)
{
    // @todo - implement this function. This should be one push_back-y line...
    
    this->allItemStacks.push_back(itemStack);
}

//------------------------------------------------------------------------------
Inventory& Inventory::operator=(Inventory rhs)
{
    std::swap(*this, rhs);
    return *this;
}

//------------------------------------------------------------------------------
void swap(Inventory& lhs, Inventory& rhs)
{
    using std::swap;

    swap(lhs.allItemStacks, rhs.allItemStacks);
    swap(lhs.slots, rhs.slots);
}

//------------------------------------------------------------------------------
bool operator==(const Inventory& lhs, const Inventory& rhs)
{
    if (lhs.utilizedSlots() != rhs.utilizedSlots()) {
        return false;
    }

    if (lhs.emptySlots() != rhs.emptySlots()) {
        return false;
    }

    // The two Inventory objects have the same number of used & unused slots

    using const_iterator = Inventory::const_iterator;

    const_iterator lhsIt = lhs.begin();
    const_iterator rhsIt = rhs.begin();

    while (lhsIt != lhs.end() && rhsIt != rhs.end()) {
        if (*lhsIt != *rhsIt) {
            return false;
        }

        lhsIt++;
        rhsIt++;
    }

    // If the two Inventory objects are identical, both iterators
    // will have reached end positions.
    return lhsIt == lhs.end()
        && rhsIt == rhs.end();
}

//------------------------------------------------------------------------------
void Inventory::mergeStacks(ItemStack& lhs, const ItemStack& rhs)
{
    // @todo - implement this function. There is no trick here (beyond
    // reviewing Assignment 1).
    lhs.addItems(rhs.size());
}
