#include <memory>

std::unique_ptr<int[]> monTableau(new int[10]);

std::unique_ptr<int> uniquePtr = std::make_unique<int>(10);
std::shared_ptr<int> sharedPtr = std::move(uniquePtr);

// À ce stade, uniquePtr est vide (nullptr) et sharedPtr gère la ressource.

class MonObjet
{
public:
    // ... détails de la classe ...
};

int main()
{
    // Créer un shared_ptr pour gérer un MonObjet
    std::shared_ptr<MonObjet> monObjetPtr1 = std::make_shared<MonObjet>();

    // Créer un autre shared_ptr partageant la propriété de MonObjet
    std::shared_ptr<MonObjet> monObjetPtr2 = monObjetPtr1;

    // Les deux pointeurs partagent la même instance de MonObjet
    // La mémoire sera libérée lorsque les deux pointeurs seront détruits ou réaffectés
}