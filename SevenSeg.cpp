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

void SevenSeg::drawG(int x, int y) const {
    double xlist[6] = {3,  5,  15, 17, 15, 5};
    double ylist[6] = {18, 16, 16, 18, 20, 20};
    resize(xlist, ylist, x, y);
    eggx_fillpoly(win, xlist, ylist, 6, 0);
}

void SevenSeg::drawH(int x, int y) const {

}

void SevenSeg::drawpart(int x, int y, int a, int b, int c, int d, int e, int f, int g, int h) const {
    if (a) drawA(x, y);
    if (b) drawB(x, y);
    if (c) drawC(x, y);
    if (d) drawD(x, y);
    if (e) drawE(x, y);
    if (f) drawF(x, y);
    if (g) drawG(x, y);
    //if (h) drawH(x, y);
}

void SevenSeg::draw0(int x, int y) const {
    drawpart(x, y, 1, 1, 1, 1, 1, 1, 0, 0);
}

void SevenSeg::draw1(int x, int y) const {
    drawpart(x, y, 0, 1, 1, 0, 0, 0, 0, 0);
}

void SevenSeg::draw2(int x, int y) const {
    drawpart(x, y, 1, 1, 0, 1, 1, 0, 1, 0);
}

void SevenSeg::draw3(int x, int y) const {
    drawpart(x, y, 1, 1, 1, 1, 0, 0, 1, 0);
}

void SevenSeg::draw4(int x, int y) const {
    drawpart(x, y, 0, 1, 1, 0, 0, 1, 1, 0);
}

void SevenSeg::draw5(int x, int y) const {
    drawpart(x, y, 1, 0, 1, 1, 0, 1, 1, 0);
}

void SevenSeg::draw6(int x, int y) const {
    drawpart(x, y, 1, 0, 1, 1, 1, 1, 1, 0);
}

void SevenSeg::draw7(int x, int y) const {
    drawpart(x, y, 1, 1, 1, 0, 0, 0, 0, 0);
}

void SevenSeg::draw8(int x, int y) const {
    drawpart(x, y, 1, 1, 1, 1, 1, 1, 1, 0);
}

void SevenSeg::draw9(int x, int y) const {
    drawpart(x, y, 1, 1, 1, 1, 1, 0, 1, 0);
}

void SevenSeg::draw(int x, int y, int num) const {
    switch (num) {
        case 0:
            draw0(x, y);
            break;
        case 1:
            draw1(x, y);
            break;
        case 2:
            draw2(x, y);
            break;
        case 3:
            draw3(x, y);
            break;
        case 4:
            draw4(x, y);
            break;
        case 5:
            draw5(x, y);
            break;
        case 6:
            draw6(x, y);
            break;
        case 7:
            draw7(x, y);
            break;
        case 8:
            draw8(x, y);
            break;
        case 9:
            draw9(x, y);
            break;
        default:
            break;
    }
}
