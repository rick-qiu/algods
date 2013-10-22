#ifndef ALGODS_LINKEDLIST_HXX
#define ALGODS_LINKEDLIST_HXX

#include <iostream>
#include <iterator>
#include <sstream>

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
            typedef typename iterator_traits<input_iterator>::value_type value_t;
            typedef slnode<value_t> node_t;
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
            typedef typename iterator_traits<input_iterator>::value_type value_t;
            typedef dlnode<value_t> node_t;
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
        void destroy_linkedlist(slnode<T>*& head) {
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
        string linkedlist2string(const slnode<T>* head) {
            ostringstream oss;
            while(head != nullptr && head->next != nullptr) {
                oss << head->data << "->";
                head = head->next;
            }
            if(head != nullptr) {
                oss << head->data;
            }
            return oss.str();
        }

        template<typename T>
        string linkedlist2string(const dlnode<T>* head) {
            ostringstream oss;
            auto pivot = head;
            while(pivot != nullptr && pivot->next != head) {
                oss << pivot->data << "<->";
                pivot = pivot->next;
            }
            if(pivot != nullptr) {
                oss << pivot->data;
            }
            return oss.str();
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
        void append_node(slnode<T>*& head, const T& data) {
            slnode<T>** current = &head;
            while(*current != nullptr) {
                current = &((*current)->next);
            }
            *current = new slnode<T>(data, nullptr);
        }

        template<typename T>
        void remove_node(slnode<T>*& head, slnode<T>*& p) {
            if(head == nullptr || p == nullptr) {
                return;
            }
            if(head == p) {
                head = head->next;
                delete p;
                p = nullptr;
                return;
            }
            auto current = head;
            while(current != nullptr && current->next != p) {
                current = current->next;
            }
            if(current != nullptr) {
                current->next = p->next;
                delete p;
                p = nullptr;
            }
        }

        template<typename T>
        slnode<T>* find_node(slnode<T>* head, const T& value) {
            while(head != nullptr) {
                if(head->data == value) {
                    return head;
                }
                head = head->next;
            }
            return nullptr;
        }

        template<typename T>
        void difference(slnode<T>*& left, slnode<T>* right) {
            while(right != nullptr) {
                auto p = find_node(left, right->data);
                remove_node(left, p);
                right = right->next;
            }
        }
    }
}
#endif
