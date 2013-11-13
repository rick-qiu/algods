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
    }
}
