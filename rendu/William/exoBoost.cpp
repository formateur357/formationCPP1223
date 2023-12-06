
#include <iostream>
#include <boost/lexical_cast.hpp> 
#include <boost/regex.hpp>
#include <boost/format.hpp>

using namespace std;
using namespace boost;

bool isMailValid(string mail)
{
    regex expr{".*@.*\..*"};
    return regex_match(mail, expr);
}

int main(int argc, char const *argv[])
{

    /* Exo 1 */
    string s;
    int i;
    cout << "Enter a number" << endl;
    cin >> s;

    i = lexical_cast<int>(s)
    i*=2;
    s = lexical_cast<string>(i);
    cout << s << endl;

    /* Exo 3 */
    string mail_ok = "test@boite.mail";
    string mail_incorrect = "testboitemail";
    cout << mail_ok << " is correct: " << isMailValid(mail_ok) << endl;
    cout << mail_incorrect << " is correct: " << isMailValid(mail_incorrect) << endl;

    /* Exo 4 */
    string name, surname, age;
    cout << "Enter your name" << endl;
    cin >> name;
    cout << "Enter your surname" << endl;
    cin >> surname;
    cout << "Enter your age" << endl;
    cin >> age;
    cout << format("Your name is %1% %2%, and you are %3% years old") %name %surname %age << endl;

    return 0;
}
