#pragma once
#include <utility>

struct pair {
    int first;
    int second;
};

int findIndex(int arr[], int size, int num);

std::pair<int, int> modifyInt(int arr[], int size, int index,int newVal);

int insertInteger(int arr[], int size, int insertVal, int capacity);

int deletion(int arr[], int size, int index, bool del);

