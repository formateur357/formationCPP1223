#include <memory>

// Bonne maniere avec data classique
class MonSingleton
{
public:
    static MonSingleton &getInstance()
    {
        static MonSingleton instance;
        return instance;
    }

private:
    MonSingleton() {} // Constructeur privé
    // Copie et affectation non autorisées
    MonSingleton(const MonSingleton &) = delete;
    MonSingleton &operator=(const MonSingleton &) = delete;
};

// bonne maniere avec des data dynamique
class MonSingleton
{
public:
    // Méthode pour obtenir l'instance du singleton
    static MonSingleton &getInstance()
    {
        static MonSingleton instance;
        return instance;
    }

    // Méthode pour libérer l'instance
    static void releaseInstance()
    {
        delete instance;
        instance = nullptr;
    }

private:
    MonSingleton() {}  // Constructeur privé
    ~MonSingleton() {} // Destructeur privé

    // Copie et affectation non autorisées
    MonSingleton(const MonSingleton &) = delete;
    MonSingleton &operator=(const MonSingleton &) = delete;

    static MonSingleton *instance; // Pointeur statique vers l'instance
};

// Initialisation du pointeur statique
MonSingleton *MonSingleton::instance = nullptr;