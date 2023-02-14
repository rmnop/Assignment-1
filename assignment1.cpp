#include <iostream>
#include <fstream>
#include <utility>
#include "function.h"

using namespace std;

int findIndex(int arr[], int size, int num) {
    for(int i = 0; i < size; i++) {
        if(arr[i] == num) {
            return i;
        }
    }
    return -1;
}


std::pair<int,int> modifyInt(int arr[], int size, int index, int newVal) {
    int oldVal = arr[index];
    arr[index] = newVal;

    return make_pair(oldVal,newVal);
    //pair<T1,T2> make_pair (T1 x, T2 y);
}

int insertInteger(int arr[], int size, int insertVal, int capacity) {
    if(size >= capacity) {
        return size;
    }    
    
    //arr size = new array with added element
    arr[size] = insertVal;

    //size + 1 so the array iterates through all the elements
    return (size + 1);
}

int deletion(int arr[], int size, int index, bool del) {
    if (del) {
        // shift all elements after the specified index one position to the left
        for (int i = index; i < size - 1; i++) {
            arr[i] = arr[i + 1];
        }
        //deletes last index
        return(size - 1);
    } else {
        // replace the value at the specified index with 0
        arr[index] = 0;
    }
    //returns the size of the array if it was switched to 0 or deleted
    return size;
}
    
int main() {
    fstream readFile;
    readFile.open("array.txt");
    int arr[20];
    int capacity = sizeof(arr) / sizeof(arr[0]);
    int size = 10;
    
    if(!readFile.good()) {
        cout << "File didn't open" << endl;
    }
        for(int i = 0; i < size; i++) {
            readFile >> arr[i];
            //cout << arr[i] << " ";
        }

    int number = 2;
    int search = findIndex(arr, size, number);
    if(arr[search] == number) {
        cout << number << " is in index " << search << endl;
    } else {
        cout << number << " is not in index" << endl;
    }

    cout << endl;

    int index = 2;
    int newInteger = 22;
    cin.exceptions(std::istream::failbit);
        try {
            std::pair<int, int> indexes = modifyInt(arr, size, index, newInteger);
            cout << "index " << index << " is now " << indexes.second << endl;
            cout << "index " << index << " before was " << indexes.first << endl;
            cout << endl;
        } catch(...) {
            cout << "There was an error in the function";
        }


    cout << "The array before insertion: " << endl;
    for(int i = 0; i < size; i++) {
        cout << arr[i] << " ";

    }
    cout << endl;

    cout << "The array after insertion: " << endl;
    try {
    int insertVal = 47;
    size = insertInteger(arr, size, insertVal, capacity);
    for(int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    } catch(...) {
        cout << "There was an error in the function" << endl;
    }
    cout << endl << endl;


    cout << "Array after replacement or deletion: " << endl;
    index = 1;
    bool del = true;
    size = deletion(arr, size, index, del);
    for(int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
   return 0;
}
