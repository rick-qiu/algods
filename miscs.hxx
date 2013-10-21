
#include <iterator>
#include <algorithm>

namespace algods {
    namespace miscs {
        using namespace std;

        template<typename random_iterator>
        bool __judge(random_iterator begin, random_iterator end,
                     const typename iterator_traits<random_iterator>::value_type& sum,
                     random_access_iterator_tag) {
            sort(begin, end);
            while(begin != end) {
                auto s = *begin + *end;
                if(s == sum) {
                    return true;
                } else if(s > sum) {
                    prev(end);
                } else {
                    next(begin);
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
                next(it);
                while(it != end) {
                    if(*begin + *it == sum) {
                        return true;
                    }
                    next(it);
                }
                next(begin);
            }
            return false;
        }

        template<typename forward_iterator>
        bool judge(forward_iterator begin, forward_iterator end,
                   const typename iterator_traits<forward_iterator>::value_type& sum) {
            return __judge(begin, end, sum, typename iterator_traits<forward_iterator>::iterator_category());
        }
    }
}
