#include "miscs.hxx"

#include <vector>
#include <set>
#include <iostream>
#include <string>
#include <algorithm>

namespace algods {
    namespace miscs {
        using namespace std;

        namespace unittest {

            int test_judge0() {
                vector<int> v{4,1,2,5,8,7};
                if(judge(v.begin(), v.end(), 8)) {
                    cout << "testjudge0 passed!" << endl;
                    return 0;
                } else {
                    cout << "testjudge0 failed!" << endl;
                    return 1;
                }
            }

            int test_zipstring0() {
                if(zipstring("abcbc") == "abcbc") {
                    cout << "testzipstring0 passed!" << endl;
                    return 0;
                } else {
                    cout << "testzipstrng0 failed!" << endl;
                    return 1;
                }
            }

            int test_zipstring1() {
                if(zipstring("xxxyyyyyyz") == "3x6yz") {
                    cout << "testzipstring1 passed!" << endl;
                    return 0;
                } else {
                    cout << "testzipstrng1 failed!" << endl;
                    return 1;
                }
            }

            int test_zipstring2() {
                if(zipstring("cccddecc") == "3c2de2c") {
                    cout << "testzipstring2 passed!" << endl;
                    return 0;
                } else {
                    cout << "testzipstrng2 failed!" << endl;
                    return 1;
                }
            }

            int test_zipstring3() {
                if(zipstring("adef") == "adef") {
                    cout << "testzipstring3 passed!" << endl;
                    return 0;
                } else {
                    cout << "testzipstrng3 failed!" << endl;
                    return 1;
                }
            }

            int test_zipstring4() {
                if(zipstring("pppppppp") == "8p") {
                    cout << "testzipstring4 passed!" << endl;
                    return 0;
                } else {
                    cout << "testzipstrng4 failed!" << endl;
                    return 1;
                }
            }

            int test_subarray_maxsum0() {
                vector<int> v{-5, 4, -20, 16, -2, -3};
                if(subarray_maxsum(v.begin(), v.end()) == 16) {
                    cout << "test_subarray_maxsum0 passed!" << endl;
                    return 0;
                } else {
                    cout << "test_subarray_maxsum0 failed!" << endl;
                    return 1;
                }
            }

            int test_subarray_minsum0() {
                vector<int> v{-5, 4, -20, 16, -2, -3};
                if(subarray_minsum(v.begin(), v.end()) == -21) {
                    cout << "test_subarray_minsum0 passed!" << endl;
                    return 0;
                } else {
                    cout << "test_subarray_minsum0 failed!" << endl;
                    return 1;
                }
            }

            int test_subarray_maxabssum0() {
                vector<int> v{-5, 4, -20, 16, -2, -3};
                if(subarray_maxabssum(v.begin(), v.end()) == 21) {
                    cout << "test_subarray_maxabssum0 passed!" << endl;
                    return 0;
                } else {
                    cout << "test_subarray_maxabssum0 failed!" << endl;
                    return 1;
                }
            }

            int test_topk0() {
                vector<int> c = {5, 3, 4, -1, 0, 2, 6, 1};
                auto end = topk(c.begin(), c.end(), 4);
                set<int> result(c.begin(), end);
                set<int> expected{6, 5, 4, 3};
                if(result == expected) {
                    cout << "test_topk0 passed!" << endl;
                    return 0;
                } else {
                    cout << "test_topk0 failed!" << endl;
                    return 1;
                }
            }

            int test_topk1() {
                vector<int> c = {5, 3, 4, -1, 0, 2, 6, 1};
                auto end = topk(c.begin(), c.end(), 9);
                set<int> result(c.begin(), end);
                set<int> expected{5, 3, 4, -1, 0, 2, 6, 1};
                if(result == expected) {
                    cout << "test_topk1 passed!" << endl;
                    return 0;
                } else {
                    cout << "test_topk1 failed!" << endl;
                    return 1;
                }
            }

            int test_topk2() {
                vector<int> c = {5, 3, 4, -1, 0, 2, 6, 1};
                auto end = topk(c.begin(), c.end(), 6);
                set<int> result(c.begin(), end);
                set<int> expected{5, 3, 4, 2, 6, 1};
                if(result == expected) {
                    cout << "test_topk2 passed!" << endl;
                    return 0;
                } else {
                    cout << "test_topk2 failed!" << endl;
                    return 1;
                }
            }

            int test_translate0() {
                string expected = "IQIIBIIISIV";
                string result = translate(1234);
                if(expected == result) {
                    cout << "test_translate0 passed!" << endl;
                    return 0;
                } else {
                    cout << "test_translate0 failed!" << endl;
                    return 1;
                }
            }

            int test_translate1() {
                string expected = "IWIIQIIIBIVSV";
                string result = translate(12345);
                if(expected == result) {
                    cout << "test_translate1 passed!" << endl;
                    return 0;
                } else {
                    cout << "test_translate1 failed!" << endl;
                    return 1;
                }
            }

            int test_translate2() {
                string expected = "IYIIQIIIBIVSVWVIQVIIBVIIISIX";
                string result = translate(123456789);
                if(expected == result) {
                    cout << "test_translate2 passed!" << endl;
                    return 0;
                } else {
                    cout << "test_translate3 failed!" << endl;
                    return 1;
                }
            }

            int test_translate3() {
                string expected = "V";
                string result = translate(5);
                if(expected == result) {
                    cout << "test_translate3 passed!" << endl;
                    return 0;
                } else {
                    cout << "test_translate3 failed!" << endl;
                    return 1;
                }
            }

            int test_translate4() {
                string expected = "IQIIBOIV";
                string result = translate(1204);
                if(expected == result) {
                    cout << "test_translate4 passed!" << endl;
                    return 0;
                } else {
                    cout << "test_translate4 failed!" << endl;
                    return 1;
                }
            }

            int test_translate5() {
                string expected = "IWOIIBIIISIV";
                string result = translate(10234);
                if(expected == result) {
                    cout << "test_translate5 passed!" << endl;
                    return 0;
                } else {
                    cout << "test_translate5 failed!" << endl;
                    return 1;
                }
            }

            int test_translate6() {
                string expected = "IVSIIYIXQIVBIXSVIWVIIQIIBIXSV";
                string result = translate(4294967295);
                if(expected == result) {
                    cout << "test_translate6 passed!" << endl;
                    return 0;
                } else {
                    cout << "test_translate6 failed!" << endl;
                    return 1;
                }
            }
        }
    }
}

int main(int argc, char *argv[]) {
    using namespace algods::miscs::unittest;
    test_judge0();
    test_zipstring0();
    test_zipstring1();
    test_zipstring2();
    test_zipstring3();
    test_zipstring4();
    test_subarray_maxsum0();
    test_subarray_minsum0();
    test_subarray_maxabssum0();
    test_topk0();
    test_topk1();
    test_topk2();
    test_translate0();
    test_translate1();
    test_translate2();
    test_translate3();
    test_translate4();
    test_translate5();
    test_translate6();
    return 0;
}
