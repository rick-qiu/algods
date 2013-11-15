#include "miscs.hxx"

#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <sstream>

namespace algods {
    namespace miscs {

        using namespace std;

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
                        char ch = static_cast<char>('0' + count[idx(s[i-1])]);
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

        string translate(unsigned n) {
            vector<string> dict1{"O", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
            if(n < 10) {
                return dict1[n];
            }
            vector<string> dict2{"", "S", "B", "Q"};
            vector<string> unit{"", "W", "Y", "Z"};
            vector<string> temp;
            unsigned m = 10;
            unsigned k = 0;
            unsigned h = 0;
            while(n > 0) {
                if(h >= 4) {
                    ++k;
                    h = 0;
                    temp.push_back(unit[k]);
                }
                auto j = n % m;
                n /= m;
                if(j != 0) {
                    temp.push_back(dict2[h]);
                }
                temp.push_back(dict1[j]);
                ++h;
            }
            string result;
            for_each(temp.rbegin(), temp.rend(), [&result](const string& s){ result.append(s);});
            return result;
        }

        void reorder(vector<int>& vi) {
            auto i = vector<int>::size_type(0);
            auto j = vi.size() - 1;
            while(i < j) {
                while(i < vi.size() && vi[i] % 2 != 0) {
                    ++i;
                }
                while(j >= 0 && vi[j] % 2 == 0) {
                    --j;
                }
                if(i < j) {
                    swap(vi[i], vi[j]);
                    ++i;
                    --j;
                }
            }
        }

        string run_length_encode(const string& s) {
            string result;
            if(s.size() <= 0) {
                return result;
            }
            auto last = s[0];
            auto count = 1;
            for(auto i = 1; i < s.size(); ++i) {
                if(s[i] == last) {
                    ++count;
                } else {
                    ostringstream oss;
                    oss << count;
                    result.append(oss.str());
                    result.push_back(last);
                    last = s[i];
                    count = 1;
                }
            }
            ostringstream oss;
            oss << count;
            result.append(oss.str());
            result.push_back(last);
            return result;
        }
    }
}
