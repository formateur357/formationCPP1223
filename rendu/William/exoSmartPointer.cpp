#include <string>
#include <iostream>
#include <memory>

class Book
{
private:
    std::string _title;
    std::string _author;
public:
    Book(const std::string title, const std::string author);
    ~Book();
    void toString();
    std::string getTitle();
};

Book::Book(const std::string title, const std::string author):
_title(title), _author(author)
{
}

Book::~Book()
{
}

void Book::toString()
{
    std::cout << "Title = " << _title << " ; Author = " << _author << std::endl;
}

std::string Book::getTitle()
{
    return _title;
} 

int main(int argc, char const *argv[])
{
    std::unique_ptr<Book> unique_book = std::make_unique<Book>("Unique Title", "Unique Author");
    unique_book->toString();

    std::shared_ptr<Book> shared_book1 = std::make_shared<Book>("The story of Shared Title", "Shared Author"));
    std::shared_ptr<Book> shared_book2 = std::make_shared<Book>("Back to Shared Title", "Shared Author"));
    std::shared_ptr<Book> shared_book3 = std::make_shared<Book>("The end of Shared Title", "Shared Author"));

    std::shared_ptr<Book> shared_book1_bis = shared_book1;
    std::shared_ptr<Book> shared_book1_ter = shared_book1;

    std::cout << shared_book1->getTitle() << " has been printed " << shared_book1.use_count() << " times" << std::endl;

    std::weak_ptr<Book> weak_book = shared_book1;

    if (weak_book.expired())
	    std::cout << shared_book1->getTitle() << " has burned" << std::endl;
    else
        std::cout << shared_book1->getTitle() << " is still printed" << std::endl;

    return 0;
}
