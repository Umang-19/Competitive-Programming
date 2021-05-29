#include <bits/stdc++.h>
using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b)
{
    return a.second < b.second;
}

int main()
{
    vector<pair<int, int>> av;
    int n;
    cin >> n; // total activities
    for (int i = 0; i < n; i++)
    {
        int start, end;
        cin >> start >> end;
        av.push_back({start, end});
    }
    sort(av.begin(), av.end(), cmp);
    int ans = 1;
    pair<int, int> lastav = {av[0].first, av[0].second};
    for (int i = 1; i < n; i++)
    {
        if (av[i].first >= lastav.second)
        {
            ans++;
            lastav = {av[i].first, av[i].second};
        }
    }
    cout << ans << endl;
    return 0;
}