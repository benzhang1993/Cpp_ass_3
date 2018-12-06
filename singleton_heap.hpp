//
// Created by benzh on 2018-12-06.
//

#ifndef CPP_ASS_3_HEAP_HPP
#define CPP_ASS_3_HEAP_HPP

#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

template <typename T, template <typename, typename> class Container>
class singleton_heap {
    static singleton_heap heap_instance;
    vector<T> v;

    singleton_heap() = default;

public:

    void set_heap(Container<T, allocator<T>> array) {
        v = array;
        make_heap(v.begin(), v.end());
    }

    void pop() {
        pop_heap(v.begin(), v.end());
        v.pop_back();
    }

    void push_back(int value) {
        v.push_back(value);
        push_heap(v.begin(), v.end());
    }

    friend ostream& operator<<(ostream& os, const singleton_heap h)
    {
        for(int i = 0; i < h.v.size(); i++) {
            os << " " << h.v[i];
        }
        os << "\n";
        return os;
    }

    static singleton_heap& instance() {
        static singleton_heap heap_instance;
        return heap_instance;
    }

    int size() {
        return v.size();
    }

    bool is_empty() {
        if(v.size() == 0) {
            return true;
        }
        else {
            return false;
        }
    }

    void clear() {
        v.clear();
    }
};


#endif //CPP_ASS_3_HEAP_HPP
