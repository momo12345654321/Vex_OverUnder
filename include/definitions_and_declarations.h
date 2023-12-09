#ifndef definition_h
#define definition_h

#include "interfaces_and_devices.h"
using namespace vex;

#define Ch1  Contrler.Axis1.position(percent)
#define Ch2  Contrler.Axis2.position(percent)
#define Ch3  Contrler.Axis3.position(percent)
#define Ch4  Contrler.Axis4.position(percent)

#define R1  Contrler.ButtonR1.pressing()
#define R2  Contrler.ButtonR2.pressing()
#define L1  Contrler.ButtonL1.pressing()
#define L2  Contrler.ButtonL2.pressing()

#define BA Contrler.ButtonA.pressing() 
#define BB Contrler.ButtonB.pressing() 
#define BX Contrler.ButtonX.pressing()
#define BY Contrler.ButtonY.pressing() 



#endif  