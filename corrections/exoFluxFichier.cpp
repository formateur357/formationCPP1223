#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

int main()
{
    ifstream inputFile("input.txt");
    ofstream outputFile("output.txt");
    string line, name;
    int score, totalScore = 0, count = 0;
    vector<pair<string, int>> records;

    // lire les donnees du fichier d'entree
    while (getline(inputFile, line))
    {
        istringstream iss(line);
        if (iss >> name >> score)
        {
            records.push_back(make_pair(name, score));
            totalScore += score;
        }
    }

    // calculer le score moyen
    double averageScore = static_cast<double>(totalScore) / records.size();

    // Ecrire dans le fichier de sortie et compter les scores superieurs a la moyenne
    for (const auto &record : records)
    {
        if (record.second > averageScore)
        {
            outputFile << record.first << " " << record.second << endl;
            count++;
        }
    }

    // Afficher le nombre de personnes ayant un score superieur a la moyenne
    cout << "Nombre de personnes au-dessus de la moyenne : " << count << endl;

    // Fermer les fichiers
    inputFile.close();
    outputFile.close();
    return 0;
}