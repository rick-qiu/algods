
namespace algods {
    namespace utils {

        template<typename T>
        struct type_traits {
        };

        template<>
        struct type_traits<int> {
            const static int zero;
        };
        const int type_traits<int>::zero = 0;

        template<>
        struct type_traits<float> {
            const static float zero;
        };
        const float type_traits<float>::zero = 0.0f;

        template<>
        struct type_traits<double> {
            const static double zero;
        };
        const double type_traits<double>::zero = 0;
    }
}
