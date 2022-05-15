//
// Created by i2011430 on 2022/05/15.
//

#include "SevenSeg.h"
#include <eggxlib.h>

SevenSeg::SevenSeg(int win, int scale, int color) {
    this->win = win;
    this->scale = scale;
    this->color = color;
}

void SevenSeg::resize(double *xlist, double *ylist, int x, int y) const {
    for (int i = 0; i < 6; i++) {
        xlist[i] = (xlist[i] + x) * scale;
        ylist[i] = (ylist[i] + y) * scale;
    }
}

void SevenSeg::drawA(int x, int y) const {
    double xlist[6] = {4, 6, 16, 18, 16, 6};
    double ylist[6] = {2, 0, 0 , 2 , 4 , 4};
    for (int i = 0; i < 6; i++) {
        xlist[i] = (xlist[i] + x) * scale;
        ylist[i] = (ylist[i] + y) * scale;
    }
    eggx_fillpoly(win, xlist, ylist, 6, 0);
}

void SevenSeg::drawB(int x, int y) const {

}