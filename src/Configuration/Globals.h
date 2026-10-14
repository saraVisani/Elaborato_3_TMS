#ifndef GLOBALS
#define GLOBALS

#include "ArduinoCompability.h"

/* ---- PINS FOR HARDWARE ---- */
#define L_OK 4          // pin
#define L_ALARM 8       // pin
#define P_S_DDD_ECHO 13  // pin
#define P_S_DDD_TRIG 12  // PIN

/* ---- ENUM FOR THE STATUS ---- */

typedef enum
{
    OK,
    UNCONNECTED
} ProblemState;

/* ---- CLASS STATE ---- */
class State
{
public:
private:
    static ProblemState systemState;
    static float levelWater;

public:
    static void setSystemState(ProblemState newState);
    static bool matchSystemState(ProblemState state);
    static bool isNotSystemState(ProblemState state);
    static ProblemState stringToSystemState(const char *stateString);
    static String systemStateToString(ProblemState state);
    static String currentSystemStateString();
    static inline void setLevelWater(float level) {
        levelWater = level;
    }

    static inline float getDistanceToGround() {
        return levelWater;
    }
};

/* ---- ENUM FOR THE HARDWARE ---- */

typedef enum
{
    LED,
    S_DDD,
} HardwareType;

inline bool matchHardwareType(HardwareType t1, HardwareType t2)
{
    return (t1 == t2);
}

inline bool isNotHardwareType(HardwareType t1, HardwareType t2)
{
    return (t1 != t2);
}

bool matchHardwareType(HardwareType t1, String t2);

bool isNotHardwareType(HardwareType t1, String t2);

/* ---- ENUM FOR THE TASKS ---- */

typedef enum
{
    T_INPUTOUTPUT,
    T_CHECKCONNECTION,
    T_MEASURELEVEL,
} TaskType;

inline bool matchTaskType(TaskType t1, TaskType t2)
{
    return (t1 == t2);
}

inline bool isNotTaskType(TaskType t1, TaskType t2)
{
    return (t1 != t2);
}

bool matchTaskType(TaskType t1, String t2);

bool isNotTaskType(TaskType t1, String t2);

#endif