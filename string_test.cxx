#include "string.hxx"

#include <string>
#include <iostream>

namespace algods {
    namespace string {
        namespace unittest {

            int test_both_empty_string() {
                auto result = kmp("", "");
                auto expected = std::string::npos;
                if(result == expected) {
                    std::cout << "test_both_empty_string passed!" << std::endl;
                    return 0;
                } else {
                    std::cout << "test_both_empty_string failed!" << std::endl;
                    return 1;
                }
            }

            int test_pattern_empty_string() {
                auto result = kmp("I am an engineer", "");
                auto expected = 0;
                if(result == expected) {
                    std::cout << "test_pattern_empty_string passed!" << std::endl;
                    return 0;
                } else {
                    std::cout << "test_pattern_empty_string failed!" << std::endl;
                    return 1;
                }
            }

            int test_text_empty_string() {
                auto result = kmp("", "pattern");
                auto expected = std::string::npos;
                if(result == expected) {
                    std::cout << "test_text_empty_string passed!" << std::endl;
                    return 0;
                } else {
                    std::cout << "test_text_empty_string failed!" << std::endl;
                    return 1;
                }
            }

            int test_exist() {
                auto result = kmp("I am an engineer", "engineer");
                auto expected = 8;
                if(result == expected) {
                    std::cout << "test_exist passed!" << std::endl;
                    return 0;
                } else {
                    std::cout << "test_exist failed!" << std::endl;
                    return 1;
                }
            }

            int test_not_exist() {
                auto result = kmp("I am an engineer", "software");
                auto expected = std::string::npos;
                if(result == expected) {
                    std::cout << "test_not_exist passed!" << std::endl;
                    return 0;
                } else {
                    std::cout << "test_not_exist failed!" << std::endl;
                    return 1;
                }
            }
        }
    }
}

int main(int argc, char *argv[]) {
    using namespace algods::string::unittest;
    int count = 0;
    count += test_both_empty_string();
    count += test_pattern_empty_string();
    count += test_text_empty_string();
    count += test_exist();
    count += test_not_exist();

    std::cout << std::endl;
    if(count == 0) {
        std::cout << "ALL test cases PASSED! :)" << std::endl;
    } else {
        std::cout << "Some test cases FAILED! :(" << std::endl;
    }
    return count;
}
