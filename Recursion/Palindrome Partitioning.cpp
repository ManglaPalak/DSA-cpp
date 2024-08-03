bool isPalindrome(string s, int left, int right) {
        while (left < right) {
            if (s[left] != s[right]) {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }

    void solve(int index, vector<string>& helper, vector<vector<string>>& ans, string s) {
        if (index >= s.size()) {
            ans.push_back(helper);
            return;
        }

        for (int i = index; i < s.size(); i++) {
            if (isPalindrome(s, index, i)) {
                helper.push_back(s.substr(index, i - index + 1));
                solve(i + 1, helper, ans, s);
                helper.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<string> helper;
        vector<vector<string>> ans;
        solve(0, helper, ans, s);
        return ans;
    }
