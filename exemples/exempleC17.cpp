// amelioration auto c++17

// auto findValue()
// {
//     if (condition)
//     {
//         return value1; // type int par exemple
//     }
//     else
//     {
//         return value2; // doit être aussi int , avec c++ 17 un autre type est possible
//     }
// }

// decltype(auto) a utiliser avec precaution, utile pour la genericite

// template <typename ContainerType, typename IndexType> // C++14
// decltype(auto) grab(ContainerType &&container, IndexType &&index)
// {
//     authenticateUser();
//     return std::forward<ContainerType>(container)[std::forward<IndexType>(index)];
// }

// std::variant
#include <iostream>
#include <variant>
#include <string>

using namespace std;

// std::variant std::visit
int main()
{
    variant<int, float, string> v = "Hello";

    v = 20;
    v = 22.7f;
    v = "Bonjour";

    visit([](auto &&arg)
          { cout << arg << endl; },
          v);

    return 0;
}
