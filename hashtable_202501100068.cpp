/*
 * PRN: 202501100068
 * Seed S: 68
 * Domain: Student marks (PRN mod 3 = 1)
 * Hash Function: Division Method (PRN is even)
 * Collision Strategy: Attempted direct array insert (no collision handling) - FAILED APPROACH
 * Table Size m: 37
 */

#include <iostream>
#include <iomanip>
using namespace std;

const int TABLE_SIZE = 37;

int divisionHash(int key) {
    return key % TABLE_SIZE;
}

class SimpleHashTable {
private:
    int table[TABLE_SIZE];
public:
    SimpleHashTable() {
        for (int i = 0; i < TABLE_SIZE; i++) table[i] = -1;
    }

    void insert(int key) {
        int index = divisionHash(key);
        table[index] = key; // Direct overwrite bug!
    }

    void display() {
        cout << "\nFlat Array Hash Table (Overwrites on collision):" << endl;
        for (int i = 0; i < TABLE_SIZE; i++) {
            cout << "Index " << setw(2) << i << " : ";
            if (table[i] == -1) cout << "EMPTY" << endl;
            else cout << table[i] << endl;
        }
    }
};

int main() {
    int S = 68;
    int dataset[20];
    SimpleHashTable ht;

    for (int i = 0; i < 20; i++) {
        dataset[i] = (S + 13 * i) % 100;
        ht.insert(dataset[i]);
    }

    ht.display();
    return 0;
}