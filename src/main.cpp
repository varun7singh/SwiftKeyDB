#include "../include/DatabaseManager.h"

int main()
{
    DatabaseManager dbm;
    while (true)
    {
        cout << dbm.currentDatabase.dbName + ">> ";
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