#include "string.hxx"

#include <string>
#include <iostream>

namespace algods {
    namespace string {
        namespace unittest {

            int test_kmp_both_empty_string() {
                auto result = kmp("", "");
                auto expected = std::string::npos;
                if(result == expected) {
                    std::cout << "test_kmp_both_empty_string passed!" << std::endl;
                    return 0;
                } else {
                    std::cout << "test_kmp_both_empty_string failed!" << std::endl;
                    return 1;
                }
            }

            int test_kmp_pattern_empty_string() {
                auto result = kmp("I am an engineer", "");
                auto expected = 0;
                if(result == expected) {
                    std::cout << "test_kmp_pattern_empty_string passed!" << std::endl;
                    return 0;
                } else {
                    std::cout << "test_kmp_pattern_empty_string failed!" << std::endl;
                    return 1;
                }
            }

            int test_kmp_text_empty_string() {
                auto result = kmp("", "pattern");
                auto expected = std::string::npos;
                if(result == expected) {
                    std::cout << "test_kmp_text_empty_string passed!" << std::endl;
                    return 0;
                } else {
                    std::cout << "test_kmp_text_empty_string failed!" << std::endl;
                    return 1;
                }
            }

            int test_kmp_exist() {
                auto result = kmp("I am an engineer", "engineer");
                auto expected = 8;
                if(result == expected) {
                    std::cout << "test_kmp_exist passed!" << std::endl;
                    return 0;
                } else {
                    std::cout << "test_kmp_exist failed!" << std::endl;
                    return 1;
                }
            }

            int test_kmp_not_exist() {
                auto result = kmp("I am an engineer", "software");
                auto expected = std::string::npos;
                if(result == expected) {
                    std::cout << "test_kmp_not_exist passed!" << std::endl;
                    return 0;
                } else {
                    std::cout << "test_kmp_not_exist failed!" << std::endl;
                    return 1;
                }
            }

            int test_remove_space_normal() {
                auto result = std::string("I      love          yahoo!");
                auto expected = std::string("I love yahoo!");
                remove_space(result);
                if(result == expected) {
                    std::cout << "test_remove_space_normal passed!" << std::endl;
                    return 0;
                } else {
                    std::cout << "test_remove_space_normal failed!" << std::endl;
                    return 1;
                }
            }

            int test_remove_space_leading() {
                auto result = std::string("          yahoo!");
                auto expected = std::string("yahoo!");
                remove_space(result);
                if(result == expected) {
                    std::cout << "test_remove_space_leading passed!" << std::endl;
                    return 0;
                } else {
                    std::cout << "test_remove_space_leading failed!" << std::endl;
                    return 1;
                }
            }

            int test_remove_space_tail() {
                auto result = std::string("yahoo!     ");
                auto expected = std::string("yahoo!");
                remove_space(result);
                if(result == expected) {
                    std::cout << "test_remove_space_tail passed!" << std::endl;
                    return 0;
                } else {
                    std::cout << "test_remove_space_tail failed!" << std::endl;
                    return 1;
                }
            }

            int test_remove_space_empty() {
                auto result = std::string("");
                auto expected = std::string("");
                remove_space(result);
                if(result == expected) {
                    std::cout << "test_remove_space_empty passed!" << std::endl;
                    return 0;
                } else {
                    std::cout << "test_remove_space_empty failed!" << std::endl;
                    return 1;
                }
            }

            int test_remove_space_empty_result() {
                auto result = std::string("     ");
                auto expected = std::string("");
                remove_space(result);
                if(result == expected) {
                    std::cout << "test_remove_space_empty_result passed!" << std::endl;
                    return 0;
                } else {
                    std::cout << "test_remove_space_empty_result failed!" << std::endl;
                    return 1;
                }
            }

            int test_remove_space_both() {
                auto result = std::string("    I love yahoo!    ");
                auto expected = std::string("I love yahoo!");
                remove_space(result);
                if(result == expected) {
                    std::cout << "test_remove_space_both passed!" << std::endl;
                    return 0;
                } else {
                    std::cout << "test_remove_space_both failed!" << std::endl;
                    return 1;
                }
            }

            int test_replace0() {
                std::string p("abc");
                std::string r("e");
                std::string s("I am a student abc, no words abcdf");
                std::string expected("I am a student e, no words edf");
                replace(s, p, r);
                if(s == expected) {
                    std::cout << "test_replace0 passed!" << std::endl;
                    return 0;
                } else {
                    std::cout << "test_replace0 failed!" << std::endl;
                    return 1;
                }
            }
            
            int test_replace1() {
                std::string p("abc");
                std::string r("IVIISD");
                std::string s("I am a student abc, no words abcdf");
                std::string expected("I am a student IVIISD, no words IVIISDdf");
                replace(s, p, r);
                if(s == expected) {
                    std::cout << "test_replace1 passed!" << std::endl;
                    return 0;
                } else {
                    std::cout << "test_replace1 failed!" << std::endl;
                    return 1;
                }
            }

            int test_replace2() {
                std::string p("abc");
                std::string r("def");
                std::string s("I am a student abc, no words abcdf");
                std::string expected("I am a student def, no words defdf");
                replace(s, p, r);
                if(s == expected) {
                    std::cout << "test_replace2 passed!" << std::endl;
                    return 0;
                } else {
                    std::cout << "test_replace2 failed!" << std::endl;
                    return 1;
                }
            }
        }
    }
}

int main(int argc, char *argv[]) {
    using namespace algods::string::unittest;
    int count = 0;
    count += test_kmp_both_empty_string();
    count += test_kmp_pattern_empty_string();
    count += test_kmp_text_empty_string();
    count += test_kmp_exist();
    count += test_kmp_not_exist();
    count += test_remove_space_normal();
    count += test_remove_space_leading();
    count += test_remove_space_tail();
    count += test_remove_space_empty();
    count += test_remove_space_empty_result();
    count += test_remove_space_both();
    count += test_replace0();
    count += test_replace1();
    count += test_replace2();

    std::cout << std::endl;
    if(count == 0) {
        std::cout << "ALL test cases PASSED! :)" << std::endl;
    } else {
        std::cout << "Some test cases FAILED! :(" << std::endl;
    }
    return count;
}
