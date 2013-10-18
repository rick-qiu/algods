
#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

namespace algods {
    namespace linkedlist {

        template<typename T>
        struct slnode {
            slnode<T>(const T& d, slnode<T>* n): data(d), next(n) {
            }
            T data;
            slnode* next;
        };

        template<typename T>
        struct dlnode {
            dlnode<T>(const T& d, dlnode<T>* p, dlnode<T>* n) : data(d), prev(p), next(n)
            T data;
            dlnode* prev;
            dlnode* next;
        };

        template<typename input_iterator>
        void build_linkedlist(input_iterator begin, input_iterator end,
                              slnode<typename iterator_traits<input_iterator>::value_type>*& head) {
            typedef typename iterator_traits<input_iterator>::value_type value_type;
            typedef slnode<value_type> node_t;
            node_t **current = &head;
            while(begin != end) {
                *current = new node_t(*begin, nullptr);
                current = &((*current)->next);
                ++begin;
            }
        }

        template<typename input_iterator>
        void build_linkedlist(input_iterator begin, input_iterator end,
                              dlnode<typename iterator_traits<input_iterator>::value_type>*& head) {
            typedef typename iterator_traits<input_iterator>::value_type value_type;
            typedef dlnode<value_type> node_t;
            node_t *prev = nullptr;
            node **current = &head;
            while(begin != end) {
                *current = new node_t(*begin, prev, nullptr);
                prev = *current;
                current = &((*current)->next);
                ++begin;
            }
            (*current)->next = head;
            head->prev = (*current);
        }

        template<typename T>
        void destory_linkedlist(slnode<T>*& head) {
            while(head != nullptr) {
                auto p = head;
                head = head->next;
                delete p;
            }
        }

        template<typename T>
        void print_linkedlist(const slnode<T>* head) {
            while(head != nullptr && head->next != nullptr) {
                cout << head->data << "->";
                head = head->next;
            }
            cout << head->data << endl;
        }
    }
}

using namespace algods::linkedlist;

int main(int argc, char* argv[]) {
    vector<int> v{1,2,3,4,5,6,7};
    slnode<int>* head = nullptr;
    build_linkedlist(v.begin(), v.end(), head);
    print_linkedlist(head);
    destory_linkedlist(head);
    return 0;
}
