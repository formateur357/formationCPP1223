#include "MultimediaDevice.hpp"
#include <iostream>
#include <string>

void MultimediaDevice::displayInfo(){
    std::cout << "MultimediaDevice\n";
};

void Camera::displayInfo(){
    std::cout << "Camera\n";
}

void Speaker::displayInfo(){
    std::cout << "Speaker\n";
}

void SmartPhone::displayInfo(){
    std::cout << "Smartphone\n";
}

void GPS::displayInfo(){
    std::cout << "GPS\n";
}

void MusicPlayer::displayInfo(){
    std::cout << "MusicPlayer\n";
}

void AdvancedSmartPhone::displayInfo(){
    std::cout << "AdvancedSmartPhone\n";
}

void AdvancedSmartPhone::activateFeature(const std::string &fonction){
    if (fonction == "GPS"){
        GPS::displayInfo();
    }else if (fonction == "MusicPlayer"){
        MusicPlayer::displayInfo();
    }
    else{
        std::cout << "Non reconnu\n";
    }
}