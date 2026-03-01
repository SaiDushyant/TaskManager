#ifndef TASKSERVICE_H
#define TASKSERVICE_H

#include <vector>

class Task;

class TaskService
{
private:
    std::vector<Task> tasks;

public:
    void addTask(const Task &task);
    Task *getTaskById(int id);
    void markTaskCompleted(int id);
};

#endif