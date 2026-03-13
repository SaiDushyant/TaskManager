#include "core/FileTaskRepository.h"
#include <fstream>
#include <sstream>

void FileTaskRepository::saveTask(const std::vector<Task> &tasks)
{
    std::ofstream file("tasks.txt");

    for (const Task &task : tasks)
    {
        file << task.getId() << "|" << task.getTitle() << "|" << task.isCompleted() << "\n";
    }

    file.close();
}

std::vector<Task> FileTaskRepository::loadTasks()
{
    std::vector<Task> tasks;
    std::ifstream file("tasks.txt");
    std::string line;

    if (!file)
    {
        std::ofstream create("tasks.txt");
        return tasks;
    }

    while (std::getline(file, line))
    {
        if (line.empty())
            continue;

        std::stringstream ss(line);
        std::string strId, title, strCompleted;

        std::getline(ss, strId, '|');
        std::getline(ss, title, '|');
        std::getline(ss, strCompleted, '|');

        int id = std::stoi(strId);
        bool completed = (strCompleted == "1");

        Task task(id, title);

        if (completed)
            task.markCompleted();

        tasks.push_back(task);
    }

    return tasks;
}