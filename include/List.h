#ifndef LIST_H
#define LIST_H

#include <string>
#include <unordered_map>
#include <iostream>
using namespace std;

class List
{
private:
    unordered_map<string, string> list;

public:
    string listName;
    void insert(string key,string val);
    void update(string key,string val);
    void remove(string key);
    string get(string key);
    void display();
    void displayKeys();
    void displayValues();
};

#endif