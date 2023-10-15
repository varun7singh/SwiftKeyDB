#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H
#include "Database.h"

class DatabaseManager
{
private:
    unordered_map<string, Database> databases;

public:
    Database currentDatabase;
    DatabaseManager()
    {
        currentDatabase = addDatabase("temp");
    }
    Database addDatabase(string name);
    void removeDatabase(string name);
    Database switchDatabase(string name);
    void displayDatabases();
    void displayLists();
};
#endif;
