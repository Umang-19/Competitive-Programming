#include <bits/stdc++.h>
using namespace std;

int IBS(vector<int> v, int n, int target)
{
    int low = 0, high = n - 1, mid;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (v[mid] == target)
            return mid;

        else if (target > v[mid])
            low = mid + 1;

        else
            high = mid - 1;
    }
    return -1;
}

int RBS(vector<int> A, int n, int target, int low, int high)
{
    int mid = (low + high) / 2;
    if (A[mid] == target)
        return mid;

    if (low > high)
        return -1;

    if (target < A[mid])
        return RBS(A, n, target, low, mid - 1);
    else
        return RBS(A, n, target, mid + 1, high);
}

int main()
{
    int n, target;
    cout << "Enter n : ";
    cin >> n;
    vector<int> v;
    cout << "Enter elements : ";
    for (int i = 0; i < n; i++)
    { 
        int x;
        cin >> x;
        v.push_back(x);
    }

    cout << "Enter target : ";
    cin >> target;

    sort(v.begin(), v.end());
    cout << "Sorted Array : ";
    for (int i = 0; i < n; i++)
        cout << v[i] << " ";

    cout << "\nAns by Iterative Binary Search : " << IBS(v, n, target) << endl;
    cout << "\nAns by Recursive Binary Search : " << RBS(v, n, target, 0, n - 1) << endl;
    return 0;
}
