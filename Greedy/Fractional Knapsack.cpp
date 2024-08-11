/*
struct Item{
    int value;
    int weight;
};
*/

class Solution {
  public:
    static bool cmp(struct Item a, struct Item b){
        double r1 = (double)a.value / (double)a.weight;
        double r2 = (double)b.value / (double)b.weight;
        return r1 > r2;
    }
    // Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int w, Item arr[], int n) {
        sort(arr, arr + n, cmp);
        double ans=0.0;
        for(int i=0;i<n;i++){
            if(arr[i].weight <= w){
                w-=arr[i].weight;
                ans+=arr[i].value;
            }
            else if (arr[i].weight > w){
                ans+=(((double)arr[i].value/(double)arr[i].weight)*w);
                w=0;
                break;
            }
        }
        return ans;
    }
};
