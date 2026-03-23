#include "core/SqliteTaskRepository.h"
#include "iostream"

SqliteTaskRepository::SqliteTaskRepository()
{
    if (sqlite3_open("tasks.db", &db))
    {
        std::cerr << "Cannot open Database\n";
    }
    init();
}

SqliteTaskRepository::~SqliteTaskRepository()
{
    sqlite3_close(db);
}

void SqliteTaskRepository::init()
{
    const char *sql =
        "CREATE TABLE IF NOT EXISTS tasks ("
        "id INTEGER PRIMARY KEY, "
        "title TEXT, "
        "completed INTEGER);";

    char *errMsg = nullptr;

    if (sqlite3_exec(db, sql, nullptr, nullptr, &errMsg) != SQLITE_OK)
    {
        std::cerr << "SQL error: " << errMsg << "\n";
        sqlite3_free(errMsg);
    }
}

void SqliteTaskRepository::addTask(const Task &task)
{
    const char *sql = "INSERT INTO tasks (id, title, completed) VALUES (?, ?, ?);";

    sqlite3_stmt *stmt;
    sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr);

    sqlite3_bind_int(stmt, 1, task.getId());
    sqlite3_bind_text(stmt, 2, task.getTitle().c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_int(stmt, 3, task.isCompleted());

    sqlite3_step(stmt);
    sqlite3_finalize(stmt);
}

void SqliteTaskRepository::updateTask(const Task &task)
{
    const char *sql = "UPDATE tasks SET title = ?, completed = ? WHERE id = ?;";

    sqlite3_stmt *stmt;
    sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr);

    sqlite3_bind_text(stmt, 1, task.getTitle().c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_int(stmt, 2, task.isCompleted());
    sqlite3_bind_int(stmt, 3, task.getId());

    sqlite3_step(stmt);
    sqlite3_finalize(stmt);
}

void SqliteTaskRepository::deleteTask(int id)
{
    const char *sql = "DELETE FROM tasks WHERE id = ?;";

    sqlite3_stmt *stmt;
    sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr);

    sqlite3_bind_int(stmt, 1, id);

    sqlite3_step(stmt);
    sqlite3_finalize(stmt);
}

std::vector<Task> SqliteTaskRepository::getAllTasks()
{
    std::vector<Task> tasks;

    const char *sql = "SELECT id, title, completed FROM tasks;";
    sqlite3_stmt *stmt;

    sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr);

    while (sqlite3_step(stmt) == SQLITE_ROW)
    {
        int id = sqlite3_column_int(stmt, 0);
        std::string title = (const char *)sqlite3_column_text(stmt, 1);
        bool completed = sqlite3_column_int(stmt, 2);

        Task task(id, title);
        if (completed)
            task.markCompleted();

        tasks.push_back(task);
    }

    sqlite3_finalize(stmt);
    return tasks;
}