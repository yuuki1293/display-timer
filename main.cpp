#include <iostream>
#include "Scenes.h"

int main() {
    auto scenes = new Scenes();
    scenes->resetTimer(10000);
    std::cout << "finish." << std::endl;
    while(true); // 正常終了するとバグが発生する
}