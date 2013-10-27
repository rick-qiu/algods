
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
                if(linkedlist2string(left) == "{10->20->30}") {
                    cout << "testdifference0 passed!" << endl;
                } else {
                    cout << "testdifference0 failed!" << endl;
                    ret = 1;
                }
                destroy_linkedlist(left);
                destroy_linkedlist(right);
                return ret;
            }

            int test_reorder_linkedlist0() {
                int ret = 0;
                vector<int> v{};
                slnode<int>* head = nullptr;
                build_linkedlist(v.begin(), v.end(), head);
                reorder_linkedlist(head);
                if(linkedlist2string(head) == "{}") {
                    cout << "test_reorder_linkedlist0 passed!" << endl;
                } else {
                    cout << "test_reorder_linkedlist0 failed!" << endl;
                    ret = 1;
                }
                return ret;
            }

            int test_reorder_linkedlist1() {
                int ret = 0;
                vector<int> v{1};
                slnode<int>* head = nullptr;
                build_linkedlist(v.begin(), v.end(), head);
                reorder_linkedlist(head);
                if(linkedlist2string(head) == "{1}") {
                    cout << "test_reorder_linkedlist1 passed!" << endl;
                } else {
                    cout << "test_reorder_linkedlist1 failed!" << endl;
                    ret = 1;
                }
                return ret;
            }

            int test_reorder_linkedlist2() {
                int ret = 0;
                vector<int> v{1, 2};
                slnode<int>* head = nullptr;
                build_linkedlist(v.begin(), v.end(), head);
                reorder_linkedlist(head);
                if(linkedlist2string(head) == "{1->2}") {
                    cout << "test_reorder_linkedlist2 passed!" << endl;
                } else {
                    cout << "test_reorder_linkedlist2 failed!" << endl;
                    ret = 1;
                }
                return ret;
            }

            int test_reorder_linkedlist3() {
                int ret = 0;
                vector<int> v{1, 2, 3};
                slnode<int>* head = nullptr;
                build_linkedlist(v.begin(), v.end(), head);
                reorder_linkedlist(head);
                if(linkedlist2string(head) == "{1->3->2}") {
                    cout << "test_reorder_linkedlist3 passed!" << endl;
                } else {
                    cout << "test_reorder_linkedlist3 failed!" << endl;
                    ret = 1;
                }
                return ret;
            }

            int test_reorder_linkedlist4() {
                int ret = 0;
                vector<int> v{1, 2, 3, 4};
                slnode<int>* head = nullptr;
                build_linkedlist(v.begin(), v.end(), head);
                reorder_linkedlist(head);
                if(linkedlist2string(head) == "{1->4->2->3}") {
                    cout << "test_reorder_linkedlist4 passed!" << endl;
                } else {
                    cout << "test_reorder_linkedlist4 failed!" << endl;
                    ret = 1;
                }
                return ret;
            }

            int test_reorder_linkedlist5() {
                int ret = 0;
                vector<int> v{1, 2, 3, 4, 5};
                slnode<int>* head = nullptr;
                build_linkedlist(v.begin(), v.end(), head);
                reorder_linkedlist(head);
                if(linkedlist2string(head) == "{1->5->2->4->3}") {
                    cout << "test_reorder_linkedlist5 passed!" << endl;
                } else {
                    cout << "test_reorder_linkedlist5 failed!" << endl;
                    ret = 1;
                }
                return ret;
            }
        }
    }
}

int main(int argc, char* argv[]) {
    using namespace algods::linkedlist::unittest;
    int count = 0;
    count += test_difference0();
    count += test_reorder_linkedlist0();
    count += test_reorder_linkedlist1();
    count += test_reorder_linkedlist2();
    count += test_reorder_linkedlist3();
    count += test_reorder_linkedlist4();
    count += test_reorder_linkedlist5();
    cout << endl;
    if(count == 0) {
        cout << "ALL test cases PASSED! :)" << endl;
    } else {
        cout << "Some test cases FAILED! :(" << endl;
    }
    return count;
}
