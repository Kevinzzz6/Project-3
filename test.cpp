#include <iostream>
#include <string>
#include <cassert>
#include "List.h"
#include "ListNode.h"

int main() {
    using namespace std;
    using namespace cs32;

    // Test code

    // The get function enables a client to iterate over all elements of a List
    List l1;
    assert(l1.max() == "");
    assert(l1.size() == 0);
    assert(l1.allMoreThan("Z") == true); // Corrected condition to reflect that an empty list returns true
    assert(l1.count("Z") == 0);
    assert(l1.strip("Z") == 0);

    l1.addToFront("Hawkeye");
    l1.addToFront("Thor");
    l1.addToFront("Hulk");
    l1.addToFront("Black Widow");
    l1.addToFront("Iron Man");
    l1.addToFront("Captain America");
    for (int k = 0; k < l1.size(); k++) {
        string x;
        l1.get(k, x);
        cout << x << endl;
    }
    // Should print: 
    // Captain America
    // Iron Man
    // Black Widow
    // Hulk
    // Thor
    // Hawkeye

    assert(l1.max() == "Thor");
    assert(l1.size() == 6);
    assert(l1.allMoreThan("A"));
    assert(l1.allMoreThan("a") == false);
    assert(l1.count("Z") == 0);
    assert(l1.count("Hulk") == 1);
    assert(l1.strip("Z") == 0);
    assert(l1.findItem("Thor"));
    assert(l1.strip("Thor") == 1);
    assert(l1.size() == 5);
    assert(l1.findItem("Thor") == false);

    cout << "all tests passed!" << endl;
    return 0;
}