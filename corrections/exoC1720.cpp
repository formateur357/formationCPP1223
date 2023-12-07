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

/////Exo 3