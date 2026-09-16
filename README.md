 DSA Lab 01

Name:NOOR-UL-HUDA
Registration Number:542148 

Program Descriptions
Task 1: Declaring and initializing an array and changing its element then displaying new array
Task 2: Declaring an array and reading values from user then print sum of elements of array
Task 3:Creating class Student along with 2 objects and displaying and modifying data using objects 
Task 4: reading 8 integers displaying maximum and minimum and first occurence of a repeated digit
Task 5:same as task 4
Task 6:reversing an array without using another array
Task 7:taking an array and displaying only the unique occurences along with number of unique occurences preserving order
Task 8:initializing repo and editing later

Task 3 Test Results (Task 3 only has 2 test cases)
Test Case 1 Result: 
Details of Student 1:
Roll Number: 1
Marks: 75
Details of Student 2:
Roll Number: 2
Marks: 90

Test Case 2 Result: 
Details of Student 1:
Roll Number: 1
Marks: 75
Details of Student 2:
Roll Number: 2
Marks: 90
After changing marks of Student 1:
Details of Student 1:
Roll Number: 1
Marks: 80
Details of Student 2:
Roll Number
Marks:90



DSA LAB 2:
lab 2 inside a separate folder named lab 2 with .cpp files



This lab develops an understanding of one-dimensional and two-dimensional arrays in C++, with all element access performed through pointer expressions rather than ordinary subscript notation. Across six tasks, array sizes are first fixed at compile time and then chosen at runtime, memory is allocated on the heap with new[], used, expanded by copying into a larger block, and finally released with delete[].
The tasks progress from a static five-element array accessed through an int* (Task 1), to a runtime-sized one-dimensional array (Task 2), to a static two-dimensional array reached through a row pointer of type int (*)[3] (Task 3), to a fully dynamic matrix built from an array of row pointers (Task 4). Task 5 demonstrates that a heap block cannot grow in place and must be replaced by a larger copy, and Task 6 diagnoses and repairs a faulty fragment containing an out-of-bounds write, a mismatched deallocation and a dangling-pointer read.


