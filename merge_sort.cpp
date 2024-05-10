// merge sort
#include <iostream>
using namespace std;

int left_subarray[50], right_subarray[50];

void merge(int arr[], int low, int mid, int high)
{
    int n1 = mid - low + 1;
    int n2 = high - mid;

    for (int i = 0; i < n1; i++)
    {
        left_subarray[i] = arr[low + i];
    }
    for (int j = 0; j < n2; j++)
    {
        right_subarray[j] = arr[mid + 1 + j];
    }

    int i = 0;   // initial index of left subarray
    int j = 0;   // initial index of right subarray
    int k = low; // initial index of merged array

    while (i < n1 && j < n2)
    {
        if (left_subarray[i] <= right_subarray[j])
        {
            arr[k] = left_subarray[i];
            i++;
        }
        else
        {
            arr[k] = right_subarray[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = left_subarray[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = right_subarray[j];
        j++;
        k++;
    }
}

void mergesort(int arr[], int low, int high)
{
    if (low < high)
    {
        int mid = low + (high - low) / 2;
        mergesort(arr, low, mid);
        mergesort(arr, mid + 1, high);
        merge(arr, low, mid, high);
    }
}

void display(int arr[], int n)
{
    cout << "Sorted array is: \n";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";
}

int main()
{
    int n, arr[50];
    cout << "Enter the number of elements in array: ";
    cin >> n;
    cout << "Enter array elements:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    mergesort(arr, 0, n - 1);

    display(arr, n);

    return 0;
}

// divide and conqure
// TC: O(nlogn)
// SC: O(n)