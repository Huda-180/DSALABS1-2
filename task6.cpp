#include<iostream>
using namespace std;

//main function:Entry Point

int main() {
   int numbers[6];//initializing array of 6 integers
    //using loop to read 6 integers from user
    for(int i=0;i<6;i++){
        cout<<"Enter "<<i+1<<" Element of Array : "; //prompting user to enter the element at index i
        cin>>numbers[i]; //reading the value of the array at index i from user
        
    }
    cout<<"The Original Array is: "<<endl; //displaying the label for original array
    for(int i=0;i<6;i++){
        cout<<numbers[i]<<" "; //displaying the value of the array at index i
    }
    cout<<"\nThe Reversed Array is: "<<endl; //displaying the label for reversed array
    
   //using loop to reverse the array
    for(int i=0;i<3;i++){
        int temp=numbers[i]; //storing the value of the array at index i in temp variable
        numbers[i]=numbers[5-i]; //swapping the value of the array at index i with the value of the array at index 5-i
        numbers[5-i]=temp; //storing the value of temp variable in the array at index 5-i
    }
    //using loop to display all six values separated by space
    for(int i=0;i<6;i++){
        cout<<numbers[i]<<" "; //displaying the value of the array at index i
    }
   return 0;
}