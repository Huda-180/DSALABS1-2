#include<iostream>
using namespace std;

//main function:Entry Point

int main() {
   int numbers[8];//initializing array of 8 integers
    //using loop to read 8 integers from user
    for(int i=0;i<8;i++){
        cout<<"Enter "<<i+1<<" Element of Array : "; //prompting user to enter the element at index i
        cin>>numbers[i]; //reading the value of the array at index i from user
        
    }

    int max=numbers[0]; //initializing max variable to store the maximum value of the array
    int min=numbers[0]; //initializing min variable to store the minimum value of the array
    int index_max=0; //initializing index_max variable to store the index of the maximum value of the array
    int index_min=0; //initializing index_min variable to store the index of the

    //using loop to find the maximum and minimum value of the array
    for(int i=0;i<8;i++){
        //finding maximum value
        if(numbers[i]>max){ //checking if the value of the array at index i is greater than max
            max=numbers[i]; //updating max to the value of the array at index i
            index_max=i; //updating index_max to the index of the maximum value
        }
        //finding minimum value
        if(numbers[i]<min){ //checking if the value of the array at index i is less than min
            min=numbers[i]; //updating min to the value of the array at index i
            index_min=i; //updating index_min to the index of the minimum value
        }
    }
 //displaying the maximum value and its index
   cout<<"The Maximum Value is: "<<max<<" at index "<<index_max<<endl;
   //displaying the minimum value and its index

    cout<<"The Minimum Value is: "<<min<<" at index "<<index_min<<endl; 
    //checking if a value occurs more than once in the array and reporting its first occurence index
    for(int i=0;i<8;i++){
        for(int j=i+1;j<8;j++){
            if(numbers[i]==numbers[j]){ 
    //checking if the value of the array at index i is equal to the value of the array at index j
                cout<<"The Value "<<numbers[i]
                <<" occurs more than once in the array and its first occurence is at index "
              <<i<<endl; 

                //displaying the value and its first occurence index
                break; //breaking the loop after finding the first occurence
            }
        }
    }

    return 0;
}