#include "List.h"

using namespace std;

namespace cs32 {

List::List() {
	head = nullptr;
}

List::List( const List& rhs ) {
    if (rhs.head == nullptr) head = nullptr;
    else {
        head = new ListNode( rhs.head->getElement() );
        ListNode *q = head;
        ListNode *p = rhs.head->getNext();
        while (p != nullptr) {
            q->setNext( new ListNode( p->getElement() ) );
            q->getNext()->setNext( nullptr );
            p = p->getNext( );
            q = q->getNext( );
        }
    }
}

List::~List() {
	makeEmpty();
}

bool List::isEmpty() const {
	return( head == nullptr );
}

void List::makeEmpty() {
	while (!isEmpty()) {
        deleteItem( head->getElement( ) );
	}
}

void List::addToFront( const std::string & data )
{
    ListNode * newnode = new ListNode( data );
    newnode->setNext( head );
    head = newnode;
}

void List::addToRear( const std::string & data )
{
    if (head == nullptr)
    {
        addToFront( data );
    }
    else
    {
        ListNode * node = head;
        while( node->getNext() != nullptr )
        {
            node = node->getNext();
        }
        ListNode * newnode = new ListNode( data );
        newnode->setNext( nullptr );
        node->setNext( newnode );
    }
}

void List::deleteItem( const std::string & data )
{
    ListNode * node = head;
    ListNode * priornode = nullptr;

        while( node != nullptr )
        {
            if (node->getElement() == data)
            {
                if (priornode != nullptr)
                    priornode->setNext( node->getNext( ) );
                else
                    head = node->getNext();
                delete( node );
                break;
            }
            priornode = node;
            node = node->getNext();
        }
}

bool List::findItem( const std::string & data )
{
    bool result = false;
    ListNode * node = head;
    while( node != nullptr )
    {
        if (node->getElement() == data)
        {
            result = true;
            break;
        }
        node = node->getNext();
    }
    return( result );
}

std::string List::printItems( )
{
    string s = "";
    if (isEmpty())
    {
        s += "---> empty list";
    }
    else
    {
        s += "head:";
        ListNode * node = head;
        while( node != nullptr )
        {
            s += " -> ";
            s += node->getElement();
            node = node->getNext();
        }
        s += " -> nullptr ";
    }
    return( s );
}


// Deep copy of linked list
const List& List::operator =( const List& rhs ) {
	if (this != &rhs) {
		makeEmpty();

        ListNode * right = rhs.head;

		while( right != nullptr )
        {
            addToRear( right->getElement() );
            right = right->getNext();
		}
	}

	return( *this );
}


size_t List::size() const {
    size_t count = 0;
    ListNode* current = head;
    while (current != nullptr) {
        count++;
        current = current->getNext();
    }
    return count;
}


bool List::get(int i, std::string& data) const {
    if (i < 0) return false;
    
    ListNode* current = head;
    int currentIndex = 0;
    
    while (current != nullptr && currentIndex < i) {
        current = current->getNext();
        currentIndex++;
    }
    
    if (current == nullptr) return false;
    
    data = current->getElement();
    return true;
}


std::string List::max() const {
    if (isEmpty()) return "";
    
    std::string maxValue = head->getElement();
    ListNode* current = head->getNext();
    
    while (current != nullptr) {
        if (current->getElement() > maxValue) {
            maxValue = current->getElement();
        }
        current = current->getNext();
    }
    
    return maxValue;
}

bool List::allMoreThan(const std::string& data) const {
    ListNode* current = head;
    
    while (current != nullptr) {
        if (current->getElement() <= data) {
            return false;
        }
        current = current->getNext();
    }
    
    return true;
}

int List::strip(const std::string& data) {
    int count = 0;
    ListNode* current = head;
    ListNode* prev = nullptr;
    
    while (current != nullptr) {
        if (current->getElement() == data) {
            count++;
            if (prev == nullptr) {
                head = current->getNext();
                delete current;
                current = head;
            } else {
                prev->setNext(current->getNext());
                delete current;
                current = prev->getNext();
            }
        } else {
            prev = current;
            current = current->getNext();
        }
    }
    
    return count;
}

int List::count(const std::string& data) const {
    int count = 0;
    ListNode* current = head;
    
    while (current != nullptr) {
        if (current->getElement() == data) {
            count++;
        }
        current = current->getNext();
    }
    
    return count;
}
}


