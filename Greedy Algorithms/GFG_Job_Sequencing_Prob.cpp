bool cmp(Job a, Job b)
{
    return a.profit > b.profit; 
}

class Solution 
{
    public:
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        sort(arr, arr + n , cmp);
        vector<int> ans;
        
        int mxprofit = arr[0].profit;
        int countjob = 1;
        int mxdead = 1;
        for(int i = 0; i < n ; i++)
        {
            if(arr[i].dead > mxdead)
                mxdead = arr[i].dead;
        }
        
        vector<bool> isemp(mxdead,true);
        isemp[arr[0].dead - 1] = false; // Assigning latest poss slot to 1st job in sorted jobs
        
        for(int i = 1 ; i < n ; i++)
        { 
            int x = arr[i].dead - 1;
            
            while(x >= 0)
            {
                if(isemp[x])
                {
                    isemp[x] = false;
                    countjob++;
                    mxprofit += arr[i].profit;
                    break;
                }
                x--;
            }
        }
        ans.push_back(countjob);
        ans.push_back(mxprofit);
        return ans;
    } 
};