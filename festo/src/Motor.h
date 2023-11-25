//
// Created by flori on 25.11.2023.
//

#ifndef PRAKTIKUMPR2_MOTOR_H
#define PRAKTIKUMPR2_MOTOR_H
#include "../festo-source/FestoTransferSystem.h"

class Motor {
private:
    FestoTransferSystem *festo;

public:
    explicit Motor(FestoTransferSystem *festo); //konstruktor
    virtual ~Motor(); //destruktor

    void motorStop();
    void motorSlowLeft();
    void motorFastLeft();
    void motorSlowRight();
    void motorFastRight();
};

#endif //PRAKTIKUMPR2_MOTOR_H
