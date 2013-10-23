#ifndef ALGODS_HEAP_HXX
#define ALGODS_HEAP_HXX

#include <vector>
#include <functional>
#include <algorithm>
#include <sstream>
#include <string>

namespace algods {
    namespace heap {

        using namespace std;

        template<typename T, typename Compare = std::less<T>>
        class min_heap {

        public:
            template<typename input_iterator>
            min_heap(input_iterator begin, input_iterator end) {
                while(begin != end) {
                    insert(*begin);
                    ++begin;
                }
            }

            bool insert(const T& e) {
                items.push_back(e);
                index_t idx = items.size() - 1;
                index_t parent = parent_index(idx);
                while(parent >= 0 && comparator(items[idx], items[parent])) {
                    swap(items[idx], items[parent]);
                    idx = parent;
                    parent = parent_index(idx);
                }
                return true;
            }

            bool remove(T& e) {
                if(items.empty()) {
                    return false;
                }
                e = *(items.begin());
                *(items.begin()) = *(items.rbegin());
                items.pop_back();
                index_t idx = 0;
                index_t left = left_child_index(idx);
                index_t right = right_child_index(idx);
                while(left < items.size() || right < items.size()) {
                    if(left < items.size() && right < items.size()) {
                        index_t i = left;
                        if(comparator(items[right], items[left])) {
                            i = right;
                        }
                        if(comparator(items[i], items[idx])) {
                            swap(items[i], items[idx]);
                            idx = i;
                            left = left_child_index(idx);
                            right = right_child_index(idx);
                        } else {
                            break;
                        }
                    } else {
                        // must be left < items.size()
                        if(comparator(items[left], items[idx])) {
                            swap(items[left], items[idx]);
                        }
                        break;
                    }
                }
                return true;
            }

        private:
            typedef vector<T> container_t;
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
            container_t items;
            Compare comparator;
        };
    }
}

#endif
