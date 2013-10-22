#ifndef ALGODS_UTILS_HXX
#define ALGODS_UTILS_HXX
namespace algods {
    namespace utils {

        template<typename T>
        struct type_traits {
        };

        template<>
        struct type_traits<int> {
            const static int zero;
        };

        template<>
        struct type_traits<float> {
            const static float zero;
        };

        template<>
        struct type_traits<double> {
            const static double zero;
        };
    }
}
#endif
