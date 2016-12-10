#include "musiccommons.h"
#include <algorithm>
MusicCommons::MusicCommons()
{
    //Create all the keys and the modes
    for(int i = 0; i < TOTAL_KEYS; i++){
        Keys.push_back(Keys_text[i]);
        KeysWithoutSharp.push_back(Keys_without_sharp_text[i]);
    }

    for(int mode = 0; mode < TOTAL_MODES; mode++){
        Modes[mode] = Mode(mode);
    }
}

bool MusicCommons::noteFoundInScale(std::string note){
    for(auto noteIt : Scale){
        if(noteIt.first == note){
            return true;
        }
    }
    return false;
}

std::string MusicCommons::getScaleText(){
    std::string scaleText;
    for(auto key : Scale)
    {
        scaleText.append(key.first);
        scaleText.append(key.second);
        scaleText.append(" ");
    }
    Scale.clear();
    return scaleText;
}

void MusicCommons::generateScaleByKey(int mode, int key){
    std::vector<std::string> KeysCopy = Keys;
    std::vector<std::string> KeysWithoutSharpCopy = KeysWithoutSharp;

    Scale.clear();
    printf(" mode %d key %d \n", mode, key);

    auto foundKey = std::find(KeysCopy.begin(), KeysCopy.end(), Keys_text[key]);
    if(foundKey != KeysCopy.end()){
        printf("%s\n", Keys_text[key].c_str());
        while(*KeysCopy.begin() != Keys_text[key]){
            std::rotate(KeysCopy.begin(), KeysCopy.begin() + 1, KeysCopy.end());
            //Do it also in the ones without sharp
            std::rotate(KeysWithoutSharpCopy.begin(), KeysWithoutSharpCopy.begin() + 1, KeysWithoutSharpCopy.end());
        }
        for (auto key : KeysCopy){
            printf(" %s", key.c_str());
        }
        printf("\n");
        for (auto key : KeysWithoutSharpCopy){
            printf(" %s", key.c_str());
        }
        printf("\n");
        //Now we are ready to generate the scale
        auto foundMode = Modes.find(mode);
        if(foundMode != Modes.end()){
            printf("%s\n", Modes_text[mode].c_str());
            unsigned long totalSemiTones = 0;
            printf("First one is %s \n", KeysCopy[0].c_str());
            if(KeysCopy[0].size() != KeysWithoutSharpCopy[0].size()){//We are in a sharp!
                Scale.push_back(std::make_pair(KeysWithoutSharpCopy[0],"#"));
            }else{
                Scale.push_back(std::make_pair(KeysWithoutSharpCopy[0], ""));
            }
            //Now start going through the scale with the semiTones found
            for(auto semiTonesToNextNote : *foundMode->second.getSemiTones()){
                totalSemiTones += semiTonesToNextNote;
                if(totalSemiTones ==12) totalSemiTones =0;
                printf("Total semitones %zu Next one is %s \n", totalSemiTones, KeysCopy[totalSemiTones].c_str());
                if(KeysCopy[totalSemiTones].size() != KeysWithoutSharpCopy[totalSemiTones].size()){//We are in a sharp!
                    if(noteFoundInScale(KeysWithoutSharpCopy[totalSemiTones])){
                        printf("Same note again, will unclude a b!");
                        if(totalSemiTones == 0){
                            Scale.push_back(std::make_pair(std::string(&KeysCopy[totalSemiTones][0]), std::string(&KeysCopy[totalSemiTones][1])));
                        }else{
                            Scale.push_back(std::make_pair(KeysWithoutSharpCopy[totalSemiTones + 1], "b"));
                        }
                    }else{
                        Scale.push_back(std::make_pair(KeysWithoutSharpCopy[totalSemiTones], "#"));
                    }
                }else{
                    Scale.push_back(std::make_pair(KeysWithoutSharpCopy[totalSemiTones], ""));
                }
            }
        }else{
            printDebug("Received a wrong key that was not found");
        }
    }else{
        printDebug("Received a wrong key that was not found");
    }
}
