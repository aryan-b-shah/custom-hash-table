#ifndef HASH_H
#define HASH_H
#include <iostream>
#include <string>
#include <cmath>
// You are free to use additional libraries as long as it's not PROHIBITED per instruction.

struct Node {
    std::string key;
    Node* next;
};

class HashTable {
private:
    int k;
    int* slotLengths;
    Node** table;

public:
    HashTable(int k);
    ~HashTable();

    void insert(const std::string& key);
    int hashFunction(const std::string& key);
    void printContents(int limit);
    void printSlotLengths();
    void printStandardVariance();
};

#endif