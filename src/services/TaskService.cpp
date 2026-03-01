#include "services/TaskService.h"
#include "models/Task.h"

void TaskService::addTask(const Task &task)
{
    tasks.push_back(task);
}

Task *TaskService::getTaskById(int id)
{
    for (auto &task : tasks)
    {
        if (task.getId() == id)
        {
            return &task;
        }
    }

    return nullptr;
}

void TaskService::markTaskCompleted(int id)
{
    Task *task = getTaskById(id);

    if (task)
    {
        task->markCompleted();
    }
}