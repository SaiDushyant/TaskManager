#include "services/TaskService.h"
#include "models/Task.h"
#include <iostream>

TaskService::TaskService()
{
    tasks = repository.loadTasks();
}

int TaskService::getNextTaskId() const
{
    int maxId = 0;

    for (const auto &task : tasks)
    {
        if (task.getId() > maxId)
        {
            maxId = task.getId();
        }
    }

    return maxId + 1;
}

void TaskService::addTask(const std::string &title)
{
    int id = getNextTaskId();

    Task task(id, title);

    tasks.push_back(task);

    repository.saveTask(tasks);
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

void TaskService::listTasks() const
{
    if (tasks.empty())
    {
        std::cout << "No Tasks Available !!\n";
        return;
    }
    for (const auto &task : tasks)
    {
        std::cout << task.getId() << " | " << task.getTitle() << " | " << (task.isCompleted() ? "Completed" : "Pending") << "\n";
    }
}

void TaskService::deleteTask(int id)
{
    for (auto it = tasks.begin(); it != tasks.end(); it++)
    {
        if (it->getId() == id)
        {
            tasks.erase(it);
            repository.saveTask(tasks);
            return;
        }
    }
}