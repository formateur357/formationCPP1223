#include <iostream>
#include <string>
#include "Livre.hpp"
#include <memory>

int main()
{
    //std::unique_ptr<Livre> l1(new Livre("Mer","Verne"));
    std::unique_ptr<Livre> l1 = std::make_unique<Livre>("Mer","Verne");

    l1->afficherLivre();

    //std::shared_ptr<Livre> l2(new Livre("Comte","Dumas"));
    std::shared_ptr<Livre> l2 = std::make_shared<Livre>("Comte","Dumas");

    l2->afficherLivre();

    std::shared_ptr<Livre> l3 = l2;
    std::cout << l2.use_count() << "\n";

    l3->afficherLivre();

    //std::shared_ptr<Livre> l4(new Livre("Sorceleur","Sapkowski"));
    std::shared_ptr<Livre> l4 = std::make_shared<Livre>("Sorceleur","Sapkowski");

    l4->afficherLivre();

    std::weak_ptr<Livre> weak1 = l2;

    if(auto tmp = weak1.lock())
    {
        std::cout << "weak1 valeur " << tmp << "\n";
    }
    else
    {
        std::cout << "weak1 inexistant";
    }

    return 0;
}