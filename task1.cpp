#include<iostream>
using namespace std;

//main function:Entry Point

int main() {
    int numbers[5]={2,4,6,8,10}; //creating array numbers with elements 2,4,6,8,10

    numbers[2]=7; //changing the value of the 3rd element of the array to 7
     
    //using for loop to display all five values separated by space
    for(int i=0;i<5;i++){
        cout<<numbers[i]<<" "; //displaying the value of the array at index i
    }
    //predicting output: 2 4 7 8 10
    return 0;
}

    
    

