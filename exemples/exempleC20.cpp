#include <ranges>
#include <vector>
#include <algorithm>
// #include <iostream>

using namespace std;

// definition du trait de type personnalise "IsEven"
// template <typename T>
// struct IsEven {
//     static constexpr bool value = false;
// };

// template <>
// struct IsEven<int> {
//     static constexpr bool value = std::is_same_v<int, int> && (int(1) % int(2) == 0);
// };

// int main() {
//     bool isEvenInt = IsEven<int>::value;
// }

// definition de trait + template avec contraintes

#include <concepts>
#include <type_traits>
#include <iostream>

// // Define a custom concept "Positive" that checks if a type is positive
// template <typename T>
// concept Positive = std::is_arithmetic_v<T> && requires(T x) {
//     {
//         x > 0
//     } -> std::convertible_to<bool>;
// };

// // Function template that uses the custom concept "Positive"
// template <Positive T>
// T double_positive(T value)
// {
//     return value * 2;
// }

// int main()
// {
//     // int positive_int = double_positive(1);  // Calls double_positive with a positive integer
//     int negative_int = double_positive(-3); // This will cause a compilation error as -3 is not positive

//     // std::cout << "Doubled positive integer: " << positive_int << std::endl;
//     std::cout << "Doubled negative_int integer: " << negative_int << std::endl;

//     return 0;
// }

// template avec contraintes explicites
template <typename T>
concept Integral = std::is_integral_v<T>;

template <Integral T>
T add(T a, T b)
{
    return a + b;
}

int main()
{
    // std::ranges
    vector<int> v = {1, 2, 3, 4, 5};

    auto even = v | std::views::filter([](int n)
                                       { return n % 2 == 0; });
    ranges::for_each(even, [](int n)
                     { cout << n << " "; });
}
