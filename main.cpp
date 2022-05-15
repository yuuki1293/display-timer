#include <iostream>
#include <unistd.h>
#include "Scenes.h"

int main() {
    auto scenes = new Scenes();
    scenes->setupTimer(1000);
    sleep(10);
    delete scenes;
}