#include <iostream>
#include <vector>
#include <string>
#include <stdexcept> // Pour la gestion des exceptions

// 1. Créez une classe générique Calculator qui prend un paramètre de type initial (T) lors de son instanciation.
template <typename T>
class Calculator
{
public:
    T result;

    Calculator(T initialValue) : result(initialValue) {}

    // 2. Implémentez les méthodes d'opération de base.
    // Addition
    void add(T value)
    {
        result += value;
    }

    // Soustraction
    void subtract(T value)
    {
        result -= value;
    }

    // Multiplication
    void multiply(T value)
    {
        result *= value;
    }

    // Division
    void divide(T value)
    {
        // Assurez-vous de gérer le cas de division par zéro.
        if (value == 0)
        {
            throw std::invalid_argument("Division by zero");
        }
        result /= value;
    }

    // 3. Ajoutez des méthodes spécifiques pour les types std::string et std::vector.

    // Concaténation (spécifique à std::string)
    void concat(const std::string &value)
    {
        // Utilisez un test conditionnel pour gérer le type std::string.
        if (std::is_same<T, std::string>::value)
        {
            result += value;
        }
        else
        {
            throw std::invalid_argument("Concatenation is only supported for string");
        }
    }

    // Ajout (spécifique à std::vector)
    void append(const T &value)
    {
        // Utilisez un test conditionnel pour gérer le type std::vector.
        if (std::is_same<T, std::vector<T>::value_type>::value)
        {
            for (const T &element : value)
            {
                result.push_back(element);
            }
        }
        else
        {
            throw std::invalid_argument("Append is only supported for vector");
        }
    }

    friend std::ostream &operator<<(std::ostream &os, const Calculator<T> &calc)
    {
        os << "Result" << calc.result;
        return os;
    }

    friend std::ostream &operator<<(std::ostream &os, const std::vector<T> &vec)
    {
        os << "Result : ";
        for (const T &element : vec)
        {
            os << element << " ";
        }
        return os;
    }
};

int main()
{
    try
    {
        // 5. Dans la fonction main, créez des instances de Calculator avec différents types de données.

        // Calculator pour les entiers
        Calculator<int> intCalculator(0);
        intCalculator.add(5);
        intCalculator.subtract(3);

        // Calculator pour les chaînes de caractères
        Calculator<std::string> stringCalculator("");
        stringCalculator.concat("Hello, ");
        stringCalculator.concat("world!");

        // Calculator pour les vecteurs d'entiers
        Calculator<std::vector<int>> vectorCalculator(std::vector<int>{});
        std::vector<int> nums = {1, 2, 3};
        vectorCalculator.append(nums);

        // 6. Affichez les résultats des opérations.
        std::cout << intCalculator << std::endl;    // Affiche le résultat entier : 2
        std::cout << stringCalculator << std::endl; // Affiche le résultat de la chaîne : Hello, world!
        std::cout << vectorCalculator << std::endl; // Affiche le résultat du vecteur : 1 2 3
    }
    catch (const std::invalid_argument &e)
    {
        // 7. Gérez les exceptions et affichez des messages d'erreur appropriés.
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
