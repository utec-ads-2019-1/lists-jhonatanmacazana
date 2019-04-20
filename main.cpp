#include <iostream>
#include "forward.h"
//#include "test/tester.h"

using namespace std;

int main(int argc, char *argv[]) {
    cout << "===========================================================" << endl;
    cout << "\tLists Practice" << endl;
    cout << "===========================================================" << endl << endl;

    //Tester::execute();

    ForwardList<int> *list = new ForwardList<int>();

    cout << list->front() << endl;
    list->push_front(16);
    cout << "Front(): " << list->front() << "    Back: " << list->back() << "    Size: " << list->size() << endl;
    list->push_front(10);
    cout << "Front(): " << list->front() << "    Back: " << list->back() << "    Size: " << list->size() << endl;
    list->pop_front();
    cout << "Front(): " << list->front() << "    Back: " << list->back() << "    Size: " << list->size() << endl;
    list->pop_front();
    cout << "Front(): " << list->front() << "    Back: " << list->back() << "    Size: " << list->size() << endl;
    list->pop_front();
    cout << "Front(): " << list->front() << "    Back: " << list->back() << "    Size: " << list->size() << endl;


    cout << endl;


    return EXIT_SUCCESS;
}
