#ifndef OUTPUT_H
#define OUTPUT_H

class Output {
    private:
        int dataPin;
        int clockPin;
        int latchPin;

    public:
        Output(const int &, const int &, const int &);
        ~Output();
        virtual void shiftOut(const unsigned char &) = 0;
};

#endif
