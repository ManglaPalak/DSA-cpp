int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size();
        int l = 0, h = n - 1;

        if (k < arr[0]) 
            return k;
        if (k > arr[n - 1] - n) 
            return k + n;
        while (l < h) {
            int m = l + (h - l) / 2;
            if (arr[m] - m - 1 >= k) 
                h = m;
            else
                l = m + 1;
        }
        return l + k;
    }
