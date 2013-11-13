#include "string.hxx"

#include <string>
#include <vector>

namespace algods {
    namespace string {

        std::string::size_type kmp(const std::string& text, const std::string& pattern) {
            if(text.size() < pattern.size() || text.size() == 0) {
                return std::string::npos;
            }
            if(pattern.size() == 0) {
                return 0;
            }
            std::vector<long long> shifts(pattern.size(), -1);
            auto prefix_func = [&shifts, &pattern]() { 
                long long q = -1;
                for(auto i = 1; i < pattern.size(); ++i) {
                    while(q >= 0 && pattern[q + 1] != pattern[i]) {
                        q = shifts[q];
                    }
                    if(pattern[q + 1] == pattern[i]) {
                        ++q;
                    }
                    shifts[i] = q;
                }
            };
            prefix_func();
            long long q = -1;
            for(auto i = 0; i < text.size(); ++i) {
                while(q >= 0 && pattern[q + 1] != text[i]) {
                    q = shifts[q];
                }
                if(pattern[q + 1] == text[i]) {
                    ++q;
                }
                if(q + 1 == pattern.size()) {
                    return i - pattern.size() + 1;
                }
            }
            return std::string::npos;
        }

        void remove_space(std::string& s) {
            const static char space = ' ';
            auto next_pos = std::string::size_type(0);
            auto cur_pos = std::string::size_type(0);
            auto space_count = 0;
            auto size = 0;
            while(cur_pos < s.size()) {
                if(s[cur_pos] != space) {
                    s[next_pos] = s[cur_pos];
                    ++next_pos;
                    space_count = 0;
                    size  = next_pos;
                }
                if(s[cur_pos] == space) {
                    if(space_count < 1 && next_pos != 0) {
                        s[next_pos] = space;
                        ++next_pos;
                    }
                    ++space_count;
                }
                ++cur_pos;
            }
            s.resize(size);
        }
    }
}
