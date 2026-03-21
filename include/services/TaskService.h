#ifndef TASKSERVICE_H
#define TASKSERVICE_H

#include "core/FileTaskRepository.h"
#include <vector>

class Task;

class TaskService
{
private:
    std::vector<Task> tasks;
    FileTaskRepository repository;
    int getNextTaskId() const;

public:
    TaskService();
    void addTask(const std::string &title);
    Task *getTaskById(int id);
    void markTaskCompleted(int id);
    void listTasks() const;
    void deleteTask(int id);
    void editTask(int id, const std::string &newTitle);
    std::vector<Task> searchTasks(const std::string &keyword) const;
};

#endif