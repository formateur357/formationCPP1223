#include <iostream>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

/// @Exercice 1 //////////////////////////////////////////////////////////////////////////////////////
enum class Fruit
{
    Pomme,
    Banane,
    Orange
};

string fruitToString(Fruit fruit)
{
    switch (fruit)
    {
    case Fruit::Pomme:
        return "Pomme";
    case Fruit::Banane:
        return "Banane";
    case Fruit::Orange:
        return "Orange";
    default:
        return "Inconnu";
    }
}

int main()
{
    map<Fruit, double> fruitPrices{{Fruit::Pomme, 1.50}, {Fruit::Banane, 2.00}, {Fruit::Orange, 1.75}};

    for (const auto &item : fruitPrices)
    {
        cout << fruitToString(item.first) << " : " << item.second << "$\n";
    }

    auto applyDiscount = [](pair<const Fruit, double> &item)
    {
        item.second *= 0.9;
    };

    // for (auto &item : fruitPrices)
    // {
    //     item.second = applyDiscount(item.second);
    // }

    for_each(fruitPrices.begin(), fruitPrices.end(), applyDiscount);

    cout << "Apres la reduction de 10%" << endl;
    for (const auto &item : fruitPrices)
    {
        cout << fruitToString(item.first) << " : " << item.second << "$\n";
    }

    return 0;
}

/// @Exercice 2 //////////////////////////////////////////////////////////////////////////////////////

/// @Exercice 3 //////////////////////////////////////////////////////////////////////////////////////
