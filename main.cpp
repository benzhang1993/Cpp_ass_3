#include <iostream>
#include <array>
#include "singleton_heap.hpp"

int main() {

    vector<int> ints = {10, 20, 30, 5, 15};
    singleton_heap<int, vector> heap = singleton_heap<int, vector>::instance();
    heap.set_heap(ints);

    cout << "Initial heap: ";
    cout << heap;

    cout << "After pop: ";
    heap.pop();
    cout << heap;

    cout << "After push back 99: ";
    heap.push_back(99);
    cout << heap;

    cout << "Note singleton_heap cannot be accidentally reassigned since it is a singleton.";

    return 0;
}