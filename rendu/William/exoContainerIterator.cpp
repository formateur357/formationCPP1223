#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

class Book
{
public:
    Book(int id, string title, string author);
    string toString();
    int getID();
    string getTitle();

private:
    int _id;
    string _title;
    string _author;
};
Book::Book(int id, string title, string author):_id(id), _title(title), _author(author){}
string Book::toString()
{
    return _id+" "+_title+" "+_author;
}
int Book::getID()
{
    return _id;
}
string Book::getTitle()
{
    return _title;
}

int main(int argc, char const *argv[])
{
    vector<Book> vec_books;
    map<int, Book> map_books;

    vec_books.push_back(Book(1, "The first book", "Jean Random"));
    vec_books.push_back(Book(2, "The second book", "Jean Random"));
    vec_books.push_back(Book(3, "The third book", "Jean Random"));

    for (vector<Book>::iterator it = vec_books.begin() ; it != vec_books.end(); it++)
    {
        cout << (*it).toString() << endl;
        map_books.insert(make_pair((*it).getID(), (*it)));
    }
    cout << "ID 1 = " << map_books.at(1).toString() << endl;

    //////////////

    sort(vec_books.begin(), vec_books.end(), [](Book a, Book b)
    {
        return a.getTitle() < b.getTitle();
    });

    return 0;
}
