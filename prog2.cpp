#include <iostream>
#include <vector>

using namespace std;
//class for sorting and serching algorithms 
class Sorting_And_Searching
{
public:
    int partition(vector<int> &arr, int start, int end)
    {
        int pivot = arr[end];
        int i = start - 1;
        for (int j = start; j < end; j++)
        {
            if (arr[j] <= pivot)
            {
                swap(arr[++i], arr[j]);
            }
        }
        swap(arr[++i], arr[end]);
        return i;
    }
        // Function to perform Quicksort 
    int Quick_sort(vector<int> &arr, int start, int end)
    {
        if (start >= end)
        {
            return 1;
        }
        int pivotindex = partition(arr, start, end);
        Quick_sort(arr, start, pivotindex - 1);
        Quick_sort(arr, pivotindex + 1, end);
    }
        // Function to perform merge
    void Merge(vector<int> &arr, int start, int mid, int end)
    {
        vector<int> temp;
        int i = start, j = mid + 1;

        while (i <= mid && j <= end)
        {
            if (arr[i] <= arr[j])
            {
                temp.push_back(arr[i++]);
            }
            else
            {
                temp.push_back(arr[j++]);
            }
        }
    }
    
    // Function to perform merge sort
    int Merge_Sort(vector<int> &arr, int start, int end)
    {
        if (start >= end)
            return 0;
        int mid = start + (end - start) / 2;

        Merge_Sort(arr, start, mid);
        Merge_Sort(arr, mid + 1, end);
        Merge(arr, start, mid, end);
    }
    // Function to perform binary search
    int Binary_Search(vector<int> &arr, int target)
    {
        int start = 0;
        int end = arr.size() - 1;

        while (start <= end)
        {
            int mid = (start + end) / 2;

            if (arr[mid] == target)
            {
                return mid;
            }
            else if (arr[mid] < target)
            {
                start = mid + 1;
            }
            else
            {
                end = mid - 1;
            }
        }
        return -1;
    }
    //function for printing arrey
    void Print_Array(vector<int> &arr, int n)
    {
        cout << endl;
        cout << "Array is : ";
        for (int i = 0; i < n; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    int choice, value, n, element, result, key;

    Sorting_And_Searching sort;

    cout << "Enter the size of the array: ";
    cin >> n;

    vector<int> arr(n);

    for (int i = 0; i < arr.size(); i++)
    {
        cout << "Enter the element at index [" << i << "]: ";
        cin >> arr[i];
    }
    do
    {
        cout << "\n-------- MENU --------\n";
        cout << "Enter  1 For Quick Sort " << endl;
        cout << "Enter  2 Merge Sort" << endl;
        cout << "Enter  3 Binary Search" << endl;
        cout << "Enter  4 Print Array" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            sort.Quick_sort(arr, 0, arr.size() - 1);
            cout << "Quick sort :" << endl;
            sort.Print_Array(arr, n);
            break;
        case 2:
            sort.Merge_Sort(arr, 0, arr.size() - 1);
            cout << "Array sorting using merge sort" << endl;
            sort.Print_Array(arr, arr.size());

            break;
        case 3:
            int result;
            cout << "Enter value to search (Binary):";
            cin >> element;
            result = sort.Binary_Search(arr, element);
            if (result != -1)
            {
                cout << "Element at : " << result << endl;
            }
            else
            {
                cout << "Element not found!" << endl;
            }
            break;
        case 4:
            sort.Print_Array(arr, n);
            break;
        case 0:
            cout << "Exiting....." << endl;
            break;
        default:
            cout << "Invalid choice!" << endl;
        }
    } while (choice != 0);

    return 0;
}