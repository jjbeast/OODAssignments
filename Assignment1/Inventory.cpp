#include <utility>
#include "Inventory.h"

// Allow the compiler to define the remaining
// comparison operators boom
using namespace std::rel_ops;





//------------------------------------------------------------------------------
Inventory::Node::Node()
    :data(Item(0, "Air"), 0)
{
    this->next = nullptr;
}

//------------------------------------------------------------------------------
Inventory::Node::Node(ItemStack s)
    :data(s)
{
    this->next = nullptr;
}

//------------------------------------------------------------------------------
Inventory::Inventory()
{
    this->head     = nullptr;
    this->tail     = nullptr;
    this->slots    = 10;
    this->occupied = 0;

    //std::cerr << Node().data << "\n";
}

//------------------------------------------------------------------------------
Inventory::Inventory(int n)
{
    this->head     = nullptr;
    this->tail     = nullptr;
    this->slots    = n;
    this->occupied = 0;
}

//------------------------------------------------------------------------------
Inventory::Inventory(const Inventory &src)
{
    // @todo implement this function
  
   

    
    this->head  = nullptr;
    this->tail  = nullptr;
    
    this->occupied = src.occupied;
    this->slots = src.slots;
    
    Node* srcIt = src.head;
   
    while (srcIt != nullptr) {
      
      Node *newNode = new Node(srcIt->data);
          if (head == nullptr) {
                head = newNode;
                tail = newNode;
            } else {
                tail->next = newNode;
                tail = newNode;
            }
            srcIt = srcIt->next;
    }
}

//------------------------------------------------------------------------------
Inventory::~Inventory()
{
    // @todo implement this function
 Node *this_iterator = nullptr;  
    Node *to_delete     = nullptr;  

    
    this_iterator = this->head;

    
    while (this_iterator != nullptr) {
        to_delete = this_iterator;

      
        this_iterator = this_iterator->next;

       
        delete to_delete;

        to_delete = nullptr;  

        
    }

   
    

    
    head  = nullptr;
    tail  = nullptr;
    
}

//------------------------------------------------------------------------------
bool Inventory::isFull() const
{
    // @todo implement this function
    //
    // If this is more than one line
    // in the form "return (boolean expression);"
    // you are overthinking the problem

    return this->occupied == this->slots; // This line is a placeholder. Remove it.

}

//------------------------------------------------------------------------------
void Inventory::display(std::ostream &outs) const
{
    
    outs << " -Used " << occupied << " of " << slots << " slots" << "\n";

    Node* it = head;
    while(it != nullptr){
        outs << "  " << it->data << "\n";

        it = it->next;
    }
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

    swap(lhs.head, rhs.head);
    swap(lhs.tail, rhs.tail);
    swap(lhs.slots, rhs.slots);
    swap(lhs.occupied, rhs.occupied);
}

//------------------------------------------------------------------------------
Inventory::Node* Inventory::findMatchingItemStackNode(const ItemStack& itemStack)
{
    // @todo implement this function
     Node* it = head;

    while(it != nullptr){
        
        if(it->data == itemStack) {
                
                return it;
        }

        it = it->next;
    }

   
    return nullptr;
    
}

//------------------------------------------------------------------------------
void Inventory::mergeStacks(ItemStack& lhs, const ItemStack& rhs)
{
    lhs.addItems(rhs.size());
    // Update lhs... remember rhs is read only
}

//------------------------------------------------------------------------------
void Inventory::addItemStackNoCheck(ItemStack itemStack)
{
    // @todo implement this function
   
    Node *new_node = nullptr;

    
    new_node = new Node(itemStack);

    
    if (this->occupied == 0) {
        
        this->head = new_node;
        this->tail = new_node;
    }
    else{
        
        (this->tail)->next = new_node;
        this->tail = new_node;
    }

    
    this->occupied++;

    
  
    new_node = nullptr;
}
