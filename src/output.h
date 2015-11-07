#ifndef OUTPUT_H
#define OUTPUT_H

class Output {
    private:
    
    protected:
        int dataPin;
        int clockPin;
        int latchPin;

    public:
        Output(const int &, const int &, const int &);
        ~Output();
        virtual void myShiftOut(const unsigned char &) = 0;
        virtual void toggleLatch() = 0;
};

#endif
