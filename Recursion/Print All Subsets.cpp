void allsubsets(vector<int>& nums,int index,vector<vector<int>>& result,vector<int>& ans){
        if (index>=nums.size()){
            result.push_back(ans);
            return;
        }
        //exclude
        allsubsets(nums,index+1,result,ans);
        //include
        ans.push_back(nums[index]);
        allsubsets(nums,index+1,result,ans);
        ans.pop_back();
        
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> ans;
        allsubsets(nums,0,result,ans);
        return result;
    }
