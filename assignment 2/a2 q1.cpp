#include <iostream>
using namespace std;
int binarySearch(int arr[], int n, int wanted) {
    int start = 0, end = n - 1;
    while (start <= end) {
        int mid = start + (end - start) / 2; 
        if (arr[mid] == wanted) 
            return mid; 
        else if (arr[mid] < wanted) 
            start = mid + 1; 
        else 
            end = mid - 1; 
    }
    return -1; 
}
int main() {
    int n, wanted;
    cout << "Enter number of elements (sorted array): ";
    cin >> n;

    int arr[n];
    cout << "Enter elements in sorted order: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << "Enter element to search: ";
    cin >> wanted;
    int result = binarySearch(arr, n, wanted);
    if (result != -1)
        cout << "Element found at index " << result << endl;
    else
        cout << "Element not found" << endl;
    return 0;
}

