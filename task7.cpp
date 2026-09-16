#include<iostream>
using namespace std;

//main function:Entry Point

int main() {
   int numbers[10];//initializing array of 10 integers
    //using loop to read 10 integers from user
    for(int i=0;i<10;i++){
        cout<<"Enter "<<i+1<<" Element of Array : "; //prompting user to enter the element at index i
        cin>>numbers[i]; //reading the value of the array at index i from user
        
    }

    //moving first occurence of each value to the front of the array and removing duplicates
    int j=0; //initializing j variable to store the index of the next unique
    for(int i=0;i<10;i++){
        int k; //initializing k variable to check if the value of the array at index i is unique
        for(k=0;k<j;k++){
            if(numbers[i]==numbers[k]){ 
                //checking if the value of the array at index i is equal to any of the previous values
                break; //breaking the loop if the value is not unique
            }
        }
        if(k==j){ //checking if the value is unique
            numbers[j]=numbers[i]; //moving the unique value to the front of the array
            j++; //incrementing j to point to the next unique value
        }
    }
    //displaying unique values and count of unique values
    cout<<"The Unique Values are: "; //displaying the label for unique values
    for(int i=0;i<j;i++){
        cout<<numbers[i]<<" "; //displaying the unique value at index i
    }
    cout<<endl; //moving to the next line
    cout<<"Count of Unique Values: "<<j<<endl; //displaying the count of unique values

    return 0;
}