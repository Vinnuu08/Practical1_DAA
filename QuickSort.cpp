#include <iostream>
#include <vector>
#include <limits> // For numeric_limits

using namespace std;

// Function to swap two elements
void swapElements(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

// Partition function using Lomuto partition scheme
int partition(vector<int> &arr, int low, int high) {
    int pivot = arr[high]; // Choosing last element as pivot
    int i = low - 1;       // Index of smaller element

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swapElements(arr[i], arr[j]);
        }
    }
    swapElements(arr[i + 1], arr[high]);
    return i + 1;
}

// QuickSort function (recursive)
void quickSort(vector<int> &arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        // Recursively sort elements before and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Function to safely read integers from user
bool readInt(int &num) {
    cin >> num;
    if (cin.fail()) {
        cin.clear(); // Clear error flag
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
        return false;
    }
    return true;
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    if (!readInt(n) || n <= 0) {
        cout << "Invalid input. Please enter a positive integer.\n";
        return 1;
    }

    vector<int> arr(n);
    cout << "Enter " << n << " integers:\n";
    for (int i = 0; i < n; i++) {
        if (!readInt(arr[i])) {
            cout << "Invalid input. Please enter integers only.\n";
            return 1;
        }
    }

    quickSort(arr, 0, n - 1);

    cout << "Sorted array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << "\n";

    return 0;
}
