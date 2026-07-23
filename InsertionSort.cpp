#include <iostream>
#include <vector>
#include <limits> // For numeric_limits

using namespace std;

// Function to perform Insertion Sort
void insertionSort(vector<int> &arr) {
    int n = arr.size();
    for (int i = 1; i < n; i++) {
        int key = arr[i]; // Current element to insert
        int j = i - 1;

        // Move elements greater than key to one position ahead
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// Function to display the array
void displayArray(const vector<int> &arr) {
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
}

int main() {
    int n;

    cout << "Enter number of elements: ";
    if (!(cin >> n) || n <= 0) {
        cout << "Invalid input. Please enter a positive integer for size.\n";
        return 1;
    }

    vector<int> arr(n);

    cout << "Enter " << n << " integers: ";
    for (int i = 0; i < n; i++) {
        if (!(cin >> arr[i])) {
            cout << "Invalid input. Please enter integers only.\n";
            return 1;
        }
    }

    cout << "\nOriginal array: ";
    displayArray(arr);

    insertionSort(arr);

    cout << "Sorted array: ";
    displayArray(arr);

    return 0;
}
