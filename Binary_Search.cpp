#include <bits/stdc++.h>
using namespace std;

int IterativeBinarySearch(int A[], int n, int target)
{
    int low = 0, high = n - 1, mid;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (A[mid] == target)
            return mid;

        else if (target > A[mid])
            low = mid + 1;

        else
            high = mid - 1;
    }
    return -1;
}

int RecursiveBinarySearch(int A[], int n, int target, int low, int high)
{
    int mid = (low + high) / 2;
    if (A[mid] == target)
        return mid;

    if (low > high)
        return -1;

    if (target < A[mid])
        return RecursiveBinarySearch(A, n, target, low, mid - 1);
    else
        return RecursiveBinarySearch(A, n, target, mid + 1, high);
}

int main()
{
    int n, target;
    cout << "Enter n : ";
    cin >> n;
    int A[n];
    cout << "Enter elements : ";
    for (int i = 0; i < n; i++)
        cin >> A[i];

    cout << "Enter target : ";
    cin >> target;

    sort(A, A + n);
    cout << "Sorted Array : ";
    for (int i = 0; i < n; i++)
        cout << A[i] << " ";

    cout << "\nAns by Iterative Binary Search : " << IterativeBinarySearch(A, n, target) << endl;
    cout << "\nAns by Recursive Binary Search : " << RecursiveBinarySearch(A, n, target, 0, n - 1) << endl;
    return 0;
}
