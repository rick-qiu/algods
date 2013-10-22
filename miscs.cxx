#include "miscs.hxx"

#include <vector>
#include <iostream>
#include <string>

namespace algods {
    namespace miscs {

        string zipstring(const string& s) {
            string ret;
            if(s.empty()) {
                return ret;
            }
            auto idx = [](char ch)->int { return ch - 'a';};
            ret.reserve(s.size());
            constexpr int size = 'z' - 'a' + 1;
            int count[size] = {};
            int i = 0;
            ++count[idx(s[i])];
            for(i = 1; i < s.size(); ++i) {
                ++count[idx(s[i])];
                if(s[i] != s[i-1]) {
                    if(count[idx(s[i-1])] > 1) {
                        char ch = static_cast<char>('0' + count[s[i-1]-'a']);
                        ret.push_back(ch);
                    }
                    ret.push_back(s[i-1]);
                    count[idx(s[i-1])] = 0;
                }
            }
            if(count[idx(s[i-1])] != 0) {
                if(count[idx(s[i-1])] > 1) {
                    char ch = static_cast<char>('0' + count[idx(s[i-1])]);
                    ret.push_back(ch);
                }
                ret.push_back(s[i-1]);
            }
            return ret;
        }
    }
}

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
    return 0;
}
