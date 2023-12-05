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
    void displayInfo() override
    {
        // Résolvez l'ambiguïté et appelez displayInfo de Camera et Speaker
        Camera::displayInfo();
        Speaker::displayInfo();

        // Ajoutez des informations supplémentaires spécifiques à SmartPhone
        std::cout << "Smartphone device\n";
    }
};

// int main()
// {
//     SmartPhone myPhone;
//     // Effectuez le casting et appelez displayInfo() pour Camera et Speaker
//     Camera *cam = dynamic_cast<Camera *>(&myPhone);
//     if (cam)
//         cam->displayInfo();

//     // Appeler displayInfo sur myPhone
//     Speaker *spk = dynamic_cast<Speaker *>(&myPhone);
//     if (spk)
//         spk->displayInfo();

//     myPhone.displayInfo();
// }

// Partie 2 -------------------------------------------------------------------------------------------------

class GPS : virtual public MultimediaDevice
{
public:
    void displayInfo() override { std::cout << "GPS functionality\n"; }
};

class MusicPlayer : virtual public MultimediaDevice
{
public:
    void displayInfo() override { std::cout << "Music Player functionality\n"; }
};

class AdvancedSmartPhone : public SmartPhone, public GPS, public MusicPlayer
{
public:
    void displayInfo() override
    {
        SmartPhone::displayInfo();
        GPS::displayInfo();
        MusicPlayer::displayInfo();
        std::cout << "Advanced Smartphone device\n";
    }

    void activateFeature(const std::string &feature)
    {
        if (feature == "GPS")
        {
            std::cout << "GPS Activated\n";
        }
        else if (feature == "Music")
        {
            std::cout << "Music Player activated\n";
        }
        else
        {
            std::cout << "Feature not recognized\n";
        }
    }
};

int main()
{

    AdvancedSmartPhone myAdvancedPhone;

    // Polymorphisme avec MultimediaDevice* et appels de displayInfo()
    MultimediaDevice *device = dynamic_cast<MultimediaDevice *>(&myAdvancedPhone);
    device->displayInfo();

    // Testez activateFeature() avec différents paramètres
    myAdvancedPhone.activateFeature("GPS");
    myAdvancedPhone.activateFeature("Music");
    myAdvancedPhone.activateFeature("Camera");
}