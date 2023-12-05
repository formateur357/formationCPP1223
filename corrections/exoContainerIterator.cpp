#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <algorithm>

using namespace std;

// Définition de la structure Livre
struct Livre
{
    int id;
    string titre;
    string auteur;

    Livre(int id = 0, string titre = "", string auteur = "") : id(id), titre(titre), auteur(auteur) {}
};

// Affiche les détails d'un livre
void afficherLivre(const Livre &livre)
{
    cout << "ID: " << livre.id << ", Titre: " << livre.titre << ", Auteur: " << livre.auteur << endl;
}

int main()
{
    // Partie 1: Utilisation de vector et map ------------------------------------------------------------------------
    vector<Livre> bibliotheque;

    // Ajout de livres dans le vector
    bibliotheque.push_back(Livre(1, "livre A", "Auteur A"));
    bibliotheque.push_back(Livre(2, "livre B", "Auteur B"));

    // Affichage des livres en utilisant un itérateur
    cout << "Liste des livres:" << endl;
    for (const auto &livre : bibliotheque)
    {
        afficherLivre(livre);
    }

    // Création d'une map pour mapper ID de livre à l'objet Livre
    map<int, Livre> mapLivres;
    for (const Livre &livre : bibliotheque)
    {
        mapLivres[livre.id] = livre;
    }

    // Recherche d'un livre par ID
    int idRecherche = 1;
    auto it = mapLivres.find(idRecherche);
    if (it != mapLivres.end())
    {
        cout << "Livre trouve: ";
        afficherLivre(it->second);
    }
    else
    {
        cout << "Livre non trouve." << endl;
    }

    // Gestion des emprunts
    set<int> emprunts;
    emprunts.insert(1);
    if (emprunts.find(1) != emprunts.end())
    {
        cout << "Livre ID 1 est emprunte." << endl;
    }

    // Partie 2: Opérations avancées et algorithmes STL --------------------------------------------------------------

    // Tri du vector de livres par titre
    sort(bibliotheque.begin(), bibliotheque.end(), [](const Livre &a, Livre &b)
         { return a.titre < b.titre; });

    // Filtrage des livres d'un auteur spécifique
    vector<Livre> livresAuteurA;
    copy_if(bibliotheque.begin(), bibliotheque.end(), back_inserter(livresAuteurA), [](const Livre &livre)
            { return livre.auteur == "Auteur A"; });

    // Utilisation de unordered_map pour regrouper les livres par auteur
    unordered_map<string, vector<Livre>> livresParAuteur;
    for (const auto &livre : bibliotheque)
    {
        livresParAuteur[livre.auteur].push_back(livre);
    };

    // Suggestion de livres basés sur une plage de titres
    auto lower = lower_bound(bibliotheque.begin(), bibliotheque.end(), "Livre A", [](const Livre &livre, const string &titre)
                             { return livre.titre < titre; });

    auto upper = upper_bound(bibliotheque.begin(), bibliotheque.end(), "Livre B", [](const Livre &livre, const string &titre)
                             { return livre.titre < titre; });

    cout << "Livres suggeres: " << endl;
    for (auto it = lower; it != upper; ++it)
    {
        afficherLivre(*it);
    }

    return 0;
}