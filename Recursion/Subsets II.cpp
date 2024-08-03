void solve(vector<int>& nums,int index,vector<vector<int>>& result,vector<int>& ans){
        if (index==nums.size()){
            result.push_back(ans);
            return;
        }
        //include 
        ans.push_back(nums[index]);
        solve(nums,index+1,result,ans);
        ans.pop_back();
        //exclude
        int i=1;
        while(index+i<nums.size() && nums[index+i]==nums[index]){
            i++;
        }
        solve(nums,index+i,result,ans);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> ans;
        sort(nums.begin(),nums.end());
        solve(nums,0,result,ans);
        return result;
    }
