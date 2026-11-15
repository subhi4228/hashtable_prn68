/*
 * PRN: 202501100068
 * Seed S: 68
 * Domain: Student marks (PRN mod 3 = 1)
 * Hash Function: Division Method (PRN is even)
 * Collision Strategy: Linear Probing (PRN mod 2 = 0)
 * Table Size m: 37 (Smallest prime >= (68 mod 23) + 11 = 33)
 * Dataset: v[i] = (68 + 13*i) mod 100, i = 0..19
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

// Division Method Hash Function
int divisionHash(int key) {
    return key % TABLE_SIZE;
}

// Hash Table class using Linear Probing
class HashTable {
private:
    vector<Entry> table;

public:
    HashTable() {
        table.resize(TABLE_SIZE);
    }

    // Insert key using Linear Probing collision resolution
    void insert(int key, string markLabel) {
        int index = divisionHash(key);
        int originalIndex = index;
        int probes = 0;

        // Linear probing loop
        while (table[index].occupied) {
            probes++;
            index = (index + 1) % TABLE_SIZE;
            if (index == originalIndex) {
                cout << "Error: Hash Table is full!" << endl;
                return;
            }
        }

        table[index].key = key;
        table[index].markLabel = markLabel;
        table[index].occupied = true;

        cout << "  Inserted key=" << setw(2) << key
             << " (" << setw(9) << markLabel << ") -> Target Index "
             << setw(2) << originalIndex
             << " -> Placed at Index " << setw(2) << index
             << " (Probes: " << probes << ")" << endl;
    }

    // Print hash table contents
    void display() {
        cout << "\n========== HASH TABLE (Linear Probing) ==========" << endl;
        cout << "Table size m = " << TABLE_SIZE << endl;
        cout << "Hash Method : Division Method (key % 37)" << endl;
        cout << "==================================================" << endl;
        for (int i = 0; i < TABLE_SIZE; i++) {
            cout << "Index " << setw(2) << i << " : ";
            if (!table[i].occupied) {
                cout << "EMPTY" << endl;
            } else {
                cout << "[" << table[i].key << ":" << table[i].markLabel << "]" << endl;
            }
        }
        cout << "==================================================" << endl;
    }
};

int main() {
    int S = 68;
    int dataset[20];
    string markLabels[20];

    cout << "============================================" << endl;
    cout << "  PRN       : 202501100068" << endl;
    cout << "  Domain    : Student marks" << endl;
    cout << "  Hash Func : Division Method (key % 37)" << endl;
    cout << "  Collision : Linear Probing" << endl;
    cout << "  Table Size: 37" << endl;
    cout << "============================================\n" << endl;

    // Generate dataset & labels
    cout << "Dataset: ";
    for (int i = 0; i < 20; i++) {
        dataset[i] = (S + 13 * i) % 100;
        markLabels[i] = "Mark_" + to_string(dataset[i]);
        cout << dataset[i] << " ";
    }
    cout << "\n\n--- Insertion Trace ---" << endl;

    HashTable ht;

    for (int i = 0; i < 20; i++) {
        ht.insert(dataset[i], markLabels[i]);
    }

    ht.display();

    return 0;
}