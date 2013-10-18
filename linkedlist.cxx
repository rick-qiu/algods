
#include "linkedlist.hxx"

#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

namespace algods {
    namespace linkedlist {
        namespace unittest {
            int test0() {
                cout << "running test0, sanity testing" << endl;
                vector<int> v{1,2,3,4,5,6,7};
                cout << "single linked list..." << endl;
                slnode<int>* slhead = nullptr;
                build_linkedlist(v.begin(), v.end(), slhead);
                print_linkedlist(slhead);
                append_linkedlist(slhead, 8);
                print_linkedlist(slhead);
                reverse_linkedlist(slhead);
                print_linkedlist(slhead);
                destory_linkedlist(slhead);
                cout << "double linked list..." << endl;
                dlnode<int> *dlhead = nullptr;
                build_linkedlist(v.begin(), v.end(), dlhead);
                print_linkedlist(dlhead);
                return 0;
            }
        }
    }
}

int main(int argc, char* argv[]) {
    using namespace algods::linkedlist::unittest;
    return test0();
}
