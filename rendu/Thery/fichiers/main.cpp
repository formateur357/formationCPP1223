#include <iostream>
#include <string>
#include <fstream>

int main()
{
    int Nb[4];
    int i = 0;
    std::string Nom[4];

    std::fstream f;
    f.open("C:\\sources\\formationCPP1223\\rendu\\Thery\\fichiers\\input.txt", std::ios_base::in);
    do {
        f >> Nom[i] >> Nb[i];
        std::cout << Nom[i] << Nb[i] << std::ends;
        i++;
    }while (!f.eof());
    f.close();

    return 0;
}