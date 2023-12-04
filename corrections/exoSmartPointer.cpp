#include <iostream>
#include <memory>
#include <string>
#include <vector>

using namespace std;

class Livre
{
private:
    std::string titre;
    std::string auteur;

public:
    Livre(const std::string &t, const std::string &a) : titre(t), auteur(a) {}

    void afficher() const
    {
        std::cout << "\nLivre: " << titre << ", Auteur: " << auteur << std::endl;
    }
};

int main()
{

    // Utilisation de unique_ptr
    unique_ptr<Livre> livreUnique = make_unique<Livre>("1984", "George Orwell");
    livreUnique->afficher();

    // Utilisation de shared_ptr
    shared_ptr<Livre> livrePartage1 = make_shared<Livre>("Le petit prince", "Antoine de Saint-Exupery");
    shared_ptr<Livre> livrePatage2 = livrePartage1;

    livrePartage1->afficher();
    cout << "Nombre de references: " << livrePartage1.use_count();

    // Utilisation de weak_ptr
    weak_ptr<Livre> livreFaible = livrePartage1;

    if (auto sharedPtr = livreFaible.lock())
    {
        sharedPtr->afficher();
    }
    else
    {
        cout << "Nombre de references apres reset: " << livrePartage1.use_count() << endl;
    }

    return 0;
}