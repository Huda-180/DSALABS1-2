#include <iostream>
using namespace std;

int main() {
    const int BRANCHES = 2;
    const int DAYS = 3;

    int sales[BRANCHES][DAYS];      // fixed-size 2D array, stored row by row

    // int (*rowPtr)[3] : "rowPtr is a pointer to an array of 3 ints".
    // The row length MUST be part of the type so that rowPtr + 1
    // knows how many bytes to jump to reach the next row.
    int (*rowPtr)[DAYS] = sales;

    // Part 1: read the six values 
    cout << "Enter sales for 2 branches over 3 days (non-negative):" << endl;
    for (int r = 0; r < BRANCHES; r++) {
        for (int c = 0; c < DAYS; c++) {
            cout << "Branch " << (r + 1) << ", Day " << (c + 1) << ": ";
            cin >> *(*(rowPtr + r) + c);    // (rowPtr + r) -> row r
                                            // *(rowPtr + r) -> that row (decays to int*)
                                            // +c then *     -> element at column c
            while (*(*(rowPtr + r) + c) < 0) {
                cout << "Sales cannot be negative. Re-enter: ";
                cin >> *(*(rowPtr + r) + c);
            }
        }
    }

    // Display as a two-row table
    cout << "\nSales table:" << endl;
    cout << "            Day1  Day2  Day3" << endl;
    for (int r = 0; r < BRANCHES; r++) {
        cout << "Branch " << (r + 1) << " :  ";
        for (int c = 0; c < DAYS; c++) {
            cout << "   " << *(*(rowPtr + r) + c) << "  ";
        }
        cout << endl;
    }

    // Part 2a: total for each BRANCH (sum across a row) 
    cout << "\nBranch totals:" << endl;
    for (int r = 0; r < BRANCHES; r++) {
        int branchTotal = 0;                // reset at the start of each branch
        for (int c = 0; c < DAYS; c++) {
            branchTotal += *(*(rowPtr + r) + c);
        }
        cout << "  Branch " << (r + 1) << " total = " << branchTotal << endl;
    }

    // Part 2b: total for each DAY (sum down a column) 
    cout << "\nDay totals:" << endl;
    for (int c = 0; c < DAYS; c++) {
        int dayTotal = 0;                   // reset at the start of each day
        for (int r = 0; r < BRANCHES; r++) {
            dayTotal += *(*(rowPtr + r) + c);
        }
        cout << "  Day " << (c + 1) << " total = " << dayTotal << endl;
    }

    //  Part 3: show the pointer step size 
    cout << "\n Pointer arithmetic demonstration " << endl;
    cout << "rowPtr      = " << rowPtr     << endl;
    cout << "rowPtr + 1  = " << (rowPtr+1) << "  (jumps a WHOLE row = 3 ints)" << endl;
    int* elemPtr = &sales[0][0];
    cout << "elemPtr     = " << elemPtr     << endl;
    cout << "elemPtr + 1 = " << (elemPtr+1) << "  (jumps only ONE int)" << endl;

    return 0;
}