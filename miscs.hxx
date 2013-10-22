#include "utils.hxx"

#include <iterator>
#include <algorithm>
#include <string>

namespace algods {
    namespace miscs {
        using namespace std;

        using namespace algods::utils;

        /************************************************************
        ** "abcbc" => "abcbc"
        ** "xxxyyyyyyz" => "3x6yz"
        ** "cccddecc" => "3c2de2c"
        ** "adef" => "adef"
        ** "pppppppp" => "8p"
        ** the source string only contains character in [a-z]
        ************************************************************/
        string zipstring(const string& s);

        /***********************************************************
         **
         **********************************************************/
        template<typename input_iterator>
        typename iterator_traits<input_iterator>::value_type subarray_maxsum(input_iterator begin, input_iterator end) {
            typedef typename iterator_traits<input_iterator>::value_type value_t;
            auto maxsum = type_traits<value_t>::zero;
            auto cursum = type_traits<value_t>::zero;
            for_each(begin, end, [&](const value_t& e) { cursum += e; cursum = max(cursum, type_traits<value_t>::zero); maxsum = max(maxsum, cursum); });
            return maxsum;
        }

        template<typename input_iterator>
        typename iterator_traits<input_iterator>::value_type subarray_minsum(input_iterator begin, input_iterator end) {
            typedef typename iterator_traits<input_iterator>::value_type value_t;
            auto minsum = type_traits<value_t>::zero;
            auto cursum = type_traits<value_t>::zero;
            for_each(begin, end, [&](const value_t& e) { cursum += e; cursum = min(cursum, type_traits<value_t>::zero); minsum = min(minsum, cursum); });
            return minsum;
        }

        template<typename input_iterator>
        typename iterator_traits<input_iterator>::value_type subarray_maxabssum(input_iterator begin, input_iterator end) {
            typedef typename iterator_traits<input_iterator>::value_type value_t;
            return max(abs(subarray_maxsum(begin, end)), abs(subarray_minsum(begin, end)));
        }

        template<typename random_iterator>
        bool __judge(random_iterator begin, random_iterator end,
                     const typename iterator_traits<random_iterator>::value_type& sum,
                     random_access_iterator_tag) {
            if(begin == end) {
                return false;
            }
            sort(begin, end);
            --end; // move end to the last element
            while(begin != end) {
                auto s = *begin + *end;
                if(s == sum) {
                    return true;
                } else if(s > sum) {
                    --end;
                } else {
                    ++begin;
                }
            }
            return false;
        }

        template<typename forward_iterator>
        bool __judge(forward_iterator begin, forward_iterator end,
                   const typename iterator_traits<forward_iterator>::value_type& sum,
                   forward_iterator_tag) {
            while(begin != end) {
                auto it = begin;
                ++it;
                while(it != end) {
                    if(*begin + *it == sum) {
                        return true;
                    }
                    ++it;
                }
                ++begin;
            }
            return false;
        }

        /*****************************************************************************
        ** determine whether there are two elements in [begin, end) satisfying
        ** element1 + element2 = sum
        ******************************************************************************/
        template<typename forward_iterator>
        bool judge(forward_iterator begin, forward_iterator end,
                   const typename iterator_traits<forward_iterator>::value_type& sum) {
            return __judge(begin, end, sum, typename iterator_traits<forward_iterator>::iterator_category());
        }
    }
}
