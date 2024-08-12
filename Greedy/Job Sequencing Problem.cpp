/*
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
*/

class Solution 
{
    public:
    bool static comp(Job a,Job b){
        return a.profit > b.profit ;
    }
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n) {
        sort(arr,arr+n,comp);
        int cnt=0;
        int maxprofit=0;
        int maxdeadline=0;
        for(int i=0;i<n;i++){
            maxdeadline=max(maxdeadline,arr[i].dead);
        }
        vector<int> track(maxdeadline,-1);
        for(int i=0;i<n;i++){
            for(int j=arr[i].dead-1;j>=0;j--){
                if (track[j]==-1){
                    cnt++;
                    maxprofit+=arr[i].profit;
                    track[j]=arr[i].id;
                    break;
                }
            }
        }
        return {cnt,maxprofit};
    } 
};
