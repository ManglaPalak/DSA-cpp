int helper(vector<int>& bloom,int m,int k,int mid){
        int cnt=0;
        int ans=0;
        for(int i=0;i<bloom.size();i++){
            if (bloom[i]<=mid){
                cnt++;
            }
            else{
                ans+=(cnt/k);
                cnt=0;
            }
        }
        ans+=(cnt/k);
        return ans>=m;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int low=0;
        int high=0;
        int n=bloomDay.size();
        if (m*1LL*k*1LL > n){
            return -1;
        }
        for(int i=0;i<n;i++){
            low=min(low,bloomDay[i]);
            high=max(high,bloomDay[i]);
        }
        while(low<high){
            int mid=low+(high-low)/2;
            if(helper(bloomDay,m,k,mid)){
                high=mid;
            }
            else{
                low=mid+1;
            }
        }
        return low;
    }
