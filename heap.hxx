#ifndef ALGODS_HEAP_HXX
#define ALGODS_HEAP_HXX

#include <cassert>

#include <vector>
#include <functional>
#include <algorithm>
#include <sstream>
#include <string>

namespace algods {
    namespace heap {

        using namespace std;

        /********************************************************************************************
         ** a binary heap maintains both Compare(parent, left_child) and Compare(parent, right_child) are
         ** true for distinct elements
         *******************************************************************************************/
        template<typename T, typename Compare = std::less<T>, typename Allocator = std::allocator<T>>
        class binary_heap {

        public:
            template<typename input_iterator>
            binary_heap(input_iterator begin, input_iterator end) {
                while(begin != end) {
                    insert(*begin);
                    ++begin;
                }
            }

            /***************************************************************************************
             ** add an element into existing heap
             ** algorithm paradigm: incremental approach -- build a solution on existing smaller
             ** solution, like insertion sorting, see bottopm_adjust
             ***************************************************************************************/
            bool insert(const T& e) {
                items.push_back(e);
                bottom_adjust();
                return true;
            }

            /**************************************************************************************
             ** remove element at top
             ** algorithm paradigm: decrease-and-conquer -- gradually decrease the scale of the
             ** problem, see top_adjust
             *************************************************************************************/
            bool remove(T& e) {
                if(items.empty()) {
                    return false;
                }
                e = *items.begin();
                *items.begin() = *items.rbegin();
                items.pop_back();
                top_adjust();
                return true;
            }

            bool top(T& e) {
                if(items.empty()) {
                    return false;
                }
                e = *items.begin();
                return true;
            }

            bool change_top(const T& e) {
                if(items.empty()) {
                    return false;
                }
                *items.begin() = e;
                top_adjust();
                return true;
            }

        private:
            typedef vector<T, Allocator> container_t;
            typedef int index_t;
            index_t parent_index(index_t idx) {
                return ((idx + 1) >> 1) - 1;
            }
            index_t left_child_index(index_t idx) {
                return (idx + 1) << 1 - 1;
            }
            index_t right_child_index(index_t idx) {
                return (idx + 1) << 1;
            }
            // ONLY the first element might violate the heap property
            void top_adjust() {
                index_t parent = 0;
                index_t left = left_child_index(parent);
                index_t right = right_child_index(parent);
                assert(left < right);
                while(right < items.size()) {
                    index_t i = left;
                    if(!comparator(items[i], items[right])) {
                        i = right;
                    }
                    if(!comparator(items[parent], items[i])) {
                        swap(items[i], items[parent]);
                        parent = i;
                        left = left_child_index(parent);
                        right = right_child_index(parent);
                        assert(left < right);
                    } else {
                        break;
                    }
                }
                if(left < items.size() && !comparator(items[parent], items[left])) {
                    swap(items[left], items[parent]);
                }
            }
            // ONLY the last element might violate the heap property
            void bottom_adjust() {
                index_t idx = items.size() - 1;
                index_t parent = parent_index(idx);
                while(parent >= 0 && !comparator(items[parent], items[idx])) {
                    swap(items[idx], items[parent]);
                    idx = parent;
                    parent = parent_index(idx);
                }
            }
            container_t items;
            Compare comparator;
        };

        //placeholders
        class binomial_heap {
        };

        class fibonacci_heap {
        };
    }
}

#endif
