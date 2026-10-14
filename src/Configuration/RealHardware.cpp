#include "RealHardware.h"

#include "./Util/Hardware/Component.h"
#include "./Util/Hardware/Real/Led/Led.h"
#include "./Util/Hardware/Real/S_DDD/Sddd.h"

Hardware* hw = nullptr;

Led ledOKInstance;
Led ledAlarmInstance;
Sddd sensorDddInstance;

ILed* ledOK = &ledOKInstance;
ILed* ledAlarm = &ledAlarmInstance;
ISddd* sensorDdd = &sensorDddInstance;

RealHardware::RealHardware() {
    hw = this;
}

void RealHardware::initAllHardware() {
    ledOK->init(L_OK);
    ledAlarm->init(L_ALARM);
    sensorDdd->init();
}

static RealHardware realHw;
