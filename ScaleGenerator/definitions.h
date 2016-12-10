#ifndef DEFINITIONS_H
#define DEFINITIONS_H
#include <fstream>
#include <string>
#include <iostream>

static const int WHOLE_STEP = 2;
static const int HALF_STEP = 1;

enum Modes{
    MODE_IONIAN = 0,
    MODE_DORIAN,
    MODE_PHRYGIAN,
    MODE_LYDIAN,
    MODE_MIXOLYDIAN,
    MODE_AEOLIAN,
    MODE_LOCRIAN,
    TOTAL_MODES
};

static const std::string Modes_text[TOTAL_MODES] = {"Ionian (Major)", "Dorian", "Phrygian", "Lydian", "Mixolydian", "Minor (Aeolian)", "Locrian"};

enum KEYS{
    KEY_A = 0,
    KEY_AS,
    KEY_B,
    KEY_C,
    KEY_CS,
    KEY_D,
    KEY_DS,
    KEY_E,
    KEY_F,
    KEY_FS,
    KEY_G,
    KEY_GS,
    TOTAL_KEYS
};

static const std::string Keys_text[TOTAL_KEYS] ={"A","A#","B","C","C#","D","D#","E","F","F#","G","G#"};
static const std::string Keys_without_sharp_text[TOTAL_KEYS] ={"A","A","B","C","C","D","D","E","F","F","G","G"};

static void printDebug(std::string str){
    std::ofstream logfile("log.txt");
    logfile << "[DEBUG] ";
    logfile << str;
    logfile.close();
}

#endif // DEFINITIONS_H
