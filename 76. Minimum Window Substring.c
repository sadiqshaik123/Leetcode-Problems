char* minWindow(char* s, char* t) {
    int letterCnt[128] = {0};
    int left = 0, cnt = 0, minLeft = -1, minLen = INT_MAX;
    
    for (int i = 0; t[i] != '\0'; ++i)
        ++letterCnt[t[i]];

    for (int i = 0; s[i] != '\0'; ++i) {
        if (--letterCnt[s[i]] >= 0) 
            ++cnt;

        while (cnt == strlen(t)) {
            if (minLen > i - left + 1) {
                minLen = i - left + 1;
                minLeft = left;
            }

            if (++letterCnt[s[left]] > 0) 
                --cnt;

            ++left;
        }
    }

    if (minLeft == -1) {
        char* result = (char*)malloc(1);
        result[0] = '\0';
        return result;
    }

    char* result = (char*)malloc(minLen + 1);
    strncpy(result, s + minLeft, minLen);
    result[minLen] = '\0';

    return result;
}
