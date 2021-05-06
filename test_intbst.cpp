#include <iostream>
#include "intbst.h"
using namespace std;



int main() {
    IntBST mytree;
    mytree.insert(5);
    mytree.insert(3);
    mytree.insert(4);
    mytree.insert(2);
    mytree.insert(6);
    mytree.insert(7);
    if (mytree.sum() == 27) {
        cout << "Sum() passed\n";
    }
    else {
        cout << "Sum() failed\n";
    }
    if (mytree.count() == 6) {
        cout << "count() passed\n";
    }
    else {
        cout << "count() failed\n";
    }






    return 0;
}
