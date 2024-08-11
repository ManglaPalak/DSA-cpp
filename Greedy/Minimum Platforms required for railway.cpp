int findPlatform(int arr[], int dep[], int n){
        sort(arr,arr+n);
        sort(dep,dep+n);
        int maxcnt=0;
        int cnt=0;
        int i=0;
        int j=0;
        while(i<n){
            if (arr[i]<=dep[j]){
                cnt++;
                i++;
            }
            else{
                cnt--;
                j++;
            }
            maxcnt=max(maxcnt,cnt);
        }
        return maxcnt;
    }
