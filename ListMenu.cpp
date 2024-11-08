#include <iostream>
#include <string>
#include <cassert>
#include "List.h"
#include "ListNode.h"

using namespace std;
using namespace cs32;

enum class CHOICE {MAKEEMPTY, ISEMPTY, ADDTOFRONT, ADDTOREAR, DELETE, FIND, QUIT, PRINT, OPERATOR };

CHOICE menu();

int main() {
    string value;
    List list;
    List list2;

    CHOICE choice;
    do {
        choice = menu();
        switch( choice ) {
        case CHOICE::MAKEEMPTY:
            list.makeEmpty();
            break;
        case CHOICE::ISEMPTY:
            if (list.isEmpty()) {
                cout << "list is empty" << endl;
            }
            else {
                cout << "list is not empty" << endl;
            }
            break;
        case CHOICE::DELETE:
            cout << "Please provide a string to remove: ";
            cin  >> value; 
            list.deleteItem( value );
            break;
        case CHOICE::ADDTOFRONT:
            cout << "Please provide a string to insert in front: ";
            cin  >> value; 
            list.addToFront( value );
            break;
        case CHOICE::ADDTOREAR:
            cout << "Please provide a string to insert in rear: ";
            cin  >> value;
            list.addToRear( value );
            break;
        case CHOICE::FIND:
            cout << "Please provide a string to find: ";
            cin  >> value;
            cout.setf( ios::boolalpha );
            cout << list.findItem( value ) << endl;
            cout.unsetf( ios::boolalpha );
            break;
        case CHOICE::PRINT:
            cout << list.printItems() << endl;;
            break;
        case CHOICE::OPERATOR:
            list2 = list;
            cout << "second list now:" << endl;
            cout << list2.printItems() << endl;
            break;
        case CHOICE::QUIT:
            break;
        }	

    } while (choice != CHOICE::QUIT);

    return( 0 );
}

CHOICE menu() {
    string s;
    cout << "(M)akeEmpty I(s)Empty (D)elete (A)ddToFront (R)AddtoRear  (F)ind (P)rint (=) (Q)uit: " << endl;
    cin  >> s;
    char choice = s.at( 0 );
    switch( choice ) {
    case 'M':
    case 'm':
        return CHOICE::MAKEEMPTY;
    case 'D':
    case 'd':
        return CHOICE::DELETE;
    case 'S':
    case 's':
        return CHOICE::ISEMPTY;
    case 'A':
    case 'a':
        return CHOICE::ADDTOFRONT;
    case 'R':
    case 'r':
        return CHOICE::ADDTOREAR;
    case 'F':
    case 'f':
        return CHOICE::FIND;
    case 'Q':
    case 'q':
        return CHOICE::QUIT;
    case 'P':
    case 'p':
        return CHOICE::PRINT;
    case '=':
        return CHOICE::OPERATOR;
    default:
        return CHOICE::QUIT;
    }
}