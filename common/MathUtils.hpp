#ifndef MATHUTILS_HPP
#define MATHUTILS_HPP

#include <type_traits>
#include <limits>

#include <configure.h>


namespace PROGRAM_NAMESPACE {

class MathUtils {

private:
    static constexpr int ULP_DEFAULT = 3;

public:

    template<class T>
    static inline typename std::enable_if_t<!std::numeric_limits<T>::is_integer, bool> almostEqual(T x, T y, int ulp = ULP_DEFAULT) {
        // NOTE NIC 20/05/2019 - vedere link en.cppreference - numeric limits - epsilon
        return std::abs(x-y) <= std::numeric_limits<T>::epsilon() * std::abs(x + y) * ulp
            || std::abs(x-y) < std::numeric_limits<T>::min();
    }

    template<class T>
    static inline typename std::enable_if_t<std::numeric_limits<T>::is_integer, bool> almostEqual(T x, T y) {
        return x == y;
    }

    /* NOTE NIC 06/12/2019 - due funzioni devono differire per il tipo di template, non solo per gli argomenti
     * la keywork typename definisce il tipo, assegnando un valore si ha argomento e tipo diversi,
     * quindi le due funzioni sono diverse
     */

    template<class T, typename std::enable_if_t<!std::is_integral_v<T>, int> = 0>
    static inline bool almostEqualExample(T x, T y, int ulp = ULP_DEFAULT) {
        // NOTE NIC 20/05/2019 - vedere link en.cppreference - numeric limits - epsilon
        return std::abs(x-y) <= std::numeric_limits<T>::epsilon() * std::abs(x + y) * ulp
            || std::abs(x-y) < std::numeric_limits<T>::min();
    }

    template<class T, typename std::enable_if_t<std::is_integral_v<T>, int> = 0>
    static inline bool almostEqualExample(T x, T y) {
        return x == y;
    }

};

}

#endif // MATHUTILS_HPP
