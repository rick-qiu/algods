#ifndef ALGODS_TREE_HXX
#define ALGODS_TREE_HXX

#include <functional>
#include <memory>
#include <iterator>

namespace algods {
    namespace tree {

        using namespace std;

        template<typename T, typename Compare = std::less<T>, typename Allocator = std::allocator<T>>
        class binary_tree {

        public:

            binary_tree(): root(nullptr) {
            }

            template<typename InputIt>
            bool insert(InputIt begin, InputIt end) {
                for(; begin != end; ++begin) {
                    insert(*begin);
                }
            }

            template<typename InputIt>
            binary_tree(InputIt begin, InputIt end) {
                for(; begin != end; ++begin) {
                    insert(*begin);
                }
            }

            ~binary_tree() {
            }

            bool insert(const T& d) {
                node_t** pcurrent = &root;
                while(nullptr != *pcurrent) {
                    if(cmp(d, (*pcurrent)->data)) {
                        pcurrent = (*pcurrent)->left;
                    } else {
                        pcurrent = (*pcurrent)->right;
                    }
                }
                *pcurrent = new node_t(d);
                return true;
            }

            template<typename InputIt>
            bool insert(InputIt begin, InputIt end) {
                for(; begin != end; ++begin) {
                    insert(*begin);
                }
                return true;
            }

        private:
            struct node_t {
                node_t(const T& d): 
                    data(d), left(nullptr), right(nullptr) {
                }
                T data;
                node *left, *right;
            };
            node_t* root;
            Compare cmp;
            Allocator alloc;
        };

        template<typename T>
        struct node_t {
            node_t(const T& d): data(T), left(nullptr), right(nullptr) {
            }
            T data;
            node_t *left, *right;
        };

        template<typename T>
        void insert(node_t<T>*& root, const T& d) {
            node_t<T>** p = &root;
            while(nullptr != *p) {
                if(d < (*p)->data) {
                    p = &((*p)->left);
                } else {
                    p = &((*p)->right);
                }
            }
            *p = new node_t(d);
        }

        template<typename InputIt>
        void insert(node_t<T>*& root, InputIt first, InputIt last) {
            for(; first != last; ++first) {
                insert(root, *first);
            }
        }        
    }
}
#endif
