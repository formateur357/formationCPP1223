#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    ofstream f("monFichier.txt");
    f
        << uppercase << hex << 255 << endl;
    f.close();
    fstream fic;
    fic.open("monFichier.txt", ios_base::in | ios_base::out | ios_base::trunc);
    if (fic.is_open())
    {
        // écriture
        fic << "une chaine"
            << " " << 24 << " " << 3.14 << endl;
        fic.seekg(0);
        // lecture
        string si;
        string si2;
        int ii;
        double di;
        fic >> si >> si2 >> ii >> di;
        cout << si << " " << si2 << " " << ii << " " << di << endl;
        fic.close();
    }
}