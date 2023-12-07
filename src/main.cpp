#include "interfaces_and_devices.h"
#include "definitions_and_declarations.h"
#include "autonomous.h"
#include "tasks.h"

using namespace vex;


void far_auton(void){

    intake(-100);
    timerMove(1160,80);
    timerMove(50,-50);
    wait(200);
    timerTurnMove(375,45, -1);
    intake(100);
    wait(300);
    timerMove(245, 80);
    wait(200);
    timerMove(100, -80);
    timerMove(50, 50);
    wait(200);
    intake(100);
    timerMove(250, 80);
    wait(200);
    timerMove(120,-80);
    wait(200);
    intake(-100);
    timerTurnMove(470, 52.5, -1);
    wait(200);
    timerMove(400,80);
    wait(200);
    timerMove(100,-80);
    wait(200);
    timerTurnMove(605, 55, -1);
    timerMove(450, 80);
    intake(100);
    wait(200);
    timerMove(225, 100);
    wait(200);
    timerMove(100, -80);
    wait(200);
    timerMove(225, 100);
    wait(200);
    intake(0);
    timerMove(200, -100);
    
    
    
    
}
// void far_auton1(void){
//     timerMove(400,-350); 
//     wait(500);
//     timerMove(350,-100);
//     wait(200);
//     timerMove(250, 150);
//     wait(200);
//     timerTurnMove(350, 150, 1);
// }

void near_auton(void) {
    timerMove(450,-100);
    wait(200);
    timerMove(350, 80);
    wait(200);
    timerMove(450,-100);
    wait(200);
    timerMove(350, 80);



    

    
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

        elev1.spin(fwd, 12000*(L1-L2), voltageUnits::mV);
        elev2.spin(fwd, 12000*(-L1+L2), voltageUnits::mV);



        Brain.Screen.printAt(10,20,"hello world");
        Brain.Screen.printAt(10,20," %d ",Contrler.Axis3.position(percent));
        wait(10, msec);

        if(A){
            sol.set(true);//1 bool
        }
    
        if(B){
            sol.set(false);//0
        }
    }
}

int main() {
    Competition.autonomous(far_auton);
    Competition.drivercontrol(usercontrol);
    //pre_auton();
    while(true){
        wait(100, msec);
    }  
}