#include <Configuration/Includes.h>

RealTimer timer;
Scheduler scheduler(timer);

void setup() {
  hw->initAllHardware();
  scheduler.init(25);
  Task* checkTask = new CheckConnection();
  checkTask->init(25);
  scheduler.addTask(checkTask);
  Task* ioTask = new InputOutput();
  ioTask->init(50);
  scheduler.addTask(ioTask);
  Task* measureTask = new MeasureLevel();
  measureTask->init(50);
  scheduler.addTask(measureTask);
}

void loop() {
  scheduler.schedule();
}