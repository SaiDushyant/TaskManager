#include <iostream>
#include "utils/Printer.h"
#include "models/Task.h"

int main()
{
    Printer printer;
    Task task(1, "Hello");

    printer.printStartupMessage();
    printer.printMessage("System Ready");

    std::cout << "Task Id : " << task.getId() << "\n";
    return 0;
}