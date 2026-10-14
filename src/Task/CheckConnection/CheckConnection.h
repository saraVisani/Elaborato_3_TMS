#ifndef __CHECKCONNECTION__
#define __CHECKCONNECTION__

#include "Task/Task.h"

class CheckConnection: public Task{
    public:
        void tick() override;
        inline TaskType getType() override{
            return TaskType::T_CHECKCONNECTION;
        }
};
#endif