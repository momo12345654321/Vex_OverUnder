#include "definitions_and_declarations.h"
#include "interfaces_and_devices.h"

using namespace vex;

void move(float v){
    LA.spin(fwd, -120 * v, voltageUnits::mV);
    LB.spin(fwd, -120 * v, voltageUnits::mV);
    LC.spin(fwd, -120 * v, voltageUnits::mV);
    RA.spin(fwd, 120 * v, voltageUnits::mV);
    RB.spin(fwd, 120 * v, voltageUnits::mV);
    RC.spin(fwd, 120 * v, voltageUnits::mV);
}
void move_turn(float v, int d){
    LA.spin(fwd, 120 * v * d, voltageUnits::mV);
    LB.spin(fwd, 120 * v * d, voltageUnits::mV);
    LC.spin(fwd, 120 * v * d, voltageUnits::mV);
    RA.spin(fwd, 120 * v * d, voltageUnits::mV);
    RB.spin(fwd, 120 * v * d, voltageUnits::mV);
    RC.spin(fwd, 120 * v * d, voltageUnits::mV);
}
void timerMove(int moveTime, float v){
    move(v);
    vexDelay(moveTime);
    move(0);
}
void timerTurnMove(int moveTime, float v, int d){ // (time, move, move)
    move_turn(v, d);
    vexDelay(moveTime);
    move(0);
}
void wait(int time){
    vexDelay(time);
}

