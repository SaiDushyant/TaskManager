#ifndef FILETASKREPOSITORY_H
#define FILETASKREPOSITORY_H

#include <vector>
#include "models/Task.h"

class FileTaskRepository
{
public:
    void saveTask(const std::vector<Task> &tasks);
    std::vector<Task> loadTasks();
};

#endif