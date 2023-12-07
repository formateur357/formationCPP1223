#include <iostream>
#include <vector>
#include <ranges>
#include <numeric>
#include <concepts>
#include <string>
#include <variant>

using namespace std;

///// Exo 1

// int main()
// {
//     vector<int> numbers = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

//     auto squared_odd_numbers = numbers | std::views::filter([](int x)
//                                                             { return x % 2 != 0; }) |
//                                std::views::transform([](int x)
//                                                      { return x * x; });

//     int sum_of_squares = accumulate(squared_odd_numbers.begin(), squared_odd_numbers.end(), 0);

//     cout << "Sum of squares of odd number : " << sum_of_squares << endl;

//     return 0;
// }

/////Exo 2

// template <typename T>
// concept Numeric = is_integral<T>::value || is_floating_point<T>::value;

// template <Numeric T>
// T average(T a, T b)
// {
//     return (a + b) / static_cast<T>(2);
// }

// int main()
// {
//     int num1 = 5, num2 = 7;

//     double double1 = 2.5, double2 = 1.5;

//     int average1 = average(num1, num2);
//     double average2 = average(double1, double2);

//     cout << "Average (int) : " << average1 << endl;
//     cout << "Average (double) : " << average2 << endl;

//     return 0;
// }

/////Exo 3

#include <iostream>
#include <variant>
#include <string>

using MyVariant = std::variant<int, std::string, bool>;

// Overload for int
void visitVariant(const int &value)
{
    std::cout << "Integer: " << value << std::endl;
}

// Overload for std::string
void visitVariant(const std::string &value)
{
    std::cout << "String: " << value << std::endl;
}

// Overload for bool
void visitVariant(const bool &value)
{
    std::cout << "Bool: " << std::boolalpha << value << std::endl;
}

int main()
{
    MyVariant data = "Hello, C++";

    std::visit([](const auto &value)
               { visitVariant(value); },
               data);

    data = true;
    std::visit([](const auto &value)
               { visitVariant(value); },
               data);

    data = 23;
    std::visit([](const auto &value)
               { visitVariant(value); },
               data);

    return 0;
}