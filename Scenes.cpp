//
// Created by i2011430 on 2022/05/12.
//

#include "Scenes.h"
#include <eggxlib.h>
#include <valarray>
#include <chrono>
#include "SevenSeg.h"
#include <string>

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

    mainSeg = SevenSeg(win, 15);
    subSeg = SevenSeg(win, 9);
}

Scenes::Scenes(const std::string& font_color, const std::string& back_color) : Scenes(){
    eggx_newcolor(win,font_color.c_str());
    eggx_gsetbgcolor(win,back_color.c_str());
    eggx_gclr(win);
}

Scenes::~Scenes() {
    eggx_gclose(win);
}

void Scenes::flush() const {
    eggx_copylayer(win, 1, 0);
}

void Scenes::setupTimer(int millsec,int digit) {
    mainSeg.draw(400,200,millsec/1000,digit);
    subSeg.draw(1200,410,millsec/10 % 100,2, true);
    eggx_fillcirc(win,1125,700,30,30);

    flush();
}

void Scenes::countdownTimer(int millsec, int digit) {
    while(true) {
        time_point<Clock> now = Clock::now();
        milliseconds diff = duration_cast<milliseconds>(now - start);
        if(eggx_ggetch() >= 0) break;
        if(diff.count() >= millsec){
            eggx_gclr(win);
            mainSeg.draw(600, 300, 0, digit);
            subSeg.draw(130, 40, 0, 2, true);
            flush();
            break;
        }
        eggx_gclr(win);
        mainSeg.draw(400, 200, (int)(millsec - diff.count()) / 1000, digit);
        //subSeg.draw(1200, 410, ((millsec - (int)diff.count()) / 10) % 100, 2, true);
        //eggx_fillcirc(win,1125,700,30,30);
        flush();
    }
    startTimer(digit);
}

void Scenes::startTimer(int digit) {
    start = Clock::now();
    while(true){
        time_point<Clock> now = Clock::now();
        milliseconds diff = duration_cast<milliseconds>(now - start);
        if(eggx_ggetch() >= 0) break;
        eggx_gclr(win);
        mainSeg.draw(400, 200, (int)diff.count() / 1000, digit);
        subSeg.draw(1200, 410, (int)diff.count() / 10 % 100, 2, true);
        eggx_fillcirc(win,1125,700,30,30);
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
    countdownTimer(millsec, digit);
}