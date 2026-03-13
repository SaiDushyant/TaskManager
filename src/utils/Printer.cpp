#include <iostream>
#include "utils/Printer.h"

void Printer::printStartupMessage()
{
    std::cout << "Task Manager Starting!!!" << "\n";
}

void Printer::printMessage(const std::string &message)
{
    std::cout << message << "\n";
}