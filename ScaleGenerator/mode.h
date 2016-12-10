#ifndef MODE_H
#define MODE_H
#include <vector>
#include "definitions.h"

class Mode
{
    std::vector<unsigned long> semiTones;
public:
    Mode(){};
    Mode(int mode);
    std::vector<unsigned long>* getSemiTones();
};

#endif // MODE_H
