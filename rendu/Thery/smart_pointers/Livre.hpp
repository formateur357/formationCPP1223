#ifndef ___LIVRE___
#define ___LIVRE___
#include <string>
#include <iostream>

class Livre 
{
    private:
        std::string _titre;
        std::string _auteur;

    public:
        Livre();
        Livre(const std::string& titre, const std::string& auteur);
        ~Livre();
        std::string getTitre();
        std::string getAuteur();
        void setTitre(std::string titre);
        void setAuteur(std::string auteur);
        void afficherLivre();
};

#endif