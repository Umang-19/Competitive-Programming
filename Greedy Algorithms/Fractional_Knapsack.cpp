#include<bits/stdc++.h>
using namespace std;

bool cmp(pair<int,int> a, pair<int,int> b)
{
    double ax = (double)a.second / a.first;
    double bx = (double)b.second / b.first;
    return ax > bx;
}

int main()
{
    int n, w;
    cin >> n; // No. of items
    vector<pair<int,int>> items; 
    for(int i = 0 ; i < n ; i++)
    {
        int wt,val;
        cin >> wt >> val;
        items.push_back({wt,val});
    }
    cin >> w ; // Knapsack Capacity

    sort(items.begin(), items.end(), cmp);
    // cout << "Items : ";
    // for(auto x : items)
    //     cout << x.first << " " << x.second << endl;
    
    double res = 0.0;
    int currcap = w;
    for(int i = 0 ; i < n ; i++)
    {
        if(items[i].first <= currcap)
        {
            currcap -= items[i].first;
            res += items[i].second;
        }
        else 
        {
            res += items[i].second * ((double)currcap / items[i].first);
            break;
        }
    }
    cout << res << endl;
    return 0;
}