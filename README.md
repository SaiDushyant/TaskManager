# Task Manager CLI (C++)

A simple **Command Line Task Manager** written in **C++** using
**Object-Oriented Design** and **CMake**.

This project allows users to manage tasks directly from the terminal.
Tasks are stored in a file and automatically loaded when the program
starts.

The goal of this project is to demonstrate: - C++ OOP design - File
persistence - Modular architecture - CMake build system - CLI
application development

------------------------------------------------------------------------

# Features

-   List tasks
-   Add new tasks
-   Mark tasks as completed
-   Delete tasks
-   Persistent storage using a file (`tasks.txt`)
-   Automatic task ID management

------------------------------------------------------------------------

# Project Structure

```
TaskManager
├── include
│   ├── core
│   │   └── FileTaskRepository.h
│   ├── models
│   │   └── Task.h
│   ├── services
│   │   └── TaskService.h
│   └── utils
│       └── Printer.h
│
├── src
│   ├── core
│   │   └── FileTaskRepository.cpp
│   ├── models
│   │   └── Task.cpp
│   ├── services
│   │   └── TaskService.cpp
│   └── utils
│       └── Printer.cpp
│
├── CMakeLists.txt
├── main.cpp
└── README.md
```

------------------------------------------------------------------------

# Build Instructions

## Requirements

-   C++17
-   CMake (\>= 3.10)
-   g++

## Build Steps

### Clone the repository

```bash
git clone https://github.com/SaiDushyant/TaskManager.git
cd TaskManager
```

### Build the project

```bash
mkdir build
cd build
cmake ..
make
```

### Run the program

```bash
./task_manager
```


------------------------------------------------------------------------

# Example CLI Usage

===== Task Manager ===== 
1. List Tasks
2. Add Task
3. Complete Task
4. Delete Task
5. Exit

### Add a Task

Enter choice: 2 
Enter task title: Study C++ 

Task added

### List Tasks

Enter choice: 1

1 \| Study C++ \| Pending

### Complete a Task

Enter choice: 3 
Enter task id: 1

Task marked completed

### Delete a Task

Enter choice: 4 
Enter task id: 1

Task deleted

------------------------------------------------------------------------

# How Tasks Are Stored

Tasks are saved in a file:

tasks.txt

Example:

1\|Study C++\|0 2\|Build project\|1

Format:

ID \| TITLE \| COMPLETED

Where: - 0 → Pending - 1 → Completed

------------------------------------------------------------------------

## Design Architecture

The project follows a **layered architecture**:

```
CLI (main.cpp)
      │
      ▼
TaskService
      │
      ▼
FileTaskRepository
      │
      ▼
Task Model
```

### Layer Responsibilities

| Layer      | Responsibility   |
| ---------- | ---------------- |
| CLI        | User interaction |
| Service    | Business logic   |
| Repository | File storage     |
| Model      | Task data        |


------------------------------------------------------------------------

# Future Improvements

-   Task editing
-   Task priority
-   Due dates
-   Task search
-   Colored CLI output
-   Unit tests
-   GUI version

------------------------------------------------------------------------

# Author

Sai Dushyant
