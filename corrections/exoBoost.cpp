// -----------------------------------------------------------
// Exo 1 => Lexical_cast
// #include <boost/lexical_cast.hpp>
// #include <iostream>
// #include <string>

// using namespace std;
// using namespace boost;

// int main()
// {
//     string input;
//     cout << "Entrez un nombre : ";
//     cin >> input;

//     int number = lexical_cast<int>(input);

//     number *= 2;

//     cout << "Le double de votre nombre est : " << number << endl;

//     string result = lexical_cast<string>(number);
//     cout << "En tant que chaine de caracteres : " << result << endl;

//     return 0;
// }

// -----------------------------------------------------------
// Exo 2 => FileSystem
// #include <boost/filesystem.hpp>
// #include <iostream>
// #include <fstream>

// using namespace std;
// using namespace boost;

// int main()
// {
//     // Creation d'un repertoire
//     filesystem::path dir("test_directory");
//     filesystem::create_directory(dir);

//     // Verification de l'existence du repertoire
//     if (filesystem::exists(dir))
//     {
//         cout << "Repertoire cree avec succes." << endl;

//         // Creation d'un fichier du repertoire
//         filesystem::path file = dir / "exemple.txt";
//         ofstream fileStream(file.string());
//         if (fileStream.is_open())
//         {
//             fileStream << "Exemple de texte";
//             fileStream.close();
//         }

//         // Affichage du chemin absolu du fichier
//         cout << "Chemin du fichier cree : " << filesystem::absolute(file).string() << endl;
//     }
//     else
//     {
//         cout << "Impossible de creer le repertoire." << endl;
//     }

//     return 0;
// }

// -----------------------------------------------------------
// Exo 3 => Regex
// #include <boost/regex.hpp>
// #include <iostream>
// #include <string>

// bool validateEmail(const std::string &email)
// {
//     const boost::regex pattern(R"(^\w+([\.-]?\w+)*@\w+([\.-]?\w+)*(\.\w{2,3})+$)");
//     return boost::regex_match(email, pattern);
// }

// int main()
// {
//     std::string email;
//     std::cout << "Entrez une adresse email pour validation : ";
//     std::cin >> email;

//     if (validateEmail(email))
//     {
//         std::cout << "Adresse email valide." << std::endl;
//     }
//     else
//     {
//         std::cout << "Adresse email invalide." << std::endl;
//     }

//     return 0;
// }

// -----------------------------------------------------------
// Exo 4 => Format
#include <boost/format.hpp>
#include <iostream>
#include <string>

using namespace std;

int main()
{
    string nom, prenom;
    int age;

    cout << "Entrez votre nom : ";
    cin >> nom;

    cout << "Entrez votre prenom : ";
    cin >> prenom;

    cout << "Entrez votre age : ";
    cin >> age;

    boost::format formatter("Bonjour, %1% %2%. Vous avez %3% ans.");
    formatter % prenom % nom % age;
    string message = formatter.str();

    cout << message << endl;
    return 0;
}

// -----------------------------------------------------------
// Exo 5 => FileSystem 2
// #include <boost/filesystem.hpp>
// #include <iostream>

// void searchFiles(const boost::filesystem::path &root, const std::string &extension)
// {
// }

// int main()
// {

//     return 0;
// }

// -----------------------------------------------------------