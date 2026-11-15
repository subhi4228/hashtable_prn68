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
        int probes = 0;

        // Linear probing loop
        while (table[index].occupied) {
            probes++;
            index = (index + 1) % TABLE_SIZE;
            if (index == originalIndex) return; // Table full
        }

        table[index].key = key;
        table[index].markLabel = markLabel;
        table[index].occupied = true;

        cout << "  Inserted key=" << setw(2) << key
             << " (" << setw(9) << markLabel << ") -> Target "
             << setw(2) << originalIndex << " -> Placed at Index "
             << setw(2) << index << " (Probes: " << probes << ")" << endl;
    }

    void display() {
        cout << "\n========== HASH TABLE (Linear Probing) ==========" << endl;
        cout << "Table size m = 37" << endl;
        cout << "==================================================" << endl;
        for (int i = 0; i < TABLE_SIZE; i++) {
            cout << "Index " << setw(2) << i << " : ";
            if (!table[i].occupied) cout << "EMPTY" << endl;
            else cout << "[" << table[i].key << ":" << table[i].markLabel << "]" << endl;
        }
        cout << "==================================================" << endl;
    }
};

int main() {
    int S = 68;
    int dataset[20];
    HashTable ht;

    cout << "--- Insertion Trace ---" << endl;
    for (int i = 0; i < 20; i++) {
        dataset[i] = (S + 13 * i) % 100;
        ht.insert(dataset[i], "Mark_" + to_string(dataset[i]));
    }

    ht.display();
    return 0;
}