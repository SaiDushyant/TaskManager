#include <iostream>
#include "utils/Printer.h"
#include "services/TaskService.h"

int main()
{
    Printer printer;
    TaskService service;

    printer.printStartupMessage();

    int choice;

    while (true)
    {
        std::cout << "\n===== Task Manager =====\n";
        std::cout << "1. List Tasks\n";
        std::cout << "2. Add Task\n";
        std::cout << "3. Complete Task\n";
        std::cout << "4. Delete Task\n";
        std::cout << "5. Exit\n";
        std::cout << "Enter choice: ";

        std::cin >> choice;

        if (choice == 1)
        {
            service.listTasks();
        }
        else if (choice == 2)
        {
            std::cin.ignore();

            std::string title;
            std::cout << "Enter task title: ";
            std::getline(std::cin, title);

            int id = rand() % 100000; // temporary id generator
            service.addTask(title);

            std::cout << "Task added\n";
        }
        else if (choice == 3)
        {
            int id;
            std::cout << "Enter task id: ";
            std::cin >> id;

            service.markTaskCompleted(id);
            std::cout << "Task marked completed\n";
        }
        else if (choice == 4)
        {
            int id;
            std::cout << "Enter task id: ";
            std::cin >> id;

            service.deleteTask(id);
            std::cout << "Task deleted\n";
        }
        else if (choice == 5)
        {
            std::cout << "Goodbye!\n";
            break;
        }
        else
        {
            std::cout << "Invalid option\n";
        }
    }

    return 0;
}