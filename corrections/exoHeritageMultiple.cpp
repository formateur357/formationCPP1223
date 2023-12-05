#include <iostream>
#include <string>

class MultimediaDevice
{
public:
    virtual void displayInfo() { std::cout << "Multimedia device\n"; }
};

class Camera : virtual public MultimediaDevice
{
public:
    void displayInfo() override { std::cout << "Camera device\n"; }
};

class Speaker : virtual public MultimediaDevice
{
public:
    void displayInfo() override { std::cout << "Speaker device\n"; }
};

class SmartPhone : public Camera, public Speaker
{
public:
    void displayInfo()
    {
        // TODO: Résolvez l'ambiguïté et appelez displayInfo de Camera et Speaker
        // TODO: Ajoutez des informations supplémentaires spécifiques à SmartPhone
    }
};

int main()
{
    SmartPhone myPhone;
    // TODO: Effectuez le casting et appelez displayInfo() pour Camera et Speaker
    // TODO: Appeler displayInfo sur myPhone
}

// Partie 2 -------------------------------------------------------------------------------------------------

// class GPS : public MultimediaDevice
// {
// public:
//     void displayInfo() override { std::cout << "GPS functionality\n"; }
// };

// class MusicPlayer : public MultimediaDevice
// {
// public:
//     void displayInfo() override { std::cout << "Music Player functionality\n"; }
// };

// class AdvancedSmartPhone : public SmartPhone, public GPS, public MusicPlayer
// {
// public:
//     void displayInfo() override
//     {
//         // TODO: Intégrez les informations de toutes les classes de base
//     }

//     void activateFeature(const std::string &feature)
//     {
//         // TODO: Activez la fonctionnalité correspondante
//     }
// };

// int main()
// {

//     AdvancedSmartPhone myAdvancedPhone;
//     // TODO: Polymorphisme avec MultimediaDevice* et appels de displayInfo()
//     // TODO: Testez activateFeature() avec différents paramètres
// }