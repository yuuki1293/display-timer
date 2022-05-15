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

    void drawA(int x, int y) const;
    void drawB(int x, int y) const;
public:
    SevenSeg(int win, int scale, int color);

};


#endif //DISPLAY_TIMER_SEVENSEG_H
