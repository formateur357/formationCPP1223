#include <iostream>
#include <string>
#include "MultimediaDevice.hpp"

int main()
{
    //g++ -std=c++20 -Wall -Wextra *.cpp -o prog
    SmartPhone * smartphone = new SmartPhone();
    smartphone->displayInfo();
    std::cout << "SmartPhone: " << typeid(*smartphone).name() << "\n";
    std::cout << "\n";

    Camera * camera = dynamic_cast<Camera *>(smartphone);
    camera->displayInfo();
    std::cout << "Camera: " << typeid(*camera).name() << "\n";
    std::cout << "\n";

    Speaker * speaker = dynamic_cast<Speaker *>(smartphone);
    speaker->displayInfo();
    std::cout << "Speaker: " << typeid(*speaker).name() << "\n";
    std::cout << "\n";

    MultimediaDevice * md1 = new Camera();
    md1->displayInfo();
    std::cout << "md1: " << typeid(*md1).name() << "\n";
    Camera * md11 = dynamic_cast<Camera *>(md1);
    md11->displayInfo();
    std::cout << "md11: " << typeid(*md11).name() << "\n";
    std::cout << "\n";

    MultimediaDevice * md2 = new Speaker();
    md2->displayInfo();
    std::cout << "md2: " << typeid(*md2).name() << "\n";
    Speaker * md12 = dynamic_cast<Speaker *>(md2);
    md12->displayInfo();
    std::cout << "md12: " << typeid(*md12).name() << "\n";
    std::cout << "\n";

    MultimediaDevice * md3 = new SmartPhone();
    md3->displayInfo();
    std::cout << "md3: " << typeid(*md3).name() << "\n";
    MultimediaDevice * md13 = dynamic_cast<SmartPhone *>(md3);
    md13->displayInfo();
    std::cout << "md13: " << typeid(*md13).name() << "\n";
    std::cout << "\n";

    MultimediaDevice * md4 = new GPS();
    md4->displayInfo();
    std::cout << "md4: " << typeid(*md4).name() << "\n";
    MultimediaDevice * md14 = dynamic_cast<GPS *>(md4);
    md14->displayInfo();
    std::cout << "md14: " << typeid(*md14).name() << "\n";
    std::cout << "\n";

    MultimediaDevice * md5 = new MusicPlayer();
    md5->displayInfo();
    std::cout << "md5: " << typeid(*md5).name() << "\n";
    MultimediaDevice * md15 = dynamic_cast<MusicPlayer *>(md5);
    md15->displayInfo();
    std::cout << "md15: " << typeid(*md15).name() << "\n";
    std::cout << "\n";

    MultimediaDevice * md6 = new AdvancedSmartPhone();
    md6->displayInfo();
    std::cout << "md6: " << typeid(*md6).name() << "\n";
    MultimediaDevice * md16 = dynamic_cast<AdvancedSmartPhone *>(md6);
    md16->displayInfo();
    std::cout << "md16: " << typeid(*md16).name() << "\n";
    std::cout << "\n";

    AdvancedSmartPhone * adsmartphone = new AdvancedSmartPhone();
    adsmartphone->displayInfo();
    std::cout << "AdvancedSmartPhone: " << typeid(*adsmartphone).name() << "\n";
    std::cout << "\n";
    adsmartphone->activateFeature("GPS");
    adsmartphone->activateFeature("MusicPlayer");
    adsmartphone->activateFeature("Rien");
    std::cout << "\n";

    delete smartphone;
    delete camera;
    delete speaker;
    delete adsmartphone;
    delete md1;
    delete md2;
    delete md3;
    delete md4;
    delete md5;
    delete md11;
    delete md12;
    delete md13;
    delete md14;
    delete md15;
    delete md16;

    return 0;
}