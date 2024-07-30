int minEatingSpeed(vector<int>& piles, int h) {
        int low=1;
        int high=0;
        for(int i=0;i<piles.size();i++){
            high=max(high,piles[i]);
        }
        while(low<high){
            int mid=low+(high-low)/2;
            int total=0;
            for(int i=0;i<piles.size();i++){
                total=total+ceil((double)piles[i]/mid);
            }
            if (total>h){
                low=mid+1;
            }
            else{
                high=mid;
            }
        }
        return low;
    }
