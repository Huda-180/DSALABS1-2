#include <iostream>
using namespace std;

// main function:Entry Point

int main()
{
    int numbers[5];
    // initializing array numbers with size 5(assuming user enters exactly 5 integers)

    int total = 0; // initializing total variable to store the sum of all elements of the array

    // using loop to read 5 integers from user
    for (int i = 0; i < 5; i++)
    {
        cout << "Enter " << i + 1 << " Element of Array : "; // prompting user to enter the element at index i
        cin >> numbers[i];                                   // reading the value of the array at index i from user
    }
    // using loop to calculate the sum of all elements of the array
    for (int i = 0; i < 5; i++)
    {
        total += numbers[i]; // adding the value of the array at index i to total
    }

    // displaying total
     cout << "The total Sum= " << total;
     
    return 0;
}