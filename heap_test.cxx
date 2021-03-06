#include "heap.hxx"

#include <vector>
#include <iostream>
#include <functional>

namespace algods {
    namespace heap {
        namespace unittest {

            using namespace std;

            int test_binary_heap0() {
                vector<int> v{3, 6, 1, -1, 8, 2, 10, 2, 9};
                binary_heap<int> heap(v.begin(), v.end());
                int i;
                while(heap.remove(i)) {
                    cout << i << ' ';
                }
                cout << endl;
                return 0;
            }

            int test_binary_heap1() {
                vector<int> v{3, 6, 1, -1, 8, 2, 10, 2, 9};
                binary_heap<int, greater<int>> heap(v.begin(), v.end());
                int i;
                while(heap.remove(i)) {
                    cout << i << ' ';
                }
                cout << endl;
                return 0;
            }
        }
    }
}


int main(int argc, char *argv[]) {
    using namespace algods::heap::unittest;
    test_binary_heap0();
    test_binary_heap1();
    return 0;
}
