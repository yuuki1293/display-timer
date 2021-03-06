//
// Created by i2011430 on 2022/05/15.
//

#ifndef DISPLAY_TIMER_SEVENSEG_H
#define DISPLAY_TIMER_SEVENSEG_H

class SevenSeg {
private:
    int win{};
    int scale{};

    void resize(double* xlist, double* ylist, int x, int y) const;
    void drawA(int x, int y) const;
    void drawB(int x, int y) const;
    void drawC(int x, int y) const;
    void drawD(int x, int y) const;
    void drawE(int x, int y) const;
    void drawF(int x, int y) const;
    void drawG(int x, int y) const;
    void draw0(int x, int y) const;
    void draw1(int x, int y) const;
    void draw2(int x, int y) const;
    void draw3(int x, int y) const;
    void draw4(int x, int y) const;
    void draw5(int x, int y) const;
    void draw6(int x, int y) const;
    void draw7(int x, int y) const;
    void draw8(int x, int y) const;
    void draw9(int x, int y) const;
public:
    SevenSeg();
    SevenSeg(int win, int scale);

    void drawpart(int x, int y, int a, int b, int c, int d, int e, int f, int g) const;

    ///<summary>num is a number from 0 to 9</summary>
    void draw(int x, int y, int num) const;

    void draw(int x, int y, int num, int digit, int zerofill = false) const;
};


#endif //DISPLAY_TIMER_SEVENSEG_H
