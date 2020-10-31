
#ifndef ButtonPress_hpp
#define ButtonPress_hpp

#include <stdio.h>
#include <vector>
#include "queue"
using namespace std;

class ButtonPress {
    int floor;
    queue<int> goingToFloor; // 1 - 3 - 4
    bool goingUp, goingDown;
    bool outside;
    bool inside;


    public:
        ButtonPress();
        ButtonPress(int floor,queue<int> goingToFloor, bool goingUp, bool goingDown);
        bool getGoingUpState();
        bool getGoingDownState();
        int getNextFloor();
        void addFloor(int x);
        int getCurrentFloor();
        queue<int> getFloorQueue();

};

#endif /* ButtonPress_hpp */
