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
    void drawF(int x, int y) const;
    void drawG(int x, int y) const;
    void drawH(int x, int y) const;
    void draw1(int x, int y) const;
    void draw2(int x, int y) const;
    void draw3(int x, int y) const;
    void draw4(int x, int y) const;
    void draw5(int x, int y) const;
    void draw6(int x, int y) const;
public:
    SevenSeg(int win, int scale, int color);

    void drawpart(int x, int y, int a, int b, int c, int d, int e, int f, int g, int h) const;
};


#endif //DISPLAY_TIMER_SEVENSEG_H
