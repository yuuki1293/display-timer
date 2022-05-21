#include "Scenes.h"
#include<eggxlib.h>

int main() {
    auto scenes = new Scenes("#6eecff","#3c3f41");
    while(true) {
        scenes->resetTimer(10000);
        eggx_gsetnonblock(false);
        eggx_ggetch();
    }
    while(true); // 正常終了するとバグが発生する
}