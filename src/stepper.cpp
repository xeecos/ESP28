#include "stepper.h"
#include <Arduino.h>
Stepper::Stepper(int in1, int in2, int in3, int in4)
{
    _dir = true;
    pinMode(in1, OUTPUT);
    pinMode(in2, OUTPUT);
    pinMode(in3, OUTPUT);
    pinMode(in4, OUTPUT);
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
    digitalWrite(in3, LOW);
    digitalWrite(in4, LOW);
    _in1 = in1;
    _in2 = in2;
    _in3 = in3;
    _in4 = in4;
    _step = -1;
}
void Stepper::step()
{
    _step += _dir ? 1 : -1;
    if (_step < 0)
    {
        _step = 7;
    }
    if (_step > 7)
    {
        _step = 0;
    }
    if (_step == 0)
    {
        digitalWrite(_in1, HIGH);
        digitalWrite(_in2, LOW);
        digitalWrite(_in3, LOW);
        digitalWrite(_in4, LOW);
    }
    else if (_step == 1)
    {
        digitalWrite(_in1, HIGH);
        digitalWrite(_in2, HIGH);
        digitalWrite(_in3, LOW);
        digitalWrite(_in4, LOW);
    }
    else if (_step == 2)
    {
        digitalWrite(_in1, LOW);
        digitalWrite(_in2, HIGH);
        digitalWrite(_in3, LOW);
        digitalWrite(_in4, LOW);
    }
    else if (_step == 3)
    {
        digitalWrite(_in1, LOW);
        digitalWrite(_in2, HIGH);
        digitalWrite(_in3, HIGH);
        digitalWrite(_in4, LOW);
    }
    else if (_step == 4)
    {
        digitalWrite(_in1, LOW);
        digitalWrite(_in2, LOW);
        digitalWrite(_in3, HIGH);
        digitalWrite(_in4, LOW);
    }
    else if (_step == 5)
    {
        digitalWrite(_in1, LOW);
        digitalWrite(_in2, LOW);
        digitalWrite(_in3, HIGH);
        digitalWrite(_in4, HIGH);
    }
    else if (_step == 6)
    {
        digitalWrite(_in1, LOW);
        digitalWrite(_in2, LOW);
        digitalWrite(_in3, LOW);
        digitalWrite(_in4, HIGH);
    }
    else if (_step == 7)
    {
        digitalWrite(_in1, HIGH);
        digitalWrite(_in2, LOW);
        digitalWrite(_in3, LOW);
        digitalWrite(_in4, HIGH);
    }
}
void Stepper::dir(bool clockwise)
{
    _dir = clockwise;
}