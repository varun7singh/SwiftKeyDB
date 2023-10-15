#ifndef DATABASE_H
#define DATABASE_H
#include "List.h"

class Database
{
private:
    unordered_map<string, List> db;

public:
    string dbName;
    List getList(string lname);
    List addList(string lname);
    void removeList(string lname);
    void displayLists();
};

#endif