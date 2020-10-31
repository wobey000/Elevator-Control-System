
#include "ButtonPress.hpp"

ButtonPress::ButtonPress(){}

ButtonPress::ButtonPress(int floor,queue<int> goingToFloor, bool goingUp, bool goingDown){
    floor = floor;
    goingToFloor = goingToFloor;
    goingUp = goingUp;
    goingDown = goingDown;
}

bool ButtonPress::getGoingUpState(){
    return goingUp;
}

bool ButtonPress::getGoingDownState(){
    return goingDown;
}

int ButtonPress::getNextFloor(){
    int next = goingToFloor.front();
    return next;
}

int ButtonPress::getCurrentFloor(){
    return floor;
}

void ButtonPress::addFloor(int x){
    goingToFloor.push(x);
}

queue<int> ButtonPress::getFloorQueue(){
    return goingToFloor;
}
