#include <iostream>
#include <map>
#include <string>
#include <algorithm>
#include <tuple>

using namespace std;

/// @Exercice 1 //////////////////////////////////////////////////////////////////////////////////////
// enum class Fruit
// {
//     Pomme,
//     Banane,
//     Orange
// };

// string fruitToString(Fruit fruit)
// {
//     switch (fruit)
//     {
//     case Fruit::Pomme:
//         return "Pomme";
//     case Fruit::Banane:
//         return "Banane";
//     case Fruit::Orange:
//         return "Orange";
//     default:
//         return "Inconnu";
//     }
// }

// int main()
// {
//     map<Fruit, double> fruitPrices{{Fruit::Pomme, 1.50}, {Fruit::Banane, 2.00}, {Fruit::Orange, 1.75}};

//     for (const auto &item : fruitPrices)
//     {
//         cout << fruitToString(item.first) << " : " << item.second << "$\n";
//     }

//     auto applyDiscount = [](pair<const Fruit, double> &item)
//     {
//         item.second *= 0.9;
//     };

//     // for (auto &item : fruitPrices)
//     // {
//     //     item.second = applyDiscount(item.second);
//     // }

//     for_each(fruitPrices.begin(), fruitPrices.end(), applyDiscount);

//     cout << "Apres la reduction de 10%" << endl;
//     for (const auto &item : fruitPrices)
//     {
//         cout << fruitToString(item.first) << " : " << item.second << "$\n";
//     }

//     return 0;
// }

/// @Exercice 2 //////////////////////////////////////////////////////////////////////////////////////

// fonction constexpr pour calculer la densite de texte par page
constexpr double textDensity(int totalWords, int totalPages)
{
    return static_cast<double>(totalWords) / totalPages;
}

int main()
{
    tuple<string, string, int> book("1984", "Georges Orwell", 328);

    constexpr int totalWords = 64000;
    constexpr int totalPages = 328;
    constexpr double density = textDensity(totalWords, totalPages);

    // Affichage des informations du livre et de sa densité de texte
    std::cout << "Livre : " << std::get<0>(book)
              << "\nAuteur : " << std::get<1>(book)
              << "\nNombre de pages : " << std::get<2>(book)
              << "\nDensité de texte : " << density << " mots/page\n";
}

/// @Exercice 3 //////////////////////////////////////////////////////////////////////////////////////
