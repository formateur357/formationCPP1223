#include <iostream>
#include <vector>
#include <map>

using namespace std;

// auto

// auto x = 5;
// auto y = 3.14;

// auto list = {1, 2, 3};

// auto multiply(double x, double y)
// {
//     return x * y;
// }

// int main()
// {
//     cout << *list.begin();

//     vector<int> vec = {1, 2, 3, 4, 5};
//     for (auto i : vec)
//     {
//         cout << i << " ";
//     }

//     for (auto it = vec.begin(); it != vec.end(); ++it)
//     {
//         cout << *it << " ";
//     }

//     // exemple de lambda generique
//     auto add = [](auto a, auto b)
//     { return a + b; };

//     cout << add(5, 6) << endl;
//     cout << add(4.5, 6.37) << endl;

//     map<string, vector<int>> map1;
//     auto iter = map1.begin();
// }

// constexpr

// constexpr int factorial(int n)
// {
//     int result = 1;
//     for (int i = 2; i <= n; ++i)
//     {
//         result *= i;
//     }
//     return result;
// }

// // c++17 uniquement
// template <typename T>
// auto printTypeInformation(const T &val)
// {
//     if constexpr (is_integral<T>::value)
//     {
//         cout << "Le parametre est un entier." << endl;
//     }
//     else if constexpr (is_floating_point<T>::value)
//     {
//         cout << "flottant" << endl;
//     }
//     else
//     {
//         cout << "another type" << endl;
//     }
// }

// int main()
// {
//     constexpr int val = factorial(10);

//     printTypeInformation(5);
//     printTypeInformation(5.55);
//     printTypeInformation("Hello");
// }

// stl

long long operator"" _million(long double val)
{
    return val * 1000000;
}

int main()
{
    // auto arr = new int[10];
    int n;
    cin >> n;
    auto arr = new int[n];

    auto population = 7.8_million;

    cout << population;
    delete[] arr;
    return 0;
}
