bool canJump(vector<int>& nums) {
        int maxlimit=nums[0];
        for(int i=1;i<nums.size();i++){
            if (i>maxlimit){
                return false;
            }
            maxlimit=max(maxlimit,i+nums[i]);
        }
        return true;
    }
