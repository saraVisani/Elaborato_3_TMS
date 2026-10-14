#ifndef __HARDWARE__
#define __HARDWARE__

#include "Globals.h"
#include "Util/Hardware/Api/ILed.h"
#include "Util/Hardware/Api/ISddd.h"

extern ILed* ledOK;
extern ILed* ledAlarm;
extern ISddd* sensorDdd;

class Hardware {
public:
    virtual void initAllHardware() = 0;
};

extern Hardware* hw;

#endif
