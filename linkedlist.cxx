
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
            int test_difference0() {
                vector<int> a{5, 10, 20, 15, 25, 30};
                vector<int> b{5, 15, 35, 25};
                slnode<int>* left = nullptr;
                slnode<int>* right = nullptr;
                build_linkedlist(a.begin(), a.end(), left);
                build_linkedlist(b.begin(), b.end(), right);
                difference(left, right);
                int ret = 0;
                if(linkedlist2string(left) == "10->20->30") {
                    cout << "testdifference0 passed!" << endl;
                } else {
                    cout << "testdifference0 failed!" << endl;
                    ret = 1;
                }
                destroy_linkedlist(left);
                destroy_linkedlist(right);
                return ret;
            }
        }
    }
}

int main(int argc, char* argv[]) {
    using namespace algods::linkedlist::unittest;
    return test_difference0();
}
