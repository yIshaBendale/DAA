#include <iostream>
#include <vector>

using namespace std;

void swap(int& a, int& b) 
{
    int temp = a;
    a = b;
    b = temp;
}

int sort(vector<int>& arr, int left, int right) 
{
    int pivot = arr[left];
    int i = left + 1;
    int j = right;

    while (i <= j) 
    {
        while (i <= j && arr[i] <= pivot) 
        {
            i++;
        }

        while (i <= j && arr[j] >= pivot) 
        {
            j--;
        }

        if (i <= j) 
        {
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[left], arr[j]); 

    return j;  
}

void quicksort(vector<int>& arr, int left, int right) 
{
    if (left < right) 
    {
        int new_pivot = sort(arr, left, right);

        quicksort(arr, left, new_pivot - 1);
        quicksort(arr, new_pivot + 1, right); 
    }
}

int main() 
{
    int n;

    cout << "Enter the number of elements in the array: ";
    cin >> n;

    vector<int> arr(n);

    cout << "Enter the array elements:" << endl;
    for (int i = 0; i < n; i++) 
    {
        cin >> arr[i];
    }

    int left = 0;
    int right = n - 1;

    quicksort(arr, left, right);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) 
    {
        cout << arr[i] << " ";
    }

    return 0;
}

// Divide and conqure
// TC: best,avg: O(nlogn) worst:O(n^2)
// SC: O(n^2)