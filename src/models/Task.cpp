#include "models/Task.h"

Task::Task(int id, const std::string &title) : id(id), title(title), completed(false) {}

int Task::getId() const
{
    return id;
}

const std::string &Task::getTitle() const
{
    return title;
}

bool Task::isCompleted() const
{
    return completed;
}

void Task::markCompleted()
{
    completed = true;
}