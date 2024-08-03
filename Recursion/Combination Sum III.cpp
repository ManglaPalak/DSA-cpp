void solve(vector<int>& nums,int elements,int target,int index,vector<vector<int>>& result,vector<int>& ans){
        if (elements==0 && target==0){
            result.push_back(ans);
            return;
        }
        if (elements==0 && target!=0){
            return;
        }
        if (target<0){
            return;
        }
        if (index==nums.size()){
            return;
        }
        //exclude
        solve(nums,elements,target,index+1,result,ans);
        //include
        ans.push_back(nums[index]);
        solve(nums,elements-1,target-nums[index],index+1,result,ans);
        ans.pop_back();
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> result;
        vector<int> ans;
        vector<int> nums={1,2,3,4,5,6,7,8,9};
        solve(nums,k,n,0,result,ans);
        return result;
    }
