#include <iostream>
using namespace std;

int main()
{
    int n = 3;

    int *values = new int[n]; // allocate 3 integers: valid indices 0, 1, 2

    // FIX 1: the condition is i < n, so the loop stops at index 2.
    //        Using i <= n would touch values[3], which was never allocated.
    cout << "Enter " << n << " integers:" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "Value " << (i + 1) << ": ";
        cin >> *(values + i);
    }

    // Display BEFORE releasing the memory - once it is freed the
    // elements no longer belong to this program.
    cout << "\nValues entered: ";
    for (int i = 0; i < n; i++)
    {
        cout << *(values + i) << " ";
    }
    cout << endl;

    // FIX 2: memory from new[] must be released with delete[],
    //        so that the whole array block is freed correctly.
    delete[] values;

    // FIX 3: reset the pointer instead of reading through it.
    //        Reading values[0] after deletion is a dangling access.
    values = nullptr;

    cout << "Memory released correctly and pointer reset to nullptr." << endl;
    return 0;
}