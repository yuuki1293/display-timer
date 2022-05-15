#include <iostream>
#include <unistd.h>
#include "Scenes.h"

int main() {
    auto scenes = new Scenes();
    scenes->setupTimer(1000);
    printf("finish.\n");
    sleep(3);
    delete scenes;
}