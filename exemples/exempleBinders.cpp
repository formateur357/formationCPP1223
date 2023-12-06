#include <algorithm>
#include <vector>
#include <functional>
#include <string>

class Book
{
public:
    bool hasISBN(const std::string &isbn) const
    {
        // implementation...
    }
    // autres membres..
};

int main()
{
    std::vector<Book> library = {/* ... */};
    std::string isbnToFind = "some-isbn";

    auto hasNotSpecificISBN = std::bind(&Book::hasISBN, std::placeholders::_1, isbnToFind);
    auto it = std::find_if(library.begin(), library.end(), hasNotSpecificISBN);

    // Utiliser l'iterateur
}
