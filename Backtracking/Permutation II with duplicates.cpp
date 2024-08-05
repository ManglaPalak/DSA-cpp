void solve(vector<int>& nums,int index,vector<vector<int>>& result){
        if (index==nums.size()){
            result.push_back(nums);
            return;
        }
        for(int i=index;i<nums.size();i++){
            swap(nums[index],nums[i]);
            solve(nums,index+1,result);
            swap(nums[index],nums[i]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> result;
        solve(nums,0,result);
        sort(result.begin(),result.end());
        vector<vector<int>> op;
        op.push_back(result[0]);
        for(int i=1;i<result.size();i++){
            if (result[i-1]==result[i]){
                continue;
            }
            op.push_back(result[i]);
        }
        return op;
    }
