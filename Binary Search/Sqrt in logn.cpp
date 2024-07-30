long long int floorSqrt(long long int x) 
    {
        long long int l=1;
        long long int h=x;
        while(l<=h){
            long long int mid=(l+h)/2;
            if (mid*mid<=x){
                l=mid+1;
            }
            else{
                h=mid-1;
            }
        }
        return h;
    }
