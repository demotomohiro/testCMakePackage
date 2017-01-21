#include "testComp.hpp"
#include "testComp2.hpp"
#include "testComp3dep2.hpp"

int main() {
    testComp t;
    t.print();
    testComp2 t2;
    t2.print();
    testComp3dep2 t3;
    t3.print();
}
