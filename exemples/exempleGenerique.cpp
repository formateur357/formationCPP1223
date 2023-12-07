#include <iostream>

using namespace std;

template <typename T>
class MyArray
{
private:
    T *array;
    size_t size;

public:
    MyArray(size_t size) : size(size), array(new T[size]) {}

    T &operator[](size_t index)
    {
        return array[index];
    }

    ~MyArray()
    {
        delete[] array;
    }
};

template <typename T>
T add(T a, T b)
{
    return a + b;
}

int main()
{
    int x = 5, y = 7;
    double p = 3.14, q = 2.71;

    cout << "Sum of the integers : " << add(x, y) << endl;
    cout << "Sum of the doubles : " << add(p, q) << endl;

    // MyArray<int> intArray(5);
    // for (int i = 0; i < 5; ++i)
    // {
    //     intArray[i] = i * 2;
    //     cout << intArray[i] << " ";
    // }
    // cout << endl;

    return 0;
}