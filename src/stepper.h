#pragma once

class Stepper
{
    public:
        Stepper(int in1,int in2, int in3, int in4);
        void step();
        void dir(bool clockwise);
    private:
        int _step;
        int _dir;
        int _in1;
        int _in2;
        int _in3;
        int _in4;
};