#include "definitions_and_declarations.h"
#include "interfaces_and_devices.h"

void move(float v){
    LA.spin(fwd, -120 * v, voltageUnits::mV);
    LB.spin(fwd, -120 * v, voltageUnits::mV);
    LC.spin(fwd, -120 * v, voltageUnits::mV);
    RA.spin(fwd, 120 * v, voltageUnits::mV);
    RB.spin(fwd, 120 * v, voltageUnits::mV);
    RC.spin(fwd, 120 * v, voltageUnits::mV);
}
void timerMove(int moveTime, float v){
    move(v);
    vexDelay(moveTime);
    move(0);
}