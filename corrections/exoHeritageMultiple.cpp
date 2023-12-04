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