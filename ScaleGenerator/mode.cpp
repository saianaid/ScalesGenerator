#include "mode.h"
#include <stdio.h>

Mode::Mode(int mode)
{
    switch (mode) {
    case MODE_AEOLIAN:
        semiTones = {2, 1, 2, 2, 1, 2, 2};//WHWWHWW
        break;
    case MODE_DORIAN:
        semiTones = {2, 1, 2, 2, 2, 1, 2};//WHWWWHW
        break;
    case MODE_IONIAN:
        semiTones = {2, 2, 1, 2, 2, 2, 1};//WWHWWWH
        break;
    case MODE_LOCRIAN:
        semiTones = {1, 2, 2, 1, 2, 2, 2};//HWWHWWW
        break;
    case MODE_LYDIAN:
        semiTones = {2, 2, 2, 1, 2, 2, 1};//WWWHWWH
        break;
    case MODE_MIXOLYDIAN:
        semiTones = {2, 2, 1, 2, 2, 1, 2};//WWHWWHW
        break;
    case MODE_PHRYGIAN:
        semiTones = {1, 2, 2, 2, 1, 2, 2};//HWWWHWW
        break;
    }
    int sum = 0;
    for(auto it : semiTones){
        sum += it;
    }
    if (sum != 12){
        char buff[512];
        snprintf(buff, sizeof(buff), "Mode %s semiTones added do not add to 12", Modes_text[mode].c_str());
        std::string buffAsStdStr = buff;
        printDebug(buffAsStdStr);
    }
}

std::vector<unsigned long>* Mode::getSemiTones(){
    return &semiTones;
}
