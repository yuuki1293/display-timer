//
// Created by i2011430 on 2022/05/12.
//

#ifndef DISPLAY_TIMER_SCENES_H
#define DISPLAY_TIMER_SCENES_H

#include "SevenSeg.h"
#include <chrono>
#include <string>

using Clock = std::chrono::steady_clock;
using std::chrono::time_point;

class Scenes {
private:
    SevenSeg mainSeg;
    SevenSeg subSeg;
    time_point<Clock> start;
public:
    int win{};
    int height{};
    int width{};
private:
    void flush() const;

    void setupTimer(int millsec, int digit);
    void countdownTimer(int millsec, int digit);
    void startTimer(int digit);
public:
    Scenes();
    Scenes(const std::string& font_color, const std::string& back_color);
    ~Scenes();

    ///<summary>タイマーをリセットし、キーが押されるまで待機する</summary>
    ///<param name="millsec">タイマーの時間(ミリ秒)</param>
    void resetTimer(int millsec);
};


#endif //DISPLAY_TIMER_SCENES_H
