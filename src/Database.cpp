#include "../include/Database.h"

// add a new list to the database
List Database::addList(string lname)
{
    List list;
    list.listName = lname;
    db[lname] = list;
    return list;
}

// remove a list from the database
void Database::removeList(string lname)
{
    if (db.find(lname) == db.end())
    {
        cout << "List does not exist" << endl;
    }
    else
    {
        db.erase(lname);
    }
}

// display all lists in the database
void Database::displayLists()
{
    for (auto it = db.begin(); it != db.end(); it++)
    {
        cout << it->first << endl;
    }
}