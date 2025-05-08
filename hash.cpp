#include "hash.h"
#include <iostream>
#include <cmath>
using namespace std;

HashTable::HashTable(int k) : k(k) {
    table = new Node*[k]();
    slotLengths = new int[k]();
}

HashTable::~HashTable() {
    delete[] slotLengths;

    for (int i = 0; i < k; ++i) {
        Node* current = table[i];
        Node* next;

        while (current != nullptr) {
            next = current->next;
            delete current;
            current = next;
        }
    }

    delete[] table;
}

void HashTable::insert(const string& key) {
    int index = hashFunction(key);
    Node* newNode = new Node{key, nullptr};

    if (table[index] == nullptr) {
        table[index] = newNode;
    } 
    else 
    {
        Node* current = table[index];
        while (current->next != nullptr) 
        {
            current = current->next;
        }
        current->next = newNode;
    }

    slotLengths[index]++;
}

int HashTable::hashFunction(const string& key) {
    // Simple hash function: sum of ASCII values of all characters in the strig giving the lowest variance
    int hashValue = 0;
    for (char ch : key) {
        hashValue += ch;
        switch(hashValue%10){
        case 5:
        hashValue+=1;
        break;
        default:
        hashValue+=3;
    }
    }
    return hashValue % k;
}

void HashTable::printContents(int limit) {
    for (int i = 0; i < limit; ++i) {
        cout << "Slot " << i << ": ";
        Node* current = table[i];
        while (current != nullptr) {
            cout << current->key << " ";
            current = current->next;
        }
        cout << endl;
    }
}

void HashTable::printSlotLengths() {
    for (int i = 0; i < k; ++i) {
        cout << "Slot " << i << ": " << slotLengths[i] << endl;
    }
}

void HashTable::printStandardVariance() {
    // Calculate the mean
    double mean = 0;
    for (int i = 0; i < k; ++i) {
        mean += slotLengths[i];
    }
    mean /= k;

    // Calculate the sum of squared differences from the mean
    double sumSquaredDiff = 0;
    for (int i = 0; i < k; ++i) {
        sumSquaredDiff += pow(slotLengths[i] - mean, 2);
    }

    // Calculate the standard deviation
    double standardDeviation = sqrt(sumSquaredDiff / k);
    cout << standardDeviation << endl;
}
