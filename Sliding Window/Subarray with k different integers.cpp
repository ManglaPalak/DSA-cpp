int solve(vector<int>& nums, int k){
        unordered_map<int,int> mp;
        int l=0;
        int r=0;
        int cnt=0;
        while(r<nums.size()){
            mp[nums[r]]++;
            while(mp.size()>k){
                mp[nums[l]]--;
                if (mp[nums[l]]==0){
                    mp.erase(nums[l]);
                }
                l++;
            }
            if (mp.size()<=k){
                cnt+=(r-l);
            }
            r++;
        }
        return cnt;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return solve(nums,k)-solve(nums,k-1);
    }
