class Solution {
public:
    bool isScramble(string s1, string s2) {
        if (s1 == s2) return true;
        if (s1.size() != s2.size()) return false;
        int n = s1.size();
        vector<vector<vector<int>>> memo(n, vector<vector<int>>(n, vector<int>(n + 1, -1)));
        return helper(s1, s2, 0, 0, n, memo);
    }
    bool helper(string& s1, string& s2, int idx1, int idx2, int len, vector<vector<vector<int>>>& memo) {
        if (len == 0) return true;
        if (len == 1) memo[idx1][idx2][len] = s1[idx1] == s2[idx2];
        if (memo[idx1][idx2][len] != -1) return memo[idx1][idx2][len];
        for (int k = 1; k < len; ++k) {
            if ((helper(s1, s2, idx1, idx2, k, memo) && helper(s1, s2, idx1 + k, idx2 + k, len - k, memo)) || (helper(s1, s2, idx1, idx2 + len - k, k, memo) && helper(s1, s2, idx1 + k, idx2, len - k, memo))) {
                return memo[idx1][idx2][len] = 1;
            }
        }
        return memo[idx1][idx2][len] = 0;
    }
};
