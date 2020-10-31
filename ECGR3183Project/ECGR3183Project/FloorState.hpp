

#ifndef FloorState_hpp
#define FloorState_hpp

#include <stdio.h>
#include <iostream>

using namespace std;

class FloorState
{
private:
    bool soundSignal;
    bool lightSignal;
    bool doorSignal;
    bool IR_Signal;
public:
    FloorState();
    FloorState(bool ssSignal, bool lSignal, bool dSignal, bool irSignal);
    // getters
    int getSoundSignal();

    int getlightSignal();

    int getDoorSignal();

    int getIR_Signal();

    // setters
    void setSoundSignal(bool s);

    void setLightSignal(bool l);

    void setDoorSignal(bool d);

    void setIRSignal(bool ir);

};

#endif /* FloorState_hpp */
