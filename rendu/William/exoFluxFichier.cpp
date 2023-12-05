#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;
int main()
{
    vector<pair<string,int>> data;
    string line;
    string name;
    int number;

    fstream file;
    file.open("C:\\Users\\william.bequetrennes\\Desktop\\Cours_cpp\\formationCPP1223\\rendu\\William\\inputFile.txt", ios_base::in);
    if(file.is_open())
    {
        cout << "Reading inputFile.txt" << endl;
        while (getline(file, line)) {
            cout << line << endl;
            istringstream lstream(line);
            if(lstream >> name >> number)
            {
                data.push_back(make_pair(name, number));
            }
        }
        file.close();
    }
}