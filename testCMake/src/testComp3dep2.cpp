#include "testComp3dep2.hpp"
#include "testComp2.hpp"

#include <iostream>

using namespace std;

void testComp3dep2::print() {
    testComp2 t;
    cout << "testComp3 print ...\n";
    t.print();
    cout << "then, testComp3 print\n";
}
