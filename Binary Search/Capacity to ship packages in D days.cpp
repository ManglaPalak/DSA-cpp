bool possible(vector<int>& a,int n,int m ,int mid){
        int sum=0,c=1;
        for(int i=0;i<n;i++){
            if(a[i]>mid)
            return false;
            if(sum+a[i]>mid)
            {
                c++;
                sum=a[i];
                if(c>m)
                    return false;
            }
            else
            sum+=a[i];
        }
        return true;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int n=weights.size();
        int s=0,mid,ans=-1;
        int e=accumulate(weights.begin(),weights.end(),0);

        while(s<=e){
            mid=s+(e-s)/2;
            if(possible(weights,weights.size(),days,mid))
            {
                ans=mid;
                e=mid-1;
            }
            else
            s=mid+1;
        }
        return ans;
    }
