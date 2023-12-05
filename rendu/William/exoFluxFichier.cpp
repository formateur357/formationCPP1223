#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
int main()
{
    vector<string> names;
    vector<int> numbers;
    string line;

    fstream file;
    file.open("inputFile.txt", ios_base::in);
    if(file.is_open())
    {
        cout << "Reading inputFile.txt" << endl;
        while (getline(file, line)) {
            cout << "turn\n";
            int n;
            string s;
            file >> s >> n;
            names.push_back(s);
            numbers.push_back(n);
        }
        file.close();
    }
}