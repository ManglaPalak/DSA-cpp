void solve(int arr[],int n,int i,int k,int& ans,int& sum){
	    if (sum>k){
	        return;
	    }
	    if (i==n){
	        if (sum==k){
	            ans++;
	        }
	        return;
	    }
	    //exclude
	    solve(arr,n,i+1,k,ans,sum);
	    //include
	    sum+=arr[i];
	    solve(arr,n,i+1,k,ans,sum);
	    sum-=arr[i];
	}
	int perfectSum(int arr[], int n, int sum)
	{
        int ans=0;
        int sum1=0;
        solve(arr,n,0,sum,ans,sum1);
        return ans;
	}
