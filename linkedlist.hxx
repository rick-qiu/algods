
#include <iostream>
#include <iterator>

namespace algods {
    namespace linkedlist {

        using namespace std;

        template<typename T>
        struct slnode {
            slnode<T>(const T& d, slnode<T>* n): data(d), next(n) {
            }
            T data;
            slnode* next;
        };

        template<typename T>
        struct dlnode {
            dlnode<T>(const T& d, dlnode<T>* p, dlnode<T>* n) : data(d), prev(p), next(n) {
            }
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
            node_t **current = &head;
            while(begin != end) {
                *current = new node_t(*begin, prev, nullptr);
                prev = *current;
                current = &((*current)->next);
                ++begin;
            }
            if(head != nullptr) {
                *current = head;
                head->prev = prev;
            }
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
        void destroy_linkedlist(dlnode<T>*& head) {
            auto pivot = head;
            while(pivot != nullptr && pivot->next != head) {
                auto p = pivot;
                pivot = pivot->next;
                delete p;
            }
            if(pivot != nullptr) {
                delete pivot;
            }
            head = nullptr;
        }

        template<typename T>
        void print_linkedlist(const slnode<T>* head) {
            while(head != nullptr && head->next != nullptr) {
                cout << head->data << "->";
                head = head->next;
            }
            if(head != nullptr) {
                cout << head->data;
            }
            cout << endl;
        }

        template<typename T>
        void print_linkedlist(const dlnode<T>* head) {
            auto pivot = head;
            while(pivot != nullptr && pivot->next != head) {
                cout << pivot->data << "<->";
                pivot = pivot->next;
            }
            if(pivot != nullptr) {
                cout << pivot->data;
            }
            cout << endl;
        }

        template<typename T>
        void reverse_linkedlist(slnode<T>*& head) {
            slnode<T>* prev = nullptr;
            while(head != nullptr && head->next != nullptr) {
                auto next = head->next;
                head->next = prev;
                prev = head;
                head = next;
            }
            if(head != nullptr) {
                head->next = prev;
            }
        }

        template<typename T>
        void append_linkedlist(slnode<T>*& head, const T& data) {
            slnode<T>** current = &head;
            while(*current != nullptr) {
                current = &((*current)->next);
            }
            *current = new slnode<T>(data, nullptr);
        }
    }
}
