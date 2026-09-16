#include <iostream>
using namespace std;

int main() {
    int rows, cols;

    //  Part 1: read and VALIDATE both dimensions 
    cout << "Enter number of students (1-10): ";
    cin >> rows;
    cout << "Enter number of subjects (1-10): ";
    cin >> cols;

    if (rows < 1 || rows > 10 || cols < 1 || cols > 10) {
        cout << "Error: both values must be between 1 and 10. "
             << "No memory was allocated." << endl;
        return 1;    // exit BEFORE allocating anything
    }

    //  Part 2: two-stage allocation
    int** marks = new int*[rows];        // stage 1: array of 'rows' pointers
    for (int r = 0; r < rows; r++) {
        marks[r] = new int[cols];        // stage 2: each row gets its own block
    }

    //  Part 3: read the marks using pointer notation 
    cout << "\nEnter marks (0-100):" << endl;
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            cout << "Student " << (r + 1) << ", Subject " << (c + 1) << ": ";
            cin >> *(*(marks + r) + c);   // *(marks + r) -> row pointer r
                                          // + c then *   -> element in column c
        }
    }

    // Display the matrix (pointer notation again)
    cout << "\nMarks matrix:" << endl;
    for (int r = 0; r < rows; r++) {
        cout << "Student " << (r + 1) << ": ";
        for (int c = 0; c < cols; c++) {
            cout << *(*(marks + r) + c) << "\t";
        }
        cout << endl;
    }

    // Part 4: totals and the highest scorer 
    // Start by assuming student 1 is the best, then compare the rest.
    int bestTotal = 0;
    int bestStudent = 1;

    cout << "\nStudent totals:" << endl;
    for (int r = 0; r < rows; r++) {
        int studentTotal = 0;             // reset for each student
        for (int c = 0; c < cols; c++) {
            studentTotal += *(*(marks + r) + c);
        }
        cout << "  Student " << (r + 1) << " total = " << studentTotal << endl;

        // Strict ">" means that on a TIE the FIRST student is kept,
        // because a later equal total does not replace the stored one.
        if (r == 0 || studentTotal > bestTotal) {
            bestTotal = studentTotal;
            bestStudent = r + 1;
        }
    }

    cout << "\nTop student: Student " << bestStudent
         << " with a total of " << bestTotal << endl;

    // Part 5: release memory in the CORRECT order
    for (int r = 0; r < rows; r++) {
        delete[] marks[r];       // free every row block FIRST
    }
    delete[] marks;              // then free the array of row pointers
    marks = nullptr;

    cout << "\nAll memory released and pointer set to nullptr." << endl;
    return 0;
}
