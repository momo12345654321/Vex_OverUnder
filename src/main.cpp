#include "interfaces_and_devices.h"
#include "definitions_and_declarations.h"
#include "autonomous.h"
#include "tasks.h"

using namespace vex;


void auton(void){
    intake(-100);
    timerMove(850,100);
    //timerMove(100, 0);
    timerTurnMove(180,150, -1);
    intake(100);
    timerMove(200, 175);
    timerMove(100, -150);
    wait(900);
    intake(100);
    timerMove(200, 175);
    wait(900);
    timerMove(300,-200);
    intake(-100);
    timerTurnMove(400,87.5, -1);
    timerMove(350,150);
    timerTurnMove(400,100, -1);
    timerMove(400, 150);
    

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
