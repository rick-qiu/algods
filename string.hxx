#ifndef ALGODS_STRING_HXX
#define ALGODS_STRING_HXX

#include <string>

namespace algods {
    namespace string {

        /*******************************************************************************
         ** classic KMP
         ******************************************************************************/
        std::string::size_type kmp(const std::string& text, const std::string& pattern);
        std::string::size_type kmp(const std::string& text, std::string::size_type pos,
                                   const std::string& pattern);

        /*******************************************************************************
         ** remove extra spaces, e.g.
         ** "I      love          yahoo!" => "I love yahoo!"
         ** "    yahoo!" => "yahoo!"
         ** "yahoo!    " => "yahoo!"
         ******************************************************************************/
        void remove_space(std::string& s);

        /******************************************************************************
         ** replace all occurs of p in s with r
         *****************************************************************************/
        void replace(std::string& s, const std::string& p, const std::string& r);
    }
}

#endif
