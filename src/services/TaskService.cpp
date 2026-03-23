#include "services/TaskService.h"
#include "models/Task.h"
#include <iostream>
#include <algorithm>
#include <cctype>

TaskService::TaskService()
{
    tasks = repository.getAllTasks();
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

    repository.addTask(task);
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
        repository.updateTask(*task);
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
            repository.deleteTask(id);
            return;
        }
    }
}

void TaskService::editTask(int id, const std::string &newTitle)
{
    for (auto &task : tasks)
    {
        if (task.getId() == id)
        {
            task.setTitle(newTitle);
            repository.updateTask(task);
            return;
        }
    }

    std::cout << "Task not Found!!\n";
}

std::string toLower(std::string str)
{
    std::transform(str.begin(), str.end(), str.begin(),
                   [](unsigned char c)
                   { return std::tolower(c); });
    return str;
}

std::vector<Task> TaskService::searchTasks(const std::string &keyword) const
{
    std::vector<Task> result;

    std::string lowerKeyWord = toLower(keyword);

    for (const auto &task : tasks)
    {
        if (toLower(task.getTitle()).find(lowerKeyWord) != std::string::npos)
        {
            result.push_back(task);
        }
    }

    return result;
}