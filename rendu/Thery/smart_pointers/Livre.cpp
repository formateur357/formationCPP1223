#include "Livre.hpp"
#include <iostream>
#include <string>

Livre::Livre(const std::string& titre, const std::string& auteur) : _titre(titre), _auteur(auteur) {}

Livre::~Livre() {}

std::string Livre::getTitre()
{
    return _titre;
}

std::string Livre::getAuteur()
{
    return _auteur;
}

void Livre::setTitre(std::string titre)
{
    _titre = titre;
}

void Livre::setAuteur(std::string auteur)
{
    _auteur = auteur;
}

void Livre::afficherLivre()
{
    std::cout << this->getTitre() << " " << this->getAuteur() << "\n";
}