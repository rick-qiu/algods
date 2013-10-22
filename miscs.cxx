#include "miscs.hxx"

#include <vector>
#include <iostream>
#include <string>
#include <algorithm>

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
    }
}
