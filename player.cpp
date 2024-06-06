#include "player.h"

Player::Player(){
    marks.reserve(5);
}

void Player::setName(std::string inputName){
    name = inputName;
}

std::string Player::getName()const{
    return name;
}

void Player::setAge(float inputAge){
    if(inputAge < 1){
        inputAge = 1;
    }
    age = inputAge;
}

float Player::getAge()const{
    return age;
}