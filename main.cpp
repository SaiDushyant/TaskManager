#include <iostream>
#include "utils/Printer.h"
#include "services/TaskService.h"
#include "models/Task.h"

int main()
{
    Printer printer;
    TaskService service;

    printer.printStartupMessage();
    printer.printMessage("Starting");

    service.addTask(Task(1, "Hello"));

    service.markTaskCompleted(1);

    Task *task = service.getTaskById(1);

    if (task)
        std::cout << "Task Id: " << task->getId() << "\n";

    return 0;
}