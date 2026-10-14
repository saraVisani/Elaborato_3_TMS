#include "Globals.h"

bool matchHardwareType(HardwareType t1, String t2) {
    HardwareType ht;
    if(t2 == "LED") ht = LED;
    else if(t2 == "S_DDD") ht = S_DDD;
    else return false;

    return t1 == ht;
}

bool isNotHardwareType(HardwareType t1, String t2) {
    return !matchHardwareType(t1, t2);
}

bool matchTaskType(TaskType t1, String t2) {
    TaskType tt;
    if(t2 == "T_INPUTOUTPUT") {
        tt = T_INPUTOUTPUT;
    } else if(t2 == "T_CHECKCONNECTION") {
        tt = T_CHECKCONNECTION;
    } else if(t2 == "T_MEASURELEVEL") {
        tt = T_MEASURELEVEL;
    } else {
        return false;
    }
    return (t1 == tt);
}

bool isNotTaskType(TaskType t1, String t2) {
    return !(matchTaskType(t1, t2));
}

ProblemState State::systemState = OK;
float State::levelWater = 0.0f;

void State::setSystemState(ProblemState newState) { systemState = newState; }
bool State::matchSystemState(ProblemState state) { return systemState == state; }
bool State::isNotSystemState(ProblemState state) { return systemState != state; }

ProblemState State::stringToSystemState(const char* stateString) {
    if (strcasecmp(stateString, "ok") == 0) return OK;
    if (strcasecmp(stateString, "unconnected") == 0) return UNCONNECTED;
    return OK;
}

String State::systemStateToString(ProblemState state) {
    switch (state) {
        case OK: return "OK";
        case UNCONNECTED: return "Unconnected";
    }
    return "Unknown";
}

String State::currentSystemStateString() { return systemStateToString(systemState); }
