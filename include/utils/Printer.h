#ifndef PRINTER_H
#define PRINTER_H

#include <string>

class Printer
{
public:
    void printStartupMessage();
    void printMessage(const std::string &message);
};

#endif