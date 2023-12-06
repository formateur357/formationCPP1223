#include <map>
#include <iostream>
#include <algorithm>

enum class Fruit {ORANGE, BANANA, APPLE};

using namespace std;

string fruitToString(Fruit f)
{
    switch (f)
    {
    case Fruit::ORANGE: return "ORANGE";
        break;
    case Fruit::BANANA: return "BANANA";
        break;
    case Fruit::APPLE: return "APPLE";
        break;
    default:return "Unkown";
        break;
    }
}

constexpr int textDensity (int nbPages, int nbWords)
{
    return nbWords/nbPages;
}

int main(int argc, char const *argv[])
{
    /* Exo 1 */
    map<Fruit, double> prices;
    prices.insert(make_pair(Fruit::ORANGE, 2.30));
    prices.insert(make_pair(Fruit::BANANA, 1.19));
    prices.insert(make_pair(Fruit::APPLE, 1.42));
    // for_each(prices.begin(), prices.end(), discount);
    for(auto p : prices)
    {
        cout << fruitToString(p.first) << ": " << p.second << "€/Kg" << endl;
    }

    auto discount = [](double price) -> double
    {
        return price * 0.9;
    };
    auto discount2 = [](pair<const Fruit, double> &price)
    {
        price.second *= 0.9;
    };

    for(auto &item : prices)
    {
        item.second = discount(item.second);
    }

    cout << "After 10% discount:" << endl;
    
    for(auto p : prices)
    {
        cout << fruitToString(p.first) << ": " << p.second << "€/Kg" << endl;
    }

    cout << "After another 10% discount:" << endl;
    for_each(prices.begin(), prices.end(), discount2);
    
    for(auto p : prices)
    {
        cout << fruitToString(p.first) << ": " << p.second << "€/Kg" << endl;
    }
    

    /* Exo 2 */
    tuple<string, string, int, int> book{"Super title", "Jean-Random", 200, 30000};
    cout << "Book name = " << get<0>(book) << " ; author = " << get<1>(book) << " ; total of pages = " << get<2>(book) << " ; total of words = " << get<3>(book) << endl;
    cout << "Density of words per page in the book : " << textDensity(get<2>(book), get<3>(book));

    return 0;
}

