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

constexpr double textDensity (int nbPages, int nbWords)
{
    return static_cast<double>(nbWords/nbPages);
}

class Book
{
    public:
        Book(string title, string author, int pages):_title(title), _author(author), _pages(pages){}
        string getTitle(){return _title;}
        string getAuthor(){return _author;}
        int getPages(){return _pages;}
        string toString();

    private: 
        string _title;
        string _author;
        int _pages;
};

string Book::toString()
{
    return (_title + " written by " + _author + " has " + to_string(this->getPages()) + " pages");
}

class BookWithSummary final: public Book
{
    public:
        BookWithSummary(string title, string author, int pages, string summary):Book(title,author,pages), _summary(summary){}
        string getSummary(){return _summary;}
        string toString();

    private: 
        string _summary;
};

string BookWithSummary::toString()
{
    return (this->getTitle() + " written by " + this->getAuthor() + " has " + to_string(this->getPages()) + " pages" + " and tells the following story: " + _summary);
}

constexpr double calculateCost(double price, int nbPages)
{
    return static_cast<double>(price/nbPages);
}

int main(int argc, char const *argv[])
{
    /* Exo 1 */
    cout << "--- Exo 1 ---" << endl;
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
    cout << endl << "--- Exo 2 ---" << endl;
    tuple<string, string, int, int> book{"Super title", "Jean-Random", 200, 30000};
    cout << "Book name = " << get<0>(book) << " ; author = " << get<1>(book) << " ; total of pages = " << get<2>(book) << " ; total of words = " << get<3>(book) << endl;
    cout << "Density of words per page in the book : " << textDensity(get<2>(book), get<3>(book)) << endl;


    /* Exo 3 */
    cout << endl << "--- Exo 3 ---" << endl;
    BookWithSummary bookWithSummary("Wonderful book", "Jean-Random", 300, "It's a wonderful book telling wonderful things");
    cout << bookWithSummary.toString() << endl;
    cout << bookWithSummary.getTitle() << " costs " << calculateCost(10, bookWithSummary.getPages()) << "€ per page" << endl;
    return 0;
}
