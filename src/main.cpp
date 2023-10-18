#include "interfaces_and_devices.h"
#include "definitions_and_declarations.h"
#include "autonomous.h"

using namespace vex;


void auton(void){
    timerMove(100,630);

}

void usercontrol(void){
    float rota=0.65;
    while (1){
        LA.spin(fwd, 120 * (-Ch3-Ch1*rota), voltageUnits::mV);
        LB.spin(fwd, 120 * (-Ch3-Ch1*rota), voltageUnits::mV);
        LC.spin(fwd, 120 * (-Ch3-Ch1*rota), voltageUnits::mV);
        RA.spin(fwd, 120 * (Ch3-Ch1*rota), voltageUnits::mV);
        RB.spin(fwd, 120 * (Ch3-Ch1*rota), voltageUnits::mV);
        RC.spin(fwd, 120 * (Ch3-Ch1*rota), voltageUnits::mV);
        
        ITK.spin(fwd,12000*(R1-R2), voltageUnits::mV);

        elev1.spin(fwd, 12000*(-L1+L2), voltageUnits::mV);
        elev2.spin(fwd, 12000*(L1-L2), voltageUnits::mV);



        Brain.Screen.printAt(10,20,"hello world");
        Brain.Screen.printAt(10,20," %d ",Contrler.Axis3.position(percent));
        wait(10, msec);
    }
}

int main() {
    Competition.autonomous(auton);
    Competition.drivercontrol(usercontrol);
    //pre_auton();
    while(true){
        wait(100, msec);
    }  
}
