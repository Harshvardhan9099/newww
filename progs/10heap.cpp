#include<iostream>
using namespace std;

// Insert into min heap
void insertMinHeap(int arr[], int i) {
    while (i > 0 && arr[(i - 1) / 2] > arr[i]) {
        swap(arr[i], arr[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

// Insert into max heap
void insertMaxHeap(int arr[], int i) {
    while (i > 0 && arr[(i - 1) / 2] < arr[i]) {
        swap(arr[i], arr[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

int main() {
    int arr[100], n;
    cout << "Enter the total number: ";
    cin >> n;

    cout << "Enter the numbers: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Build min heap
    for (int i = 1; i < n; i++) {
        insertMinHeap(arr, i);
    }
    cout << "Min value is: " << arr[0] << endl;

    // Build max heap
    for (int i = 1; i < n; i++) {
        insertMaxHeap(arr, i);
    }
    cout << "Max value is: " << arr[0] << endl;

    return 0;
}

