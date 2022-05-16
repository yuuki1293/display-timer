#include "Scenes.h"

int main() {
    auto scenes = new Scenes("#6eecff","#3c3f41");
    scenes->resetTimer(10000);
    while(true); // 正常終了するとバグが発生する
}