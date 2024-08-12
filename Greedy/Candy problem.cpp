// ################################### BRUTE FORCE APPROACH ######################################################
int candy(vector<int>& ratings) {
        int n=ratings.size();
        vector<int> left(n);
        vector<int> right(n);
        left[0]=1;
        right[n-1]=1;
        for(int i=1;i<n;i++){
            if (ratings[i]>ratings[i-1]){
                left[i]=left[i-1]+1;
            }
            else{
                left[i]=1;
            }
        }
        for(int i=n-2;i>=0;i--){
            if (ratings[i]>ratings[i+1]){
                right[i]=right[i+1]+1;
            }
            else{
                right[i]=1;
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            ans+=max(left[i],right[i]);
        }
        return ans;
    }

// ######################################## OPTIMAL APPROACH (SLOPE METHOD) ########################################################
int candy(vector<int>& ratings) {
        // using slope method
        int sum=1;
        int n=ratings.size();
        int i=1;
        while(i<n){
            while(i<n && ratings[i]==ratings[i-1]){
                sum+=1;
                i++;
                continue;
            }
            int peak=1;
            while(i<n && ratings[i]>ratings[i-1]){
                peak++;
                sum+=peak;
                i++;
            }
            int down=1;
            while(i<n && ratings[i]<ratings[i-1]){
                sum+=down;
                down++;
                i++;
            }
            if (down>peak){
                sum+=(down-peak);
            }
        }
        return sum;
    }
