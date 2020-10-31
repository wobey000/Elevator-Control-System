#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <queue>
#include <vector>
#include "ElevatorState.cpp"
#include "FloorState.hpp"

using namespace std;

// global variables
int userFloorChoice = 0;  // for menu selection
ElevatorState elevator  = ElevatorState();
// main function prototyping a
//void menu();
void fireFighterMenu();
void mainMenu();
void choicesMenu();
void floorMenu(int floor, bool goingUp, bool goingDown);

int main()
{
    mainMenu();

    return 0;
}

void mainMenu()
{

    choicesMenu();
    cout << "What floor are you currently on? Or would you like access to the fireFighterMenu?\n";
    cout << "Choice: ";

    cin >> userFloorChoice;

    switch (userFloorChoice)
    {
        case 0:
            cout << " You are on the ground floor\n";
            floorMenu(0, true, false);
            break;
        case 1:
            cout << " You are on the first floor\n";
            cout << " You can go up or down\n\n";
            while(true){
                cout << " Up (choice 0) \n";
                cout << " Down (choice 1)\n";
                cin >> userFloorChoice;
                if(userFloorChoice == 0){
                    floorMenu(1, true, false);
                    break;
                }else if (userFloorChoice == 1){
                    floorMenu(1, false, true);
                    break;
                }
            }
            break;
        case 2:
            cout << " You are on the second floor\n";
            cout << " You can go up or down\n";
            while(true){
                cout << " Up (choice 0) \n";
                cout << " Down (choice 1)\n";
                cin >> userFloorChoice;
                if(userFloorChoice == 0){
                    floorMenu(2, true, false);
                    break;
                }else if (userFloorChoice == 1){
                    floorMenu(2, false, true);
                    break;
                }
            }
            break;
        case 3:
            cout << " You are on the third floor\n";
            cout << " You can only go down\n";
            floorMenu(0, false, true);
            break;
        case 4:
            cout << " You have choose to go to into fire fighter settings \n";
            fireFighterMenu();
            break;
    }
}
void floorMenu(int floor, bool goingUp, bool goingDown){
    int userFloorChoice = 0;
    queue<int> floorChoices;
    while(userFloorChoice >= 0){
        choicesMenu();
        cout << "What floor would you like to go? Or if you are a FireFighter enter FireFighter Mode\n? ";
        cout << " Choose -1 to stop entering floors\n";
        cin >> userFloorChoice;
        switch (userFloorChoice)
        {
            case 0:
                cout << " You have choose to go to the ground floor\n";
                break;
            case 1:
                cout << " You have choose to go to the first floor\n";
                break;
            case 2:
                cout << " You have choose to go to the second floor\n";
                break;
            case 3:
                cout << " You have choose to go to the third floor\n";
                break;
        }
        floorChoices.push(userFloorChoice);
    }
    cout << " Thank you. You have been added to the queue please wait\n";
    elevator.addToQueue(ButtonPress(floor,floorChoices,goingUp,goingDown));
}

void choicesMenu(){
    cout << " Floor 0 (choice 0) \n";
    cout << " Floor 1 (choice 1)\n";
    cout << " Floor 2  (choice 2)\n";
    cout << " Floor 3  (choice 3)\n";
    cout << " FireFighter Mode (choice 4) \n\n";
}

void fireFighterMenu()
{
    char userDoorChoice;
    cout << " Do you want to manually open the door y/n ?\n";
    cout << "Manually open on?\n";
    cout << "Manually open off?\n";
    cin >> userDoorChoice;
    if(userDoorChoice == 'y' || userDoorChoice == 'Y')
    {
        cout << " You chose to manually open the doors \n";
    }
    else
    {
        cout << " you don't want to manually open the door \n";
    }

}
