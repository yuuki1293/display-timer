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
    double xlist[6] = {3, 5, 15, 17, 15, 5};
    double ylist[6] = {2, 0, 0 , 2 , 4 , 4};
    resize(xlist, ylist, x, y);
    eggx_fillpoly(win, xlist, ylist, 6, 0);
}

void SevenSeg::drawB(int x, int y) const {
    double xlist[6] = {18, 20, 20, 18, 16, 16};
    double ylist[6] = {3,  5,  15, 17, 15, 5};
    resize(xlist, ylist, x, y);
    eggx_fillpoly(win, xlist, ylist, 6, 0);
}

void SevenSeg::drawC(int x, int y) const {
    double xlist[6] = {18, 20, 20, 18, 16, 16};
    double ylist[6] = {19, 21, 31, 33, 31, 21};
    resize(xlist, ylist, x, y);
    eggx_fillpoly(win, xlist, ylist, 6, 0);
}

void SevenSeg::drawD(int x, int y) const {
    double xlist[6] = {3,  5,  15, 17, 15, 5};
    double ylist[6] = {34, 32, 32, 34, 36, 36};
    resize(xlist, ylist, x, y);
    eggx_fillpoly(win, xlist, ylist, 6, 0);
}

void SevenSeg::drawE(int x, int y) const {
    double xlist[6] = {2,  4,  4,  2,  0,  0};
    double ylist[6] = {19, 21, 31, 33, 31, 21};
    resize(xlist, ylist, x, y);
    eggx_fillpoly(win, xlist, ylist, 6, 0);
}

void SevenSeg::drawF(int x, int y) const {
    double xlist[6] = {2,  4,  4,  2,  0,  0};
    double ylist[6] = {3,  5,  15, 17, 15, 5};
    resize(xlist, ylist, x, y);
    eggx_fillpoly(win, xlist, ylist, 6, 0);
}