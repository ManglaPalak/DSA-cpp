int dp[101][101];
    int lcs_len = 0;
    vector<string> res;

  private:
    int lcs(string s, string t, int pos1, int pos2) {
        if (pos1 == s.size() or pos2 == t.size())
            return 0;
        int &ans = dp[pos1][pos2];
        if (ans != -1)
            return ans;
        
        if (s[pos1] == t[pos2])
            return ans = 1 + lcs(s, t, pos1 + 1, pos2 + 1);
        return ans = max(lcs(s, t, pos1 + 1, pos2), lcs(s, t, pos1, pos2 + 1));
    }

  private:
    void helper(string s, string t, string cur, int pos1, int pos2, int cur_lcs) {
        if (cur_lcs == lcs_len) {
            res.push_back(cur);
            return;
        }
        if (pos1 == s.size() or pos2 == t.size())
            return;
        
        for (char ch = 'a'; ch <= 'z'; ch++) {
            bool f = false;
            for (int i = pos1; i < s.size(); i++) {
                if (s[i] == ch) {
                    for (int j = pos2; j < t.size(); j++) {
                        if (t[j] == ch and lcs(s, t, i, j) == lcs_len - cur_lcs) {
                            string new_cur = cur + ch;
                            helper(s, t, new_cur, i + 1, j + 1, cur_lcs + 1);
                            f = true;
                            break;
                        }
                    }
                }
                if (f)
                    break;
            }
        }
    }

  public:
    vector<string> all_longest_common_subsequences(string s, string t) {
        memset(dp, -1, sizeof(dp));
        lcs_len = lcs(s, t, 0, 0);
        helper(s, t, "", 0, 0, 0);
        return res;
    }
