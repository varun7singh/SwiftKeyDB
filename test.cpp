#include "List.h"
#include "Database.h"

class List
{
private:
    unordered_map<string, string> list;

public:
    string listName;

    void insert(string key,string val) {
        if(list.find(key) != list.end()) {
            cout<<"Key already exists"<<endl;
            return;
        }
        list[key] = val;
    }

    void update(string key,string val) {
        if(list.find(key) == list.end()) {
            cout<<"Key does not exist"<<endl;
            return;
        }
        list[key] = val;
    }

    void remove(string key) {
        if(list.find(key) == list.end()) {
            cout<<"Key does not exist"<<endl;
            return;
        }
        list.erase(key);
    }


    string get(string key) {
        if(list.find(key) == list.end()) {
            cout<<"Key does not exist"<<endl;
            return "";
        }
        return list[key];
    }

    void display() {
        for(auto it = list.begin();it!=list.end();it++) {
            cout<<it->first<<" : "<<it->second<<endl;
        }
    }

    void displayKeys() {
        for(auto it = list.begin();it!=list.end();it++) {
            cout<<it->first<<endl;
        }
    }

    void displayValues() {
        for(auto it = list.begin();it!=list.end();it++) {
            cout<<it->second<<endl;
        }
    }
};

class Database
{
private:
    unordered_map<string, List> db;

public:
    string dbName;

    // fetch the list from the database
    List getList(string lname)
    {
        return db[lname];
    }

    // add a list to the database
    List addList(string lname)
    {
        List list;
        list.listName = lname;
        db[lname] = list;
        return list;
    }

    // remove a list from the database
    void removeList(string lname)
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
    void displayLists()
    {
        for (auto it = db.begin(); it != db.end(); it++)
        {
            cout << it->first << endl;
        }
    }
};

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

    // add a database to the manager
    Database addDatabase(string name)
    {
        Database db;
        db.dbName = name;
        databases[name] = db;
        return db;
    }

    // switch to a database in the manager
    Database switchDatabase(string name)
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
    void removeDatabase(string name)
    {
        if (databases.find(name) == databases.end())
        {
            cout << "Database does not exist" << endl;
        }
        else
        {
           if(currentDatabase.dbName == name) {
            cout<<"Database in use";
            return;
           }
           databases.erase(name);
        }
    }

    // display all databases in the manager
    void displayDatabases()
    {
        for (auto it = databases.begin(); it != databases.end(); it++)
        {
            if(it->first == currentDatabase.dbName) {
                cout <<"(*)"<< it->first << endl;
                continue;
            }
            cout << it->first << endl;
        }
    }

    // display all lists in the current database
    void displayLists()
    {
        currentDatabase.displayLists();
    }
};

int main()
{
    DatabaseManager dbm;
    while (true)
    {
        cout <<dbm.currentDatabase.dbName + ">> ";
        string command;
        cin >> command;
        if (command == "exit")
        {
            break;
        }
        else if (command == "new")
        {
            string type;
            cin >> type;
            if (type == "db")
            {
                string name;
                cin >> name;
                dbm.addDatabase(name);
            }
            else if (type == "list")
            {
                string name;
                cin >> name;
                dbm.currentDatabase.addList(name);
            }
        }
        else if (command == "use")
        {
            string name;
            cin >> name;
            dbm.switchDatabase(name);
        }
        else if (command == "show")
        {
            string type;
            cin >> type;
            if (type == "dbs")
            {
                dbm.displayDatabases();
            }
            else if (type == "lists")
            {
                dbm.displayLists();
            }
        }
        else if (command == "drop")
        {
            string type;
            cin >> type;
            if (type == "db")
            {
                string name;
                cin >> name;
                dbm.removeDatabase(name);
            }
            else if (type == "list")
            {
                string name;
                cin >> name;
                dbm.currentDatabase.removeList(name);
            }
        }
    }

    return 0;
}