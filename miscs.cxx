#include "miscs.hxx"

#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <sstream>
#include <limits>

namespace algods {
    namespace miscs {

        using namespace std;

        string zipstring(const string& s) {
            string ret;
            if(s.empty()) {
                return ret;
            }
            auto last = s[0];
            auto count = 1;
            auto append = [&ret, &last, &count](){
                if(count > 1) { 
                    ostringstream oss;
                    oss << count;
                    ret.append(oss.str());
                }
                ret.push_back(last);
            };
            for(auto i = 1; i < s.size(); ++i) {
                if(s[i] == last) {
                    ++count;
                } else {
                    append();
                    last = s[i];
                    count = 1;
                }
            }
            append();
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

        vector<unsigned char> run_length_encode(const vector<unsigned char>& bytes) {
            vector<unsigned char> result;
            if(bytes.size() == 0) {
                return result;
            }
            auto last = bytes[0];
            auto count = 1;
            auto append = [&result, &last, &count](){
                while(count > numeric_limits<unsigned char>::max()) {
                    result.push_back(numeric_limits<unsigned char>::max());
                    result.push_back(last);
                    count -= numeric_limits<unsigned char>::max();
                }
                if(count != 0) {
                    result.push_back(static_cast<unsigned char>(count));
                    result.push_back(last);
                }
            };
            for(auto i = 1; i < bytes.size(); ++i) {
                if(bytes[i] == last) {
                    ++count;
                } else {
                    append();
                    last = bytes[i];
                    count = 1;
                }
            }
            append();
            return result;
        }
    }
}
