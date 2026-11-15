/*
 * PRN: 202501100068
 * Seed S: 68
 * Domain: Student marks (PRN mod 3 = 1)
 * Hash Function: Division Method (PRN is even)
 * Collision Strategy: Linear Probing (PRN mod 2 = 0)
 * Table Size m: 37
 */

#include <iostream>
#include <iomanip>
using namespace std;

const int TABLE_SIZE = 37;

// Division Method Hash Function
int divisionHash(int key) {
    return key % TABLE_SIZE;
}

int main() {
    int S = 68;
    int dataset[20];

    cout << "PRN: 202501100068" << endl;
    cout << "Hash Function: Division Method (key % 37)\n" << endl;

    for (int i = 0; i < 20; i++) {
        dataset[i] = (S + 13 * i) % 100;
        int index = divisionHash(dataset[i]);
        cout << "Key [" << setw(2) << dataset[i] 
             << "] -> Target Index: " << setw(2) << index << endl;
    }

    return 0;
}