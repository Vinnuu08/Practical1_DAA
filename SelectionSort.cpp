#include <iostream>
#include <utility> // for std::swap
void selectionSort(int arr[], int n) {
   for (int i = 0; i < n - 1; ++i) {
       int minIndex = i; // assume current index has the smallest value
       for (int j = i + 1; j < n; ++j) {
           if (arr[j] < arr[minIndex]) {
               minIndex = j; // found a smaller element
           }
       }
       std::swap(arr[i], arr[minIndex]); // place smallest in correct position
   }
}
int main() {
   int arr[] = {30, 50, 20, 10, 40};
   int n = sizeof(arr) / sizeof(arr[0]);
   selectionSort(arr, n);
   std::cout << "Sorted array: ";
   for (int i = 0; i < n; ++i)
       std::cout << arr[i] << " ";
   std::cout << "\n";
   return 0;
}
