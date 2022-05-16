//
// Created by i2011430 on 2022/05/12.
//

#include "Scenes.h"
#include <eggxlib.h>
#include <valarray>
#include <iostream>
#include <chrono>
#include "SevenSeg.h"

using Clock = std::chrono::steady_clock;
using std::chrono::time_point;
using std::chrono::duration_cast;
using std::chrono::milliseconds;
using namespace std::literals::chrono_literals;

Scenes::Scenes() {
    eggx_gsetinitialattributes(DISABLE, BOTTOM_LEFT_ORIGIN);
    eggx_gsetinitialattributes(DISABLE, SCROLLBAR_INTERFACE);
    eggx_gsetinitialattributes(DISABLE, OVERRIDE_REDIRECT);
    eggx_ggetdisplayinfo(nullptr, &width, &height);
    eggx_gsetnonblock(false);
    win = eggx_gopen(width, height);
    eggx_layer(win, 0, 1);
    eggx_gclr(win);

    mainSeg = SevenSeg(win, 7);
    subSeg = SevenSeg(win, 4);
}

Scenes::~Scenes() {
    eggx_gclose(win);
}

void Scenes::flush() const {
    eggx_copylayer(win, 1, 0);
}

void Scenes::setupTimer(int millsec,int digit) {
    mainSeg.draw(100,50,millsec/1000,digit);
    subSeg.draw(150,70,(millsec/100) % 100,2);

    flush();
    stop = false;
}

void Scenes::startTimer(int millsec, int digit) {
    while(true) {
        eggx_msleep(100);
        time_point<Clock> now = Clock::now();
        milliseconds diff = duration_cast<milliseconds>(now - start);
        if(eggx_ggetch() >= 0) stop = true;
        if(diff.count() >= millsec || stop) break;
        eggx_gclr(win);
        mainSeg.draw(100, 50, (int)(millsec - diff.count()) / 1000, digit);
        flush();
    }
}

void Scenes::resetTimer(int millsec) {
    int digit = (int)log10(millsec) - 2;
    setupTimer(millsec, digit);
    eggx_ggetch();
    eggx_gsetnonblock(true);
    while (eggx_ggetch() < 0);
    start = Clock::now();
    startTimer(millsec, digit);
}