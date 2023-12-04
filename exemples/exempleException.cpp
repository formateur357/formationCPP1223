#include <exception>
#include <iostream>

using namespace std;

// Cette fonction est appelée lorsqu'une exception inattendue est lancée.
void myUnexpected()
{
    cout << "Unexpected exception\n";
    // Lancer std::bad_exception pour signaler une exception inattendue.
    throw bad_exception();
}

// myFunction est spécifiée pour ne lancer que std::bad_exception.
void myFunction() throw(bad_exception)
{
    try
    {
        throw 2; // Lancer une exception non specifiee
    }
    catch (int) // Attraper l'exception de type int.
    {
        cout << "Caught an int\n";
        throw; // Relancer l'exception
    }
}

int main()
{
    // Définir myUnexpected comme gestionnaire d'exceptions inattendues.
    set_unexpected(myUnexpected);
    try
    {
        // Appeler myFunction qui peut lancer une exception inattendue.
        myFunction();
    }
    catch (const bad_exception &) // Attraper et gérer std::bad_exception.
    {
        cout << "Caught a bad_exception\n";
    }

    return 0;
}