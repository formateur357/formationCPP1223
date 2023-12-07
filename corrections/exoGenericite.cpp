#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>

// Déclaration de la classe générique Calculator
template <typename T>
class Calculator
{
public:
    T result;

    // Constructeur
    Calculator(T initialValue) : result(initialValue) {}

    // Opérations de base
    void add(T value)
    {
        result += value;
    }

    void subtract(T value)
    {
        result -= value;
    }

    void multiply(T value)
    {
        result *= value;
    }

    void divide(T value)
    {
        if (value == 0)
        {
            throw std::invalid_argument("Division by zero");
        }
        result /= value;
    }

    void printResult()
    {
        std::cout << "Result: " << result << std::endl;
    }
};

// Spécialisation pour std::string
template <>
class Calculator<std::string>
{
public:
    std::string result;

    Calculator(std::string initialValue) : result(initialValue) {}

    void concat(const std::string &value)
    {
        result += value;
    }

    void printResult()
    {
        std::cout << "Result: " << result << std::endl;
    }
};

// Spécialisation pour std::vector<int>
template <>
class Calculator<std::vector<int>>
{
public:
    std::vector<int> result;

    Calculator(std::vector<int> initialValue) : result(initialValue) {}

    void append(const std::vector<int> &value)
    {
        result.insert(result.end(), value.begin(), value.end());
    }

    void printResult()
    {
        std::cout << "Result: ";
        for (const int &elem : result)
        {
            std::cout << elem << " ";
        }
        std::cout << std::endl;
    }
};

// Programme principal pour tester la classe Calculator
int main()
{
    try
    {
        // Pour les entiers
        Calculator<int> intCalculator(0);
        intCalculator.add(5);
        intCalculator.subtract(3);
        intCalculator.printResult(); // Affiche 2

        // Pour les chaînes de caractères
        Calculator<std::string> stringCalculator("");
        stringCalculator.concat("Hello, ");
        stringCalculator.concat("world!");
        stringCalculator.printResult(); // Affiche Hello, world!

        // Pour les vecteurs d'entiers
        Calculator<std::vector<int>> vectorCalculator(std::vector<int>{});
        std::vector<int> nums = {1, 2, 3};
        vectorCalculator.append(nums);
        vectorCalculator.printResult(); // Affiche 1 2 3
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
