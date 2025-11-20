#include <iostream>
using namespace std;
void heapifyMax(int arr[], int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < n && arr[left] > arr[largest])
        largest = left;
    if (right < n && arr[right] > arr[largest])
        largest = right;
    if (largest != i) {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        heapifyMax(arr, n, largest);
    }
}
void heapifyMin(int arr[], int n, int i)
{
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < n && arr[left] < arr[smallest])
        smallest = left;
    if (right < n && arr[right] < arr[smallest])
        smallest = right;
    if (smallest != i) {
        int temp = arr[i];
        arr[i] = arr[smallest];
        arr[smallest] = temp;
        heapifyMin(arr, n, smallest);
    }
}
void heapSortIncreasing(int arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        heapifyMax(arr, n, i);

    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        heapifyMax(arr, i, 0);
    }
}
void heapSortDecreasing(int arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        heapifyMin(arr, n, i);

    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        heapifyMin(arr, i, 0);
    }
}
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}
int main()
{
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    int arr[100];
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int choice;
    cout << "\n1. Sort in Increasing Order\n2. Sort in Decreasing Order\n";
    cout << "Enter your choice: ";
    cin >> choice;
    if (choice == 1) {
        heapSortIncreasing(arr, n);
        cout << "\nArray sorted in Increasing order:\n";
        printArray(arr, n);
    }
    else if (choice == 2) {
        heapSortDecreasing(arr, n);
        cout << "\nArray sorted in Decreasing order:\n";
        printArray(arr, n);
    }
    else {
        cout << "Invalid choice!";
    }
    return 0;
}

