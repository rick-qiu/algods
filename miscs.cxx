#include "miscs.hxx"

#include <vector>
#include <iostream>

namespace algods {
    namespace miscs {
        using namespace std;

        namespace unittest {

            int testjudge0() {
                vector<int> v{4,1,2,5,8,7};
                if(judge(v.begin(), v.end(), 8)) {
                    cout << "testjudge0 passed!" << endl;
                    return 0;
                } else {
                    cout << "testjudge0 failed!" << endl;
                    return 1;
                }
            }
        }
    }
}

int main(int argc, char *argv[]) {
    using namespace algods::miscs::unittest;
    testjudge0();
    return 0;
}
