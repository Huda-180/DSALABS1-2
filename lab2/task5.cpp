#include <iostream>
using namespace std;

int main() {
    int n;

    cout << "Enter the number of students (1-10): ";
    cin >> n;

    if (n < 1 || n > 10) {
        cout << "Error: n must be between 1 and 10. No memory was allocated." << endl;
        return 1;
    }

    // Original block of n marks 
    int* marks = new int[n];

    cout << "Enter " << n << " marks:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Student " << (i + 1) << ": ";
        cin >> *(marks + i);
    }

    cout << "\nOriginal marks: ";
    for (int i = 0; i < n; i++) {
        cout << *(marks + i) << " ";
    }
    cout << "(size = " << n << ")" << endl;

    //  Part 1: allocate a SECOND block of n + 1 
    int newSize = n + 1;
    int* bigger = new int[newSize];

    // Copy the original n values across using pointer notation
    for (int i = 0; i < n; i++) {
        *(bigger + i) = *(marks + i);
    }

    // Read the new student's mark into the LAST position (index n)
    cout << "\nEnter the new student's mark: ";
    cin >> *(bigger + n);

    // Part 2: free the old block, repoint, update size 
    delete[] marks;      // release the old, smaller block - otherwise it leaks
    marks = bigger;      // the original pointer now refers to the new block
    n = newSize;         // keep the stored size in step with the real capacity
    bigger = nullptr;    // avoid two names for the same block

    cout << "\nUpdated marks: ";
    for (int i = 0; i < n; i++) {
        cout << *(marks + i) << " ";
    }
    cout << "(size = " << n << ")" << endl;

    //  Part 3: release the final block EXACTLY ONCE 
    delete[] marks;      // deleting twice would be undefined behaviour
    marks = nullptr;

    cout << "\nFinal block released once and pointer set to nullptr." << endl;
    return 0;
}