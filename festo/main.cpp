/**
 * @author Niklas Dathe
 * @author Florian Czorniuk
 * @date   21.11.2023
 */

#include <iostream>
#include "TimeHelper.h"
#include "FestoTransferSystem.h"
#include "FSM.h"
#include "Motor.h"

using namespace std;

#define WAIT 1000
#define LAP 1

void ampelschaltung(FestoTransferSystem *);
void emergency(FestoTransferSystem *,bool *);




int main() {
    FestoTransferSystem festo;
    FSM fsm;
    cout << "Start" << endl;
    //Motor motor(&festo);

    //Boot
    for (int i = 0; i < LAP; ++i) {
        ampelschaltung(&festo);
    }

    //Main Code
    while(fsm.running) {
        festo.updateSensors();

        fsm.evalStates();

        fsm.evalTransition();
        emergency(&festo, &fsm.running); //E-Break

        festo.updateActuators();
    }
    return 0;

}

void emergency(FestoTransferSystem *festo, bool * running){
    if(festo->switchEmergency.isPressed()){
        Motor(festo).motorStop();
        festo->feedSeparator.close();
        festo->lampRed.switchOff();
        festo->lampYellow.switchOff();
        festo->lampGreen.switchOff();
        festo->ledQ1.switchOff();
        festo->ledQ2.switchOff();
        festo->ledStart.switchOff();
        festo->ledReset.switchOff();
        cout << "Emergency Triggered" << endl;
        *running = false;
    }
}


void ampelschaltung(FestoTransferSystem *festo){
    //new
    festo->updateSensors();
    festo->lampRed.switchOn();
    festo->lampYellow.switchOff();
    festo->lampGreen.switchOff();
    festo->updateActuators();
    sleepForMS(WAIT);

    festo->updateSensors();
    festo->lampRed.switchOn();
    festo->lampYellow.switchOn();
    festo->lampGreen.switchOff();
    festo->updateActuators();
    sleepForMS(WAIT);

    festo->updateSensors();
    festo->lampRed.switchOff();
    festo->lampYellow.switchOff();
    festo->lampGreen.switchOn();
    festo->updateActuators();
    sleepForMS(WAIT);

    festo->updateSensors();
    festo->lampRed.switchOff();
    festo->lampYellow.switchOn();
    festo->lampGreen.switchOff();
    festo->updateActuators();
    sleepForMS(WAIT);

}

