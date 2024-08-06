int solve(vector<int>& nums,int k){
        if(k<0){
            return 0;
        }
        int l=0;
        int r=0;
        int cnt=0;
        int odd=0;
        while(r<nums.size()){
            if (nums[r]%2){
                odd++;
            }
            while(odd>k){
                if (nums[l]%2){
                    odd--;
                }
                l++;
            }
            if (odd<=k){
                cnt+=(r-l+1);
            }
            r++;
        }
        return cnt;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return solve(nums,k)-solve(nums,k-1);
    }
