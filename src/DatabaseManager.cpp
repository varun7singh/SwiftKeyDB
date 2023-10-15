#include "include/DatabaseManager.h"
#include "include/Database.h"
#include "include/List.h"

// add a database to the manager
Database DatabaseManager::addDatabase(string name)
{
    Database db;
    db.dbName = name;
    databases[name] = db;
    return db;
}

// switch to a database in the manager
Database DatabaseManager::switchDatabase(string name)
{
    if (databases.find(name) == databases.end())
    {
        cout << "Database does not exist" << endl;
        return currentDatabase;
    }
    else
    {
        currentDatabase = databases[name];
        return currentDatabase;
    }
}

// remove a database from the manager
void DatabaseManager::removeDatabase(string name)
{
    if (databases.find(name) == databases.end())
    {
        cout << "Database does not exist" << endl;
    }
    else
    {
        if (currentDatabase.dbName == name)
        {
            cout << "Database in use";
            return;
        }
        databases.erase(name);
    }
}

// display all databases in the manager
void DatabaseManager::displayDatabases()
{
    for (auto it = databases.begin(); it != databases.end(); it++)
    {
        if (it->first == currentDatabase.dbName)
        {
            cout << "(*)" << it->first << endl;
            continue;
        }
        cout << it->first << endl;
    }
}

// display all lists in the current database
void DatabaseManager::displayLists()
{
    currentDatabase.displayLists();
}
