#include <iostream>
#include <vector>

using namespace std;

template <typename T>

class Calculator
{
private:
    T _value;
public:

    Calculator(T val):_value(val){}
    void add(T val){ _value+=val; }
    void subtract(T val){ _value-=val; }
    void multiply(T val){ _value*=val; }
    void divide(T val){ 
        if( val != 0) _value/=val;
        else throw invalid_argument("ERROR: The parameter can't be 0");
    }
    void concat(const string& val){
        if (is_same<T, string>::value){
             _value += val;
        }
    }
    void append(const vector<T>& val){ 
        if(is_same<T, vector<T>::value_type>::value) {
             _value.insert(end(_value), begin(val), end(val)); 
        }
    }
    T getValue(){ return _value; }
};

int main(int argc, char const *argv[])
{
    Calculator calculator(5);
    cout << calculator.getValue() << endl;
    calculator.add(2);
    cout << "+2 = " << calculator.getValue() << endl;
    calculator.subtract(2);
    cout << "-2 = " << calculator.getValue() << endl;
    calculator.multiply(2);
    cout << "*2 = " << calculator.getValue() << endl;
    try{calculator.divide(2);}
    catch(const std::exception& e){std::cerr << e.what() << '\n';}
    cout << "/2 = " << calculator.getValue() << endl;
    
    Calculator string_calc(string("Hello"));
    string_calc.concat(" world!");
    cout << string_calc.getValue() << endl;
    
    vector<int> vec{ 1, 2, 3 };
    vector<int> vec2{ 4, 5, 6 };
    Calculator vec_calc(vec);
    vec_calc.concat(" world!");
    // vec_calc.append(vec2);
    for (auto element : vec_calc.getValue()) {
        cout << element << " ";
    }
    cout << endl;
    
    return 0;
}

