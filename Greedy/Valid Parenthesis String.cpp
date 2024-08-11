bool checkValidString(string s) {
        stack<int> left;
        stack<int> star;
        for(int i=0;i<s.size();i++){
            if (s[i]=='('){
                left.push(i);
            }
            else if (s[i]=='*'){
                star.push(i);
            }
            else if (s[i]==')'){
                if (!left.empty()){
                    left.pop();
                }
                else if (!star.empty()){
                    star.pop();
                }
                else{
                    return false;
                }
            }
        }
        while(!left.empty() && !star.empty()){
            if (left.top()<star.top()){
                star.pop();
                left.pop();
            }
            else{
                break;
            }
        }
        if (left.empty()){
            return true;
        }
        else{
            return false;
        }
    }
