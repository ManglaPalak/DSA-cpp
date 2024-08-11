bool lemonadeChange(vector<int>& bills) {
        unordered_map<int,int> cash;
        cash[5]=0;
        cash[10]=0;
        cash[15]=0;
        for(int i=0;i<bills.size();i++){
            if (bills[i]==5){
                cash[5]++;
            }
            else if (bills[i]==10){
                cash[10]++;
                if (cash[5]>0){
                    cash[5]--;
                }
                else{
                    return false;
                }
            }
            else if (bills[i]==20){
                cash[20]++;
                if (cash[5]>0 && cash[10]>0){
                    cash[5]--;
                    cash[10]--;
                }
                else if (cash[5]>=3){
                    cash[5]=cash[5]-3;
                }
                else{
                    return false;
                }
            }
        }
        return true;
    }
