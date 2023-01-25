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
  
   

    // Important - every constructor must initialize
    // every private data member (attribute)
    this->head  = nullptr;
    this->tail  = nullptr;
    // this->nodes = 0;
    this->occupied = src.occupied;
    this->slots = src.slots;
    // Start the Copy Operations
    Node* srcIt = src.head;
   
    while (srcIt != nullptr) {
      //  this->appendNode(srcIt->data);
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
 Node *this_iterator = nullptr;  // Loop control pointer
    Node *to_delete     = nullptr;  // Node to delete

    // start at the beginning of the this
    this_iterator = this->head;

    // iterate through the this and delete each node
    while (this_iterator != nullptr) {
        to_delete = this_iterator;

        // move to next node
        this_iterator = this_iterator->next;

        // delete the current node
        delete to_delete;

        to_delete = nullptr;  // dangling pointers are bad

        // Such output would not be included in
        // a non-academic exercise
      //  std::cerr << "Deleting Node" << "\n";
    }

    // Such output would not be included in
    // a non-academic exercise
    

    // Are these three lines necessary?
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
        // If it and itemStack contain the same type of Item
        if(it->data == itemStack) {
                
                return it;
        }

        it = it->next;
    }

    // No match was found
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
    // Create a new Node
    // Note what actually occurs on the next line
    Node *new_node = nullptr;

    // Store the "to_add" data within the node
    new_node = new Node(itemStack);

    // Handle the case where the first node is added
    if (this->occupied == 0) {
        // this->head = this->tail = new_node;
        // Note the above line is it any different
        // from the next two lines?
        this->head = new_node;
        this->tail = new_node;
    }
    else{
        // Add the new node to the this
        // What happens on the following two lines
        (this->tail)->next = new_node;
        this->tail = new_node;
    }

    // Increase the number of nodes
    this->occupied++;

    // Do not allow access to the node except
    // through the linked list
    // Is this line necessary?
    new_node = nullptr;
}
