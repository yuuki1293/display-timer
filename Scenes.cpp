//
// Created by i2011430 on 2022/05/12.
//

#include "Scenes.h"
#include <eggxlib.h>
#include <cstdio>

Scenes::Scenes() {
    eggx_gsetinitialattributes(DISABLE, BOTTOM_LEFT_ORIGIN);
    eggx_ggetdisplayinfo(nullptr,&width,&height);
    win = eggx_gopen(width,height);
    eggx_layer(win,0,1);
    eggx_gclr(win);
}

Scenes::~Scenes() {
    printf("%d\n",win);
    eggx_gclose(win);
    printf("Scenes closed.\n");
}

void Scenes::flush() const {
    eggx_copylayer(win,1,0);
}

void Scenes::draw7seg(int x, int y, int num) {

}

void Scenes::setupTimer(int millsec){
    eggx_drawstr(win,100,100,12,0.0,"Hello, World!");
    flush();
    stop = false;
}