
#include "ElevatorState.hpp"
#include "queue"
#include <iostream>
#include "ButtonPress.hpp"
using namespace std;

class ElevatorState{
    bool goingUp, goingDown, waiting, fireFighterMode;
    int currentFloor;
    int totalTime;
    vector<ButtonPress> floorQueue; //floors calling
    queue<ButtonPress> personOnElevator; //people currently on elevator

public:
    ElevatorState(){
        goingUp = false;
        goingDown = false;
        waiting = true;
        currentFloor = 1;
        totalTime = 0;
    }

    void elevatorMove(){
        if(waiting){
            //if the elevator is not moving
            waiting = false;
            elevatorMove();
        }else{
            //if the elevator is moving
            if(!floorQueue.empty() || !personOnElevator.empty()){
                if(!personOnElevator.empty()){
                    while (!personOnElevator.empty()) {
                        ButtonPress currentProcess = personOnElevator.front();
                        personOnElevator.pop();
                        cout << "New Elevator Ride\n";
                        if(currentProcess.getGoingUpState()){
                            goingUp = true;
                            goingDown = false;
                            cout << "Going Up\n";
                            move(currentProcess);
                        }else{
                            goingUp = false;
                            goingDown = true;
                            cout << "Going down\n";
                            move(currentProcess);
                        }

                    }
                }else{
                    //elevator empty floor queue not
                    ButtonPress nextProcess = floorQueue.front();
                    floorQueue.erase(floorQueue.begin());
                    personOnElevator.push(nextProcess);
                    elevatorMove();
                }
            }else{
                //send the elevator to floor 1
                queue<int> floors;
                floors.push(1);
                if(currentFloor > 1){
                    goingUp = false;
                    goingDown = true;
                    move(ButtonPress(1,floors, goingUp, goingDown));
                }else{
                    goingUp = true;
                    goingDown = false;
                    move(ButtonPress(1,floors, goingUp, goingDown));
                }
            }
        }
    }

    void move(ButtonPress next){
        waiting = false;
        while(!next.getFloorQueue().empty()){
            if(currentFloor == next.getNextFloor()){
                //latch doors
                cout << "Latching Doors\n";
                //open doors
                cout << "Opening Doors\n";
                //wait for Ir
                cout << "IR-Sensing Persons\n";
                //close doors
                cout << "Closing Doors\n";
            }else if(goingUp){
                for(int i = currentFloor; i < next.getNextFloor(); i++){
                    //check floor calls to see if people are waiting at the current floor
                    //add to persons on elevator
                    cout << "Going up to next floor\n";
                    vector<ButtonPress> tempVector = checkFloorsQueue(i);
                    if(tempVector.size() > 0){
                        //latch doors
                        cout << "Latching Doors\n";
                        //open doors
                        cout << "Opening Doors\n";
                        //wait for Ir
                        cout << "IR-Sensing Persons\n";
                        //close doors
                        cout << "Closing Doors\n";
                        for(int i = 0; i < tempVector.size(); i++){
                            personOnElevator.push(tempVector.at(i));

                        }
                    }
                    //track time
                }
                //remove people that are getting off at this floor
                next.getFloorQueue().pop();
            }else if(goingDown){
                for(int i = currentFloor; i > next.getNextFloor(); i--){
                    //check floor calls to see if people are waiting at the current floor
                    //add to persons on elevator
                    cout << "Going down to next floor\n";
                    vector<ButtonPress> tempVector = checkFloorsQueue(i);
                    if(tempVector.size() > 0){
                        //latch doors
                        cout << "Latching Doors\n";
                        //open doors
                        cout << "Opening Doors\n";
                        //wait for Ir
                        cout << "IR-Sensing Persons\n";
                        //close doors
                        cout << "Closing Doors\n";
                        for(int i = 0; i < tempVector.size(); i++){
                            personOnElevator.push(tempVector.at(i));

                        }
                    }
                    //track time
                }
                //remove people that are getting off at this floor
                next.getFloorQueue().pop();
            }
        }
        elevatorMove();
    }

    vector<ButtonPress> checkFloorsQueue(int floorNumber){
        vector<ButtonPress> temp;
        for(int i =0; i < floorQueue.size(); i++){
            if(floorQueue.at(i).getCurrentFloor() == floorNumber){
                temp.push_back(floorQueue.at(i));
                floorQueue.erase(floorQueue.begin() + i);
            }
        }
        return temp;
    }

    void setCurrentFloor(int floorNum){
        currentFloor = floorNum;
    }

    void addToQueue(ButtonPress buttonPress){
        floorQueue.push_back(buttonPress);
        elevatorMove();
    }

    void printCurrentState(){
        cout << "Current State of all inputs and outputs";
    }
};
