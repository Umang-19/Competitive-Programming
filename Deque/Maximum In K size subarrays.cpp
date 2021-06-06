#include<bits/stdc++.h>
using namespace std;

int main()
{
    int arr[7] = {5, 10, 8, 12, 15, 7, 6};
    int k = 3;
    int i =0, j = 0;
    deque<int> dq;
    
    while(j < 7)
    {
        if(dq.empty())
            dq.push_back(arr[j]);
        else 
        {
            while(!dq.empty() && dq.front() < arr[j])
                dq.pop_front();
            
            dq.push_back(arr[j]);
        }
        
        if(j - i + 1 < k)
            j++;
        else 
        {
            cout << dq.front() << endl;
            i++;
            j++;
        }
    }
    return 0;
}