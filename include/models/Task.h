#ifndef TASK_H
#define TASK_H

#include <sstream>

class Task
{
private:
    int id;
    std::string title;
    bool completed;

public:
    Task(int id, const std::string &title);

    int getId() const;
    const std::string &getTitle() const;
    bool isCompleted() const;

    void markCompleted();

    void setTitle(const std::string &newTitle);
};

#endif