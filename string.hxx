#ifndef ALGODS_STRING_HXX
#define ALGODS_STRING_HXX

#include <string>

namespace algods {
    namespace string {
        std::string::size_type kmp(const std::string& text, const std::string& pattern);
        /*******************************************************************************
         ** remove extra spaces, e.g.
         ** "I      love          yahoo!" => "I love yahoo!"
         ** "    yahoo!" => "yahoo!"
         ** "yahoo!    " => "yahoo!"
         ******************************************************************************/
        void remove_space(std::string& s);
    }
}

#endif
