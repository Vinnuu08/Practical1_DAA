#include <iostream>
#include <vector>
using namespace std;
// Function to perform Bubble Sort
void bubbleSort(vector<int>& arr) {
   int n = arr.size();
   for (int i = 0; i < n - 1; i++) {
       bool swapped = false; // Optimization: Track if any swaps occurred
       for (int j = 0; j < n - i - 1; j++) {
           if (arr[j] > arr[j + 1]) {
               swap(arr[j], arr[j + 1]);
               swapped = true;
           }
       }
       // If no swaps occurred, the array is already sorted
       if (!swapped) break;
   }
}
int main() {
   vector<int> numbers = {64, 34, 25, 12, 22, 11, 90};
   cout << "Original List: ";
   for (int num : numbers) cout << num << " ";
   cout << endl;
   bubbleSort(numbers);
   cout << "Sorted List: ";
   for (int num : numbers) cout << num << " ";
   cout << endl;
   return 0;
}
