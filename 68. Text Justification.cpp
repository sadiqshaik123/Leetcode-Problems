class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> res;
        int i = 0, n = words.size();
        while (i < n) {
            int j = i, len = 0;
            while (j < n && len + words[j].size() + j - i <= maxWidth) {
                len += words[j++].size();
            }
            string cur;
            int space = maxWidth - len;
            for (int k = i; k < j; ++k) {
                cur += words[k];
                if (space > 0) {
                    int cnt;
                    if (j == n) { 
                        if (j - k == 1) cnt = space;
                        else cnt = 1;
                    } else {
                        if (j - k > 1) {
                            if (space % (j - k - 1) == 0) cnt = space / (j - k - 1);
                            else cnt = space / (j - k - 1) + 1;
                        } else cnt = space;
                    }
                    cur.append(cnt, ' ');
                    space -= cnt;
                }
            }
            res.push_back(cur);
            i = j;
        }
        return res;
    }
};
