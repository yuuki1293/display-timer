#include <iostream>
#include <unistd.h>
#include "Scenes.h"
#include<ctime>

int main() {
    auto scenes = new Scenes();
    scenes->resetTimer(10000);
    printf("finish.\n");
    //sleep(3);
    while(true);
}