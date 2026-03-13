cmake_minimum_required(VERSION 3.10)

project(TaskManager)

set(CMAKE_CXX_STANDARD 17)

# MODELS
add_library(models
    src/models/Task.cpp
)

target_include_directories(models PUBLIC include)

# CORE
add_library(core
    src/core/FileTaskRepository.cpp
)

target_include_directories(core PUBLIC include)
target_link_libraries(core models)

# SERVICES
add_library(services
    src/services/TaskService.cpp
)

target_include_directories(services PUBLIC include)
target_link_libraries(services models core)

# UTILS
add_library(utils
    src/utils/Printer.cpp
)

target_include_directories(utils PUBLIC include)

# EXECUTABLE
add_executable(task_manager main.cpp)

target_link_libraries(task_manager
    services
    utils
)