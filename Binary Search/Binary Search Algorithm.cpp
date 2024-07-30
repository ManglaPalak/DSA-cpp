int search(vector<int>& nums, int target) {
        if (nums.size()==1){
            if (nums[0]==target){
                return 0;
            }
            return -1;
        }
        int s=0;
        int e=nums.size();
        int mid=s+(e-s)/2;
        while(s<=e){
            if (nums[mid]==target){
                return mid;
            }
            else if (nums[mid]<target){
                s=mid+1;
            }
            else{
                e=mid-1;
            }
            mid=s+(e-s)/2;
        }
        return -1;
    }
