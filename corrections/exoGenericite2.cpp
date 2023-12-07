#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>

template <typename T>
class Calculator
{
public:
    Calculator(T initialValue) : result(initialValue) {}

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

    void concat(const std::string &value)
    {
        if (std::is_same<T, std::string>::value)
        {
            result += value;
        }
        else
        {
            throw std::invalid_argument("Concatenation is only supported for std::string");
        }
    }

    void append(const T &value)
    {
        if (std::is_same<T, typename std::vector<T>::value_type>::value)
        {
            result.insert(result.end(), value.begin(), value.end());
        }
        else
        {
            throw std::invalid_argument("Append is only supported for std::vector");
        }
    }

    void printResult() const
    {
        std::cout << "Result: " << result << std::endl;
    }

private:
    T result;
};

int main()
{
    try
    {
        Calculator<int> intCalculator(0);
        intCalculator.add(5);
        intCalculator.subtract(3);

        Calculator<std::string> stringCalculator("");
        stringCalculator.concat("Hello, ");
        stringCalculator.concat("world!");

        Calculator<std::vector<int>> vectorCalculator(std::vector<int>{});
        std::vector<int> nums = {1, 2, 3};
        vectorCalculator.append(nums);

        intCalculator.printResult();
        stringCalculator.printResult();
        vectorCalculator.printResult();
    }
    catch (const std::invalid_argument &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
