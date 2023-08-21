#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>
#include <tuple>
#include <type_traits>

#ifndef TEMPLATELIB_H
#define TEMPLATELIB_H
namespace aml
{
    /**
     * @brief gets the Nth element in a template parameter pack
     *
     * @tparam N template element
     * @tparam Ts template parameter pack
     */
    template <int N, typename... Ts>
    using indexInTemplate =
        typename std::tuple_element<N, std::tuple<Ts...>>::type;

    /**
     * @brief returns the combined sizeof every item in a template parameter pack
     *
     * @tparam T template parameter pack
     * @return constexpr size_t sum of the size of all the parameters
     */
    template <typename... T>
    constexpr size_t packSize()
    {

        return (sizeof(T) + ...);
    }
    /**
     * @brief returns a boolean value indicative of if a template type paramater is contained within a template pack
     *
     * @tparam T template type being checked for
     * @tparam Ts template pack to compare to
     * @return true, template pack contains the type checked for
     * @return false, template pack does not comtain the type being checked for
     */
    template <typename T, typename... Ts>
    constexpr bool contains()
    {
        return std::disjunction_v<std::is_same<T, Ts>...>;
    }
}
#endif // TEMPLATELIB_H