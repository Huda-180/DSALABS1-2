#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int n;

    //  Part 1: read and VALIDATE n BEFORE allocating 
    cout << "Enter the number of students (1-10): ";
    cin >> n;

    if (n < 1 || n > 10) {
        // Error is reported and the program ends BEFORE any allocation,
        // so there is nothing to clean up.
        cout << "Error: n must be between 1 and 10. No memory was allocated." << endl;
        return 1;
    }

    // Allocate n integers on the heap. "marks" is a pointer variable
    // living on the stack; the n integers live on the heap.
    int* marks = new int[n];

    cout << "Enter " << n << " marks (0-100):" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Student " << (i + 1) << ": ";
        cin >> *(marks + i);        // pointer notation instead of marks[i]
    }

    //  Part 2: display, total, average, pass count 
    int total = 0;
    int passCount = 0;

    cout << "\nMarks entered: ";
    for (int i = 0; i < n; i++) {
        cout << *(marks + i) << " ";
        total += *(marks + i);
        if (*(marks + i) >= 50) {
            passCount++;            // count marks >= 50
        }
    }

    // Cast to double so the fractional part of the average is preserved.
    // Without the cast, integer division would discard it (241/4 -> 60).
    double average = static_cast<double>(total) / n;

    cout << "\nTotal:      " << total << endl;
    cout << "Average:    " << fixed << setprecision(2) << average << endl;
    cout << "Pass count: " << passCount << " (marks >= 50)" << endl;

    //  Part 3: release the memory
    delete[] marks;     // frees the n integers on the heap
    marks = nullptr;    // the pointer variable still exists; we blank it so
                        // it cannot accidentally be used as a dangling pointer

    cout << "\nMemory released and pointer set to nullptr." << endl;
    return 0;
}