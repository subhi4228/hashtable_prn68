/*
 * PRN: 202501100068
 * Seed S: 68
 * Domain: Student marks (PRN mod 3 = 1)
 * Hash Function: Division Method (PRN is even)
 * Collision Strategy: Linear Probing (PRN mod 2 = 0)
 * Table Size m: 37
 */

#include <iostream>
using namespace std;

int main() {
    int S = 68;
    int dataset[20];

    cout << "PRN: 202501100068" << endl;
    cout << "Dataset: ";

    for (int i = 0; i < 20; i++) {
        dataset[i] = (S + 13 * i) % 100;
        cout << dataset[i] << " ";
    }
    cout << endl;

    return 0;
}