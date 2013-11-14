#include "string.hxx"

#include <cassert>

#include <string>
#include <vector>


namespace algods {
    namespace string {

        static std::vector<long long> kmp_prefix_func(const std::string& pattern) {
            std::vector<long long> shifts(pattern.size(), -1);
            long long q = -1;
            for(auto i = 1; i < pattern.size(); ++i) {
                while(q >= 0 && pattern[q] != pattern[i]) {
                    q = shifts[q];
                }
                if(pattern[q + 1] == pattern[i]) {
                    ++q;
                }
                shifts[i] = q;
            }
            return shifts;
        }

        static std::string::size_type kmp(const std::string& text,
                                          std::string::size_type pos,
                                          const std::string& pattern,
                                          const std::vector<long long>& shifts) {
            if(pos >= text.size()) {
                return std::string::npos;
            }
            if(pos + pattern.size() > text.size()) {
                return std::string::npos;
            }
            if(pattern.size() == 0) {
                return 0;
            }
            long long q = -1;
            for(auto i = pos; i < text.size(); ++i) {
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

        std::string::size_type kmp(const std::string& text, std::string::size_type pos,
                                   const std::string& pattern) {
            auto shifts = kmp_prefix_func(pattern);
            return kmp(text, pos, pattern, shifts);
        }

        std::string::size_type kmp(const std::string& text, const std::string& pattern) {
            return kmp(text, 0, pattern);
        }

        /********************************************************************************
         ** O(n) on time, O(1) on space
         ********************************************************************************/
        static void replace_equal(std::string& s, const std::string& p,
                                         const std::string& r) {
            assert(p.size() == r.size() && "p.size() == r.size() is not satisfied");

            auto shifts = kmp_prefix_func(p);
            std::string::size_type pos = 0;
            while((pos = kmp(s, pos, p, shifts)) != std::string::npos) {
                for(auto i = std::string::size_type(0); i < r.size(); ++i) {
                    s[pos] = r[i];
                    ++pos;
                }
            }
        }

        /********************************************************************************
         ** O(n) on time, O(1) on space
         ********************************************************************************/
        static void replace_greater(std::string& s, const std::string& p,
                                    const std::string& r) {
            assert(p.size() > r.size() && "p.size() > r.size() is not satisfied");

            auto shifts = kmp_prefix_func(p);
            long long count = 0;
            std::string::size_type pos = 0;
            std::string::size_type start = pos;
            std::string::size_type idx = 0;
            while((pos = kmp(s, pos, p, shifts)) != std::string::npos) {
                for(auto i = start; i != pos; ++i, ++start, ++idx) {
                    s[idx] = s[start];
                }
                for(auto i = idx, j = std::string::size_type(0); j < r.size(); ++j) {
                    s[i] = r[j];
                }
                idx += r.size();
                pos += p.size();
                start = pos;
                ++count;
            }
            for(; start < s.size(); ++start, ++idx) {
                s[idx] = s[start];
            }
            s.resize(s.size() - count * (p.size() - r.size()));
        }

        static std::vector<long long> reverse_kmp_prefix_func(const std::string& pattern) {
            std::vector<long long> shifts(pattern.size(), pattern.size());
            auto q = pattern.size();
            for(long long i = pattern.size() - 2; i >= 0; --i) {
                while(q < pattern.size() && pattern[q] != pattern[i]) {
                    q = pattern[q];
                }
                if(pattern[q - 1] == pattern[i]) {
                    --q;
                }
                shifts[i] = q;
            }
            return shifts;
        }
        static std::string::size_type reverse_kmp(const std::string& text,
                                                  std::string::size_type pos,
                                                  const std::string& pattern,
                                                  const std::vector<long long>& reverse_shifts) {
            if(pos >= text.size()) {
                return std::string::npos;
            }
            if(pos < pattern.size()) {
                return std::string::npos;
            }
            if(pattern.size() == 0) {
                return 0;
            }
            long long q = pattern.size();
            for(long long i = pos; i >= 0; --i) {
                while(q < pattern.size() && pattern[q] != text[i]) {
                    q = reverse_shifts[q];
                }
                if(pattern[q - 1] == text[i]) {
                    --q;
                }
                if(q - 1 < 0) {
                    return i;
                }
            }
            return std::string::npos;
        }
        /********************************************************************************
         ** O(n) on time, O(1) on space
         ********************************************************************************/
        static void replace_less(std::string& s, const std::string& p,
                                    const std::string& r) {
            assert(p.size() < r.size() && "p.size() < r.size() is not satisfied");

            auto reverse_shifts = reverse_kmp_prefix_func(p);
            std::string::size_type pos = s.size() - 1;
            long long count = 0;
            while((pos = kmp(s, pos, p, reverse_shifts)) != std::string::npos) {
                ++count;
            }
            auto size = s.size();
            s.resize(s.size() - count * (r.size() - p.size()));
            pos = size - 1;
            auto end = pos;
            auto idx = s.size() - 1;
            while((pos = kmp(s, pos, p, reverse_shifts)) != std::string::npos) {
                for(auto i = end; i >= pos + p.size(); --i, --idx, --end) {
                    s[idx] = s[end];
                }
                for(auto i = 1; i <= r.size(); ++i, --idx) {
                    s[idx] = r[r.size() - i];
                }
                --pos;
                end = pos;
            }
        }
        /********************************************************************************
         ** O(n) on time, O(1) on space
         ********************************************************************************/
        void replace(std::string& s, const std::string& p, const std::string& r) {
            if(p.size() == r.size()) {
                replace_equal(s, p, r);
                return;
            } else if(p.size() > r.size()) {
                replace_greater(s, p, r);
                return;
            } else {
                replace_less(s, p, r);
                return;
                /*std::string::size_type pos = 0;
                while((pos = kmp(s, pos, p)) != std::string::npos) {
                    s.resize(s.size() + r.size() - p.size());
                    for(auto i = s.size() - 1, j = s.size() - 1 - r.size() + p.size(); i >= pos + p.size(); --i, --j) {
                        s[i] = s[j];
                    }
                    for(auto i = pos, j = std::string::size_type(0); j < r.size(); ++i, ++j) {
                        s[i] = r[j];
                    }
                    pos += r.size();
                    }*/
            }
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
