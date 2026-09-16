#include <iostream>
using namespace std;

int main() {
    const int DAYS = 5;

    int sales[DAYS];      // fixed-size (static) array: memory reserved on the stack
    int* p = sales;       // p holds the address of the FIRST element (sales[0])
                          // An array name decays to a pointer to its first element,
                          // so "p = sales" is the same as "p = &sales[0]".

    // Part 1: read five non-negative values 
    cout << "Enter items sold for 5 days (non-negative values):" << endl;
    for (int i = 0; i < DAYS; i++) {
        cout << "Day " << (i + 1) << ": ";
        cin >> *(p + i);        // *(p + i) is the element i steps forward from p

        // Validation: reject negative sales figures
        while (*(p + i) < 0) {
            cout << "Sales cannot be negative. Re-enter Day " << (i + 1) << ": ";
            cin >> *(p + i);
        }
    }

    // Display the values and compute the total, again using pointer notation
    int total = 0;
    cout << "\nOriginal sales: ";
    for (int i = 0; i < DAYS; i++) {
        cout << *(p + i) << " ";
        total += *(p + i);
    }
    cout << "\nOriginal total: " << total << endl;

    //  Part 2: add 2 to the third day THROUGH the pointer 
    // The third day is index 2 (indices start at 0).
    *(p + 2) = *(p + 2) + 2;    // modifies sales[2] directly in memory

    int updatedTotal = 0;
    cout << "\nUpdated sales:  ";
    for (int i = 0; i < DAYS; i++) {
        cout << *(p + i) << " ";
        updatedTotal += *(p + i);
    }
    cout << "\nUpdated total:  " << updatedTotal << endl;

    // Part 3: demonstrate the pointer expressions
    cout << "\nPointer expression demonstration" << endl;
    cout << "p        = " << p        << "  (address of sales[0])" << endl;
    cout << "&p       = " << &p       << "  (address of the pointer variable itself)" << endl;
    cout << "*p       = " << *p       << "  (value stored in sales[0])" << endl;
    cout << "*(p + 2) = " << *(p + 2) << "  (value stored in sales[2])" << endl;
    cout << "Valid indices are 0 to 4 only." << endl;

    // NOTE: p is never moved, so it still points at sales[0].
    // NOTE: sales is a local fixed-size array - it must NOT be deleted.
    return 0;
}