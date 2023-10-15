#include "include/List.h"

// add a new element to the list
void List::insert(string key, string val)
{
    if (list.find(key) != list.end())
    {
        cout << "Key already exists" << endl;
        return;
    }
    list[key] = val;
}

// update an existing element in the list
void List::update(string key, string val)
{
    if (list.find(key) == list.end())
    {
        cout << "Key does not exist" << endl;
        return;
    }
    list[key] = val;
}

// remove an element from the list
void List::remove(string key)
{
    if (list.find(key) == list.end())
    {
        cout << "Key does not exist" << endl;
        return;
    }
    list.erase(key);
}

// get an element from the list
string List::get(string key)
{
    if (list.find(key) == list.end())
    {
        cout << "Key does not exist" << endl;
        return "";
    }
    return list[key];
}

// display all elements in the list
void List::display()
{
    for (auto it = list.begin(); it != list.end(); it++)
    {
        cout << it->first << " : " << it->second << endl;
    }
}

// display all keys in the list
void List::displayKeys()
{
    for (auto it = list.begin(); it != list.end(); it++)
    {
        cout << it->first << endl;
    }
}

// display all values in the list
void List::displayValues()
{
    for (auto it = list.begin(); it != list.end(); it++)
    {
        cout << it->second << endl;
    }
}
