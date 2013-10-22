#include "miscs.hxx"

#include <vector>
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
    return 0;
}
