#include <iostream>
#include <vector>
#include <algorithm>
#include <ranges>
#include <variant>
 
using namespace std;

/* Exo 1 */
// int main()
// {
//     vector vec = {0, 1, 2, 3, 4, 5};
//     auto even = [](int i) { return 0 == i % 2; };
//     auto square = [](int i) { return i * i; };
 
//     // the "pipe" syntax of composing the views:
//     for (int i : vec | views::filter(even) | views::transform(square))
//         std::cout << i << ' ';
 
//     std::cout << '\n';
// }

// template <typename T>
// concept Numeric = std::is_integral_v<T>;

/* Exo 2 */
template <typename T>
concept Numeric = is_integral_v<T>|is_floating_point_v<T>;

template <Numeric T>
T average(T a, T b)
{
    return (a + b) / 2;
}


int main(int argc, char const *argv[])
{
    /* code */
    int a = 2;
    int b = 3;
    cout << average(a, b) << endl;
    return 0;
}


/* Exo 3 */
// struct Visitor {
//     void operator() (int& t) const
//     {
//         ++t;
//     }
//     void operator() (string& t) const
//     {
//         t += " world!";
//     }
//     void operator() (bool& t) const
//     {
//         if(t) cout << t << endl;
//         else cout << "Not true" << endl;
//     }
// };

// int main(int argc, char const *argv[])
// {   
//     variant<int, string, bool> vari = 10;
//     visit(Visitor{}, vari);

//     visit([](auto &&arg)
//           { cout << arg << endl; },
//           vari);

//     vari = "Hello";
//     visit(Visitor{}, vari);
//     visit([](auto &&arg)
//           { cout << arg << endl; },
//           vari);

//     vari = true;
//     visit(Visitor{}, vari);
//     visit([](auto &&arg)
//           { cout << arg << endl; },
//           vari);

//     vari = false;
//     visit(Visitor{}, vari);
//     visit([](auto &&arg)
//           { cout << arg << endl; },
//           vari);
//     return 0;
// }
