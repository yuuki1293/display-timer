//
// Created by i2011430 on 2022/05/12.
//

#include "Scenes.h"
#include <eggxlib.h>
#include <cstdio>
#include "SevenSeg.h"

Scenes::Scenes() {
    eggx_gsetinitialattributes(DISABLE, BOTTOM_LEFT_ORIGIN);
    eggx_gsetinitialattributes(DISABLE, SCROLLBAR_INTERFACE);
    eggx_gsetinitialattributes(DISABLE, OVERRIDE_REDIRECT);
    eggx_ggetdisplayinfo(nullptr, &width, &height);
    win = eggx_gopen(width, height);
    eggx_layer(win, 0, 1);
    eggx_gclr(win);

    mainSeg = new SevenSeg(win, 5, 0xFFFFFF);
}

Scenes::~Scenes() {
    eggx_gclose(win);
}

void Scenes::flush() const {
    eggx_copylayer(win, 1, 0);
}

void Scenes::setupTimer(int millsec) {
    for (int i = 0; i <= 99; ++i) {
        eggx_gclr(win);
        mainSeg->draw(100, 100, i, 2, 1);
        flush();
        eggx_msleep(100);
    }
    flush();
    stop = false;
}