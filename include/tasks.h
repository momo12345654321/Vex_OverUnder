#ifndef task_h
#define task_h

#include "definitions_and_declarations.h"

void intake(float v){
    ITK.spin(fwd, 120*v, voltageUnits::mV);
}
#endif