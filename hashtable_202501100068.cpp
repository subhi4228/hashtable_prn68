/*
 * PRN: 202501100068
 * Seed S: 68
 * Domain: Student marks (PRN mod 3 = 1)
 * Hash Function: Division Method (PRN is even)
 * Collision Strategy: Linear Probing (PRN mod 2 = 0)
 * Table Size m: 37
 */

#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

const int TABLE_SIZE = 37;

// Entry struct for linear probing
struct Entry {
    int key;
    string markLabel;
    bool occupied;
    Entry() : key(-1), markLabel(""), occupied(false) {}
};

int divisionHash(int key) {
    return key % TABLE_SIZE;
}

class HashTable {
private:
    vector<Entry> table;
public:
    HashTable() {
        table.resize(TABLE_SIZE);
    }

    void insert(int key, string markLabel) {
        int index = divisionHash(key);
        int originalIndex = index;

        // Linear probing loop to find an empty slot
        while (table[index].occupied) {
            index = (index + 1) % TABLE_SIZE;
            if (index == originalIndex) return; // Table full
        }

        table[index].key = key;
        table[index].markLabel = markLabel;
        table[index].occupied = true;
    }
};

int main() {
    int S = 68;
    int dataset[20];
    HashTable ht;

    for (int i = 0; i < 20; i++) {
        dataset[i] = (S + 13 * i) % 100;
        ht.insert(dataset[i], "Mark_" + to_string(dataset[i]));
    }

    cout << "Linear probing hash table initialized and inserted successfully." << endl;
    return 0;
}