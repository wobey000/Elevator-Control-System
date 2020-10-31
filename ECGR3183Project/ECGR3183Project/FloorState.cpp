
#include "FloorState.hpp"
#include <iostream>
#include <cstdlib>

using namespace std;

FloorState::FloorState()
{
    soundSignal = false;
    lightSignal = false;
    doorSignal = false;
    IR_Signal = false;
}

FloorState::FloorState(bool ssSignal, bool lSignal, bool dSignal, bool irSignal)
{
    soundSignal = ssSignal;
    lightSignal = lSignal;
    doorSignal = dSignal;
    IR_Signal = irSignal;
}

// getters
int FloorState::getSoundSignal()
{
    return soundSignal;
}
int FloorState::getlightSignal()
{
    return lightSignal;
}
int FloorState::getDoorSignal()
{
    return doorSignal;
}
int FloorState::getIR_Signal()
{
    return IR_Signal;
}

// setters
void FloorState::setSoundSignal(bool s)
{
    soundSignal = s;
}
void FloorState::setLightSignal(bool l)
{
    lightSignal = l;
}
void FloorState::setDoorSignal(bool d)
{
    doorSignal = d;
}
void FloorState::setIRSignal(bool ir)
{
    IR_Signal = ir;
}
