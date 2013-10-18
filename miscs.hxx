
#include <iterator>
#include <algorithm>

namespace algods {
    namespace miscs {
        using namespace std;

        template<typename input_iterator>
        typename iterator_traits<input_iterator>::value_type maxsum(input_iterator begin, input_iterator end) {
            typedef typename iterator_traits<input_iterator>::value_type value_t;
            value_t max_sum = 0;
            value_t cur_sum = 0;
            while(begin != end) {
                cur_sum += *begin;
                if(cur_sum < 0) {
                    cur_sum = 0;
                }
                max_sum = max(max_sum, cur_sum);
            }
            return max_sum;
        }
    }
}
