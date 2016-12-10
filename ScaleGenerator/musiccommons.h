#ifndef MUSICCOMMONS_H
#define MUSICCOMMONS_H

#include <string>
#include <vector>
#include <map>
#include "mode.h"


class MusicCommons
{
    std::vector<std::string> Keys;
    std::vector<std::string> KeysWithoutSharp;
    std::map<int, Mode> Modes;
    bool noteFoundInScale(std::string note);
    std::vector<std::pair<std::string, std::string> > Scale;

public:
    MusicCommons();

    void generateScaleByKey(int mode, int key);
    std::string getScaleText();
};


#endif // MUSICCOMMONS_H
