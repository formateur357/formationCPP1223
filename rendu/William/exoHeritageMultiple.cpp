#include <string>
#include <iostream>

using namespace std;

enum TYPE { T_GPS, T_SPEAKER, T_CAMERA };

class MultimediaDevice
{
public:
    virtual string displayInfo();
};

string MultimediaDevice::displayInfo()
{
    return "MultimediaDevice";
}

class Camera : virtual public MultimediaDevice
{
public:
    string displayInfo() override;
};

string Camera::displayInfo()
{
    return "Camera";
}

class Speaker : virtual public MultimediaDevice
{
public:
    string displayInfo() override;
};

string Speaker::displayInfo()
{
    return "Speaker";
}

class Smartphone : virtual public MultimediaDevice, public Camera, public Speaker
{
public:
    string displayInfo() override;
};

string Smartphone::displayInfo()
{
    return "Smartphone";
}

class GPS : virtual public MultimediaDevice
{
public:
    string displayInfo() override;
};

string GPS::displayInfo()
{
    return "GPS";
}

class MusicPlayer : virtual public MultimediaDevice
{
public:
    string displayInfo() override;
};
string MusicPlayer::displayInfo()
{
    return "MusicPlayer";
}

class AdvancedSmartphone : public Smartphone, public GPS, public MusicPlayer
{
public:
    string displayInfo() override;
    string activateFeature(TYPE feature);
};
string AdvancedSmartphone::displayInfo()
{
    GPS * gps = dynamic_cast<GPS *>(this);
    MusicPlayer * musicPlayer = dynamic_cast<MusicPlayer *>(this);
    Smartphone * smartphone = dynamic_cast<Smartphone *>(this);
    Camera * camera = dynamic_cast<Camera *>(smartphone);
    Speaker * speaker = dynamic_cast<Speaker *>(smartphone);
    return smartphone->Smartphone::displayInfo()+" "+camera->Camera::displayInfo()+" "+speaker->Speaker::displayInfo()+" "+gps->GPS::displayInfo()+" "+musicPlayer->MusicPlayer::displayInfo();
}

string AdvancedSmartphone::activateFeature(TYPE feature)
{
    GPS * gps = dynamic_cast<GPS *>(this);
    Smartphone * smartphone = dynamic_cast<Smartphone *>(this);
    Speaker * speaker = dynamic_cast<Speaker *>(smartphone);
    Camera * camera = dynamic_cast<Camera *>(smartphone);
    switch (feature)
    {
    case T_GPS:
        return gps->GPS::displayInfo();
        break;
    case T_SPEAKER:
        return speaker->Speaker::displayInfo();
        break;
    case T_CAMERA:
        return camera->Camera::displayInfo();
        break;
    }
    return "ERROR";
}

int main(int argc, char const *argv[])
{
    Smartphone * smartphone = new Smartphone();
    Camera * camera = dynamic_cast<Camera *>(smartphone);
    Speaker * speaker = dynamic_cast<Speaker *>(smartphone);
    
    cout << smartphone->displayInfo() << endl;
    cout << camera->displayInfo() << endl;
    cout << speaker->displayInfo() << endl;
    
    cout << smartphone->Camera::displayInfo() << endl;
    cout << smartphone->Speaker::displayInfo() << endl;

    
    AdvancedSmartphone * avancedSmartphone = new AdvancedSmartphone();
    cout << avancedSmartphone->AdvancedSmartphone::displayInfo() << endl;
    cout << avancedSmartphone->activateFeature(T_GPS) << endl;

    return 0;
}


