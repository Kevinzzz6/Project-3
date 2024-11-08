#ifndef LIST_H
#define LIST_H
#include <iostream>
#include <string>
#include "ListNode.h"

namespace cs32 {

class List {
public:
	List();
	List( const List& rhs );
	~List();

	bool isEmpty() const;
	void makeEmpty();
    void addToFront( const std::string & data );
    void addToRear( const std::string & data );
    void deleteItem( const std::string & data );
    bool findItem( const std::string & data );
    std::string printItems( );
	
	size_t size() const;
    bool get(int i, std::string& data) const;
    std::string max() const;
    bool allMoreThan(const std::string& data) const;
    int strip(const std::string& data);
    int count(const std::string& data) const;
	
	const List& operator =( const List& rhs );
private:
	ListNode * head;
	
};

}
#endif
