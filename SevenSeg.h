//
// Created by i2011430 on 2022/05/15.
//

#ifndef DISPLAY_TIMER_SEVENSEG_H
#define DISPLAY_TIMER_SEVENSEG_H

class SevenSeg {
private:
    int win{};
    int scale{};
    int color{};

    void resize(double* xlist, double* ylist, int x, int y) const;
    void drawA(int x, int y) const;
    void drawB(int x, int y) const;
    void drawC(int x, int y) const;
    void drawD(int x, int y) const;
    void drawE(int x, int y) const;
public:
    SevenSeg(int win, int scale, int color);

};


#endif //DISPLAY_TIMER_SEVENSEG_H
