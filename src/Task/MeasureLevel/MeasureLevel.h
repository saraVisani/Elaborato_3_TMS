#ifndef __MEASURELEVEL__
#define __MEASURELEVEL__

#include "Task/Task.h"

class MeasureLevel: public Task{
    private:

    public:
    void tick() override;
    bool guard() override {
        return State::matchSystemState(OK);
    }
    inline TaskType getType() override {
        return TaskType::T_MEASURELEVEL;
    };
};

#endif