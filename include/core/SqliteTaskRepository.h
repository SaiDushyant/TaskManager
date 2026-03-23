#ifndef SQLITE_TASK_REPOSITORY_H
#define SQLITE_TASK_REPOSITORY_H

#include <vector>
#include <sqlite3.h>
#include "models/Task.h"

class SqliteTaskRepository
{
private:
    sqlite3 *db;
    void init();

public:
    SqliteTaskRepository();
    ~SqliteTaskRepository();

    void addTask(const Task &task);
    void updateTask(const Task &task);
    void deleteTask(int id);
    std::vector<Task> getAllTasks();
};

#endif